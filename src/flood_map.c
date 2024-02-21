/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:59 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/20 17:58:52 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_fmap(t_fmap *fmap, t_data *map)
{
	size_t	i;

	i = -1;
	fmap->coin_count = 0;
	fmap->exit_count = 0;
	fmap->map = ft_calloc(map->height + 1, sizeof(char *));
	if (!fmap->map)
		return (0);
	while (++i < map->height)
	{
		fmap->map[i] = ft_strdup(map->map[i]);
		if (!(fmap->map[i]))
			return (free_split(fmap->map), 0);
	}
	return (1);
}

static void	flood(t_data *map, t_fmap *fmap, size_t x, size_t y)
{
	if (fmap->map[y][x] == '1')
		return ;
	else if (map->map[y][x] == 'E')
	{
		++(fmap->exit_count);
		(fmap->map[y][x] = '1');
		return ;
	}
	else if (map->map[y][x] == 'C')
		++(fmap->coin_count);
	fmap->map[y][x] = '1';
	if (y - 1 > 0 && fmap->map[y - 1][x] != '1')
		flood(map, fmap, x, y - 1);
	if (y + 1 < map->height && fmap->map[y + 1][x] != '1')
		flood(map, fmap, x, y + 1);
	if (x - 1 > 0 && fmap->map[y][x - 1] != '1')
		flood(map, fmap, x - 1, y);
	if (x + 1 < map->width && fmap->map[y][x + 1] != '1')
		flood(map, fmap, x + 1, y);
}

int	flood_map(t_data *map)
{
	t_fmap	fmap;

	if (!set_fmap(&fmap, map))
		return (0);
	flood(map, &fmap, map->player_x, map->player_y);
	free_split(fmap.map);
	if (fmap.coin_count != map->coin_count
		|| fmap.exit_count != map->exit_count)
		return (0);
	return (1);
}
