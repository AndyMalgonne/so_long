/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:48:31 by amalgonn          #+#    #+#             */
/*   Updated: 2024/02/20 18:11:33 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keysym, t_data *map)
{
	if (keysym == XK_Escape)
		exit_escape(map, keysym);
	else if (keysym == XK_Up || keysym == XK_w)
		move_p(map, 0, -1);
	else if (keysym == XK_Down || keysym == XK_s)
		move_p(map, 0, 1);
	else if (keysym == XK_Left || keysym == XK_a)
		move_p(map, -1, 0);
	else if (keysym == XK_Right || keysym == XK_d)
		move_p(map, 1, 0);
	mlx_clear_window(map->mlx, map->win);
	put_image_window(map, 0, 0);
	return (0);
}

int	exit_cross(t_data *map)
{
	ft_putstr_fd("You exited\n", 1);
	clean(map);
	return (0);
}

void	exit_escape(t_data *map, int keysym)
{
	if (keysym == XK_Escape)
	{
		ft_putstr_fd("You exited\n", 1);
		clean(map);
	}
	ft_putstr_fd("Good Game\n", 1);
	clean(map);
}
