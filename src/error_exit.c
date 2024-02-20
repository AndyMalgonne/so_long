/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:23:31 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/20 13:13:55 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	destroy_mlx(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->exit_1)
		mlx_destroy_image(data->mlx, data->exit_1);
	if (data->exit_2)
		mlx_destroy_image(data->mlx, data->exit_2);
	if (data->tile)
		mlx_destroy_image(data->mlx, data->tile);
	// if (data->mlx)
	// 	(mlx_destroy_display(data->mlx), free(data->mlx));
}
void	clean(t_data *data)
{
	if (!data)
		exit(1);
	if (data->map)
		free_split(data->map);
	(destroy_mlx(data), exit(1));
}
void	error_map(t_data *map)
{
	ft_putstr_fd("Error map\n", 1);
	clean(map);
}

void	error_ext(t_data *map)
{
	ft_putstr_fd("Error extension\n", 1);
	clean(map);
}

void	error_fd(t_data *map)
{
	ft_putstr_fd("Error loading map\n", 1);
	clean(map);
}

void	error_exit_number(t_data *map)
{
	ft_putstr_fd("Exit error\n", 1);
	clean(map);
}

void	error_coin_number(t_data *map)
{
	ft_putstr_fd("Not enough coins\n", 1);
	clean(map);
}

void	error_player_number(t_data *map)
{
	ft_putstr_fd("Too many players\n", 1);
	clean(map);
}

void	error_arg(t_data * map)
{
	if (map->exit_count != 1)
		error_exit_number(map);
	if (map->coin_count < 1)
		error_coin_number(map);
	if (map->player_count > 1)
		error_player_number(map);
}

