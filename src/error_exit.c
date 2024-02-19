/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:23:31 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/19 08:24:41 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(void)
{
	ft_putstr_fd("Error map\n", 1);
	exit(1);
}

void	error_ext(void)
{
	ft_putstr_fd("Error extension\n", 1);
	exit(1);
}

void	error_fd(void)
{
	ft_putstr_fd("Error loading map\n", 1);
	exit(1);
}

void	error_exit_number(void)
{
	ft_putstr_fd("Too many exit\n", 1);
	exit(1);
}

void	error_coin_number(void)
{
	ft_putstr_fd("Not enough coins\n", 1);
	exit(1);
}

void	error_player_number(void)
{
	ft_putstr_fd("Too many players\n", 1);
	exit(1);
}

void	error_arg(t_data * map)
{
	if (map->exit_count != 1)
		error_exit_number();
	if (map->coin_count < 1)
		error_coin_number();
	if (map->player_count > 1)
		error_player_number();
}
