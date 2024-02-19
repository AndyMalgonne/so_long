/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:21:20 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/19 12:59:01 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_suffix(char *map_file)
{
	int	len;
	int	fd;

	len = ft_strlen(map_file);
	if (len < 4 || ft_strncmp(map_file + (len - 4), ".ber", len) != 0)
		error_ext();
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_fd();
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
		if (map->width != (size_t)ft_strlen(trimmed_line))
			error_map();
		map->height++;
		(free(trimmed_line), free(line), line = get_next_line(fd));
		if (line)
			join = ft_strjoin(join, line);
	}
	(free(line), close(fd), map->map = ft_split(join, '\n'));
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

	i = 0;
	map->coin_count = 0;
	map->exit_count = 0;
	map->coins_collected = 0;
	map->player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				map->coin_count++;
			else if (map->map[i][j] == 'E')
				map->exit_count++;
			else if (map->map[i][j] == 'P')
				map->player_count++;
			j++;
		}
		i++;
	}
	error_arg(map);
}


void	free_map(t_data *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	return ;
}
