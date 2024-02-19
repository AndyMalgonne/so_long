/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:38:50 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/19 11:29:33 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *map, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->player, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->coin, x, y);
	else if (c == 'E')
	{
		if (map->coins_collected == 0)
			mlx_put_image_to_window(map->mlx, map->win, map->exit_2, x, y);
		else if (map->coins_collected > 0 && map->coins_collected < map->coin_count)
			mlx_put_image_to_window(map->mlx, map->win, map->exit_1, x, y);
		else if (map->coins_collected == map->coin_count)
			mlx_put_image_to_window(map->mlx, map->win, map->exit, x, y);
	}
	else if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->tile, x, y);
}

int	put_image_window(t_data *map, int x, int y)
{
	size_t	i;
	size_t	j;
	int		start_x;
	int		start_y;

	start_x = x;
	start_y = y;
	i = 0;
	j = 0;

	while (i < map->height)
	{
		while (map->map[i][j])
		{
			put_image(map, map->map[i][j], start_x, start_y);
			j++;
			start_x += 40;
		}
		j = 0;
		start_x = x;
		i++;
		start_y += 40;
	}
	return (0);
}
