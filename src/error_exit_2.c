/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:22 by amalgonn          #+#    #+#             */
/*   Updated: 2024/02/20 17:16:30 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit_number(t_data *map)
{
	ft_putstr_fd("Exit error\n", 1);
	clean(map);
}

void	error_coin_number(t_data *map)
{
	ft_putstr_fd("Coins error\n", 1);
	clean(map);
}

void	error_player_number(t_data *map)
{
	ft_putstr_fd("Player error\n", 1);
	clean(map);
}

void	error_arg(t_data *map)
{
	if (map->exit_count != 1)
		error_exit_number(map);
	if (map->coin_count < 1)
		error_coin_number(map);
	if (map->player_count > 1)
		error_player_number(map);
}

void	error_wall(t_data *map)
{
	ft_putstr_fd("Wall error\n", 1);
	clean(map);
}
