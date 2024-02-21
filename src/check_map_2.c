/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:13:07 by amalgonn          #+#    #+#             */
/*   Updated: 2024/02/20 17:13:43 by amalgonn         ###   ########.fr       */
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
			error_wall(map);
		j++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			error_wall(map);
		i++;
	}
}
