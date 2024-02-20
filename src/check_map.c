/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:21:20 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/20 13:10:14 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_suffix(char *map_file, t_data *map)
{
	int	len;
	int	fd;

	len = ft_strlen(map_file);
	if (len < 4 || ft_strncmp(map_file + (len - 4), ".ber", len) != 0)
		error_ext(map);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_fd(map);
	close(fd);
}


void	check_wall(t_data *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < map->width)
	{
		if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
		{
			ft_putstr_fd("Not a Wall\n", 1);
			exit(1);
		}
		j++;
	}

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
		{
			ft_putstr_fd("Not a Wall'\n", 1);
			exit(1);
		}
		i++;
	}
}

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

void	set_map(t_data *map, char *file)
{
	int		fd;
	char	*line;
	char	*join;
	char	*trimmed_line;

	map->height = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	join = ft_strdup(line);
	while (line)
	{
		trimmed_line = ft_strtrim(line, "\n");
		if (!trimmed_line)
			error_map(map);
		if (map->width != (size_t)ft_strlen(trimmed_line))
			error_map(map);
		map->height++;
		(free(trimmed_line), free(line), line = get_next_line(fd));
		if (line)
		{
			join = ft_fstrjoin(join, line, 1);
			if (!&ft_fstrjoin)
				return (error_map(map));
		}

	}
	(free(line), close(fd), map->map = ft_split(join, '\n'));
	(free(join));
	if (map->width * 40 > 1440 || map->height * 40 > 900)
	{
		ft_putstr_fd("Map too big\n", 1);
		exit(1);
	}
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
