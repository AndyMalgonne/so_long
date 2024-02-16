/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:30:28 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/16 16:04:02 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


void	start_win(t_data *map)
{
	int	w;
	int	h ;

	w = 40;
	h = 40;
	map->win = mlx_new_window(map->mlx, 1080, 900, "so_long");
	map->wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &w, &h);
	map->player = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm", &w, &h);
	map->coin = mlx_xpm_file_to_image(map->mlx, "./img/coin.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./img/exit_2.xpm", &w, &h);
	map->tile = mlx_xpm_file_to_image(map->mlx, "./img/tile.xpm", &w, &h);
}


void	exit_1(t_data *map, int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		ft_putstr_fd("You exited\n", 1);
		exit (0);
	}
	mlx_destroy_window(map->mlx, map->win);
	ft_putstr_fd("Good Game\n", 1);
	exit (0);
}

int key_hook(int keycode, t_data *map)
{
	if (keycode == 53)
		exit_1(map, keycode);
	//Up button
	else if (keycode == 126)
		move_p(map, 0, -1);
	// Down button
	else if (keycode == 125)
		move_p(map, 0, 1);
	// Left button
	else if (keycode == 123)
		move_p(map, -1, 0);
	// Right button
	else if (keycode == 124)
		move_p(map, 1, 0);
	mlx_clear_window(map->mlx, map->win);
	put_image_window(map, 350, 350);
	return (0);
}

static int	put_img(t_data *map)
{
	(void)map;
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	map;

	if (ac == 1 || ac > 2)
	{
		ft_putstr_fd("Wrong number of arguments", 1);
		return (1);
	}

	map.mlx = mlx_init();
	check_suffix(av[1]);
	set_map(&map, av[1]);
	check_arg(&map);
	check_wall(&map);
	start_win(&map);
	init_p(&map);
	put_image_window(&map, 350, 350);
	mlx_loop_hook(map.mlx, &put_img, &map);
	mlx_hook(map.win, 2, 0, key_hook, &map);
	mlx_loop(map.mlx);
}

