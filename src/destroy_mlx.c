/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:59:10 by amalgonn          #+#    #+#             */
/*   Updated: 2024/02/20 17:15:34 by amalgonn         ###   ########.fr       */
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
	if (data->mlx)
		(mlx_destroy_display(data->mlx), free(data->mlx));
}

void	clean(t_data *data)
{
	if (!data)
		exit(1);
	if (data->map)
		free_split(data->map);
	(destroy_mlx(data), exit(1));
}
