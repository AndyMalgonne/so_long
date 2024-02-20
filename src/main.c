/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:30:28 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/20 13:14:22 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


void	start_win(t_data *map)
{
	int		w;
	int		h ;
	size_t	i;
	size_t	j;

	j = map->height;
	i = map->width;
	w = 40;
	h = 40;
	map->win = mlx_new_window(map->mlx, i * w, j * h, "so_long");
	map->wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &w, &h);
	map->player = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm", &w, &h);
	map->coin = mlx_xpm_file_to_image(map->mlx, "./img/coin.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm", &w, &h);
	map->exit_1 = mlx_xpm_file_to_image(map->mlx, "./img/exit_1.xpm", &w, &h);
	map->exit_2 = mlx_xpm_file_to_image(map->mlx, "./img/exit_2.xpm", &w, &h);
	map->tile = mlx_xpm_file_to_image(map->mlx, "./img/tile.xpm", &w, &h);
}


void	exit_escape(t_data *map, int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		free(map->mlx);
		ft_putstr_fd("You exited\n", 1);
		exit (0);
	}
	mlx_destroy_window(map->mlx, map->win);
	ft_putstr_fd("Good Game\n", 1);
	exit (0);
}

int	exit_cross(t_data *map)
{
	mlx_destroy_window(map->mlx, map->win);
	free(map->mlx);
	ft_putstr_fd("You exited\n", 1);
	exit (0);
}

// 126 up 125 down 123 left 124 right
int	key_hook(int keycode, t_data *map)
{
	if (keycode == 53)
		exit_escape(map, keycode);
	else if (keycode == 126)
		move_p(map, 0, -1);
	else if (keycode == 125)
		move_p(map, 0, 1);
	else if (keycode == 123)
		move_p(map, -1, 0);
	else if (keycode == 124)
		move_p(map, 1, 0);
	mlx_clear_window(map->mlx, map->win);
	put_image_window(map, 0, 0);
	return (0);
}

static int	put_img(t_data *map)
{
	(void)map;
	return (0);
}

void	init_map(t_data *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->mlx = NULL;
	map->win = NULL;
	map->wall = NULL;
	map->tile = NULL;
	map->coin = NULL;
	map->exit = NULL;
	map->exit_1 = NULL;
	map->exit_2 = NULL;
	map->player = NULL;
	map->player_count = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->count = 0;
	map->coin_count = 0;
	map->exit_count = 0;
	map->coins_collected = 0;
}

int	main(int ac, char *av[])
{
	t_data	map;

	if (ac == 1 || ac > 2)
		return (ft_putstr_fd("Wrong number of arguments\n", 1), 1);
	(init_map(&map), map.mlx = mlx_init());
	if (!map.mlx)
		error_map(&map);
	check_suffix(av[1], &map);
	set_map(&map, av[1]);
	check_arg(&map);
	check_wall(&map);
	start_win(&map);
	init_p(&map);
	if (!flood_map(&map))
		(ft_putstr_fd("Map is invalid\n", 1), exit(1));
	put_image_window(&map, 0, 0);
	mlx_loop_hook(map.mlx, &put_img, &map);
	mlx_hook(map.win, 2, 0, key_hook, &map);
	mlx_hook(map.win, 17, 0, exit_cross, &map);
	mlx_loop(map.mlx);
}

