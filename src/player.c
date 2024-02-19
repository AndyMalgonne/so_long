/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:55:00 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/16 17:35:36 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_p(t_data *map)
{
	size_t	i;
	size_t	j;

	map->count = 1;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	exit_w(t_data *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_putstr_fd("MOVES: ", 1);
	ft_putnbr_fd(map->count++, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Good Game\n", 1);
	exit (0);
}

static void	z_to_p(t_data *map, size_t new_y, size_t new_x)
{
	map->map[map->player_y][map->player_x] = '0';
	map->map[new_y][new_x] = 'P';
	map->player_x = new_x;
	map->player_y = new_y;
	ft_putstr_fd("MOVES: ", 1);
	ft_putnbr_fd(map->count++, 1);
	ft_putstr_fd("\n", 1);
}

void	move_p(t_data *map, int dx, int dy)
{
	size_t	new_x;
	size_t	new_y;

	new_x = map->player_x + dx;
	new_y = map->player_y + dy;
	if (new_x >= 0 && new_x < map->width && new_y >= 0 && new_y < map->height)
	{
		if (map->map[new_y][new_x] == 'E')
		{
			if (map->coins_collected == map->coin_count)
				exit_w(map);
			else
				ft_putstr_fd("You need to collect all the coins first\n", 1);
		}
		else if (map->map[new_y][new_x] == '1')
			ft_putstr_fd("You can't go there\n", 1);
		else if (map->map[new_y][new_x] == 'C')
		{
			map->coins_collected++;
			z_to_p(map, new_y, new_x);
		}
		else
			z_to_p(map, new_y, new_x);
	}
}


