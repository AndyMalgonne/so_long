/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:56:41 by andymalgonn       #+#    #+#             */
/*   Updated: 2024/02/20 17:45:57 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>

typedef struct s_data
{
	char	**map;
	size_t	width;
	size_t	height;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*tile;
	void	*coin;
	void	*exit;
	void	*exit_1;
	void	*exit_2;
	void	*player;
	int		player_count;
	int		player_x;
	int		player_y;
	int		count;
	int		coin_count;
	int		exit_count;
	int		coins_collected;
}	t_data;

typedef struct s_fmap
{
	char	**map;
	int		coin_count;
	int		exit_count;
}	t_fmap;

void	set_map(t_data *map, char *file);
void	check_suffix(char *map_file, t_data *map);
int		key_hook(int keycode, t_data *vars);
int		put_image_window(t_data *map, int x, int y);

// Events
int		key_hook(int keysym, t_data *map);
int		exit_cross(t_data *map);
void	exit_escape(t_data *map, int keysym);

// Flood
int		flood_map(t_data *map);

//Check
void	check_wall(t_data *map);
void	check_arg(t_data *map);

// Player
void	init_p(t_data *map);
void	move_p(t_data *map, int dx, int dy);
// Errors
void	error_ext(t_data *map);
void	error_map(t_data *map);
void	error_fd(t_data *map);
void	error_exit_number(t_data *map);
void	error_coin_number(t_data *map);
void	error_player_number(t_data *map);
void	error_arg(t_data *map);
void	clean(t_data *data);
void	error_wall(t_data *map);
void	error_map_too_big(t_data *map);
void	flood_error(t_data *map);

#endif