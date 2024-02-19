/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:59 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/19 14:43:31 by andymalgonn      ###   ########.fr       */
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
			return (0);
	}
	return (1);
}

static void	flood(t_data *map, t_fmap *fmap, size_t x, size_t y)
{
	if (fmap->map[y][x] == '1')
		return ;
	else if (map->map[y][x] == 'E')
		++(fmap->exit_count);
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
	for (size_t i = 0; fmap.map[i]; i++)
	{
		printf("%s\n", fmap.map[i]);
	}
	flood(map, &fmap, map->player_x, map->player_y);
	putchar('\n');
	for (size_t i = 0; fmap.map[i]; i++)
	{
		printf("%s\n", fmap.map[i]);
	}
	if (fmap.coin_count != map->coin_count
		|| fmap.exit_count != map->exit_count)
		return (0);
	printf("coin_count: %d\n", map->coin_count);
	printf("flood_coin_count: %d\n", fmap.coin_count);
	printf("exit_count: %d\n", map->exit_count);
	printf("flood_exit_count: %d\n", fmap.exit_count);
	return (1);
}
