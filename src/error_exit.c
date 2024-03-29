/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:23:31 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/20 17:44:07 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	error_map_too_big(t_data *map)
{
	ft_putstr_fd("Error map too big\n", 1);
	clean(map);
}

void	flood_error(t_data *map)
{
	ft_putstr_fd("Map is invalid\n", 1);
	clean(map);
}
