/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:21:20 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/21 08:26:53 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_fstrjoin(char *s1, char *s2, int n)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	if (n == 1)
		free(s1);
	else if (n == 2)
		free(s2);
	else if (n == 0)
		(free(s1), free(s2));
	return (join);
}

void	handle_errors(t_data *map, char *trimmed_line, char *join, char *line)
{
	if (!trimmed_line || map->width != (size_t)ft_strlen(trimmed_line))
	{
		free(trimmed_line);
		free(join);
		free(line);
		error_map(map);
	}
}

void	size_map_too_big(t_data *map)
{
	if (map->width * 40 > 1440 || map->height * 40 > 900)
		error_map_too_big(map);
}

void	set_map(t_data *map, char *file)
{
	int		fd;
	char	*line;
	char	*join;
	char	*trimmed_line;

	map->height = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		(close(fd), clean(map));
	map->width = ft_strlen(line) - 1;
	join = ft_strdup(line);
	while (line)
	{
		trimmed_line = ft_strtrim(line, "\n");
		handle_errors(map, trimmed_line, join, line);
		map->height++;
		(free(trimmed_line), free(line), line = get_next_line(fd));
		if (line)
		{
			join = ft_fstrjoin(join, line, 1);
			if (!join)
				(free(join), free(line), error_map(map));
		}
	}
	(free(line), close(fd), map->map = ft_split(join, '\n'), free(join));
	size_map_too_big(map);
}

void	check_arg(t_data *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	map->coin_count = 0;
	map->exit_count = 0;
	map->coins_collected = 0;
	map->player_count = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'C')
				map->coin_count++;
			else if (map->map[i][j] == 'E')
				map->exit_count++;
			else if (map->map[i][j] == 'P')
				map->player_count++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				(ft_putstr_fd("Invalid character\n", 1), exit(1));
		}
	}
	error_arg(map);
}
