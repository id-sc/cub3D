/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:51:00 by vildan            #+#    #+#             */
/*   Updated: 2026/07/10 18:06:25 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../lib/mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "cub3d.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define ESC 65307

# define R_ARROW 65363
# define L_ARROW 65361

# define SPEED 0.08
# define ROTATE_SPEED 0.05

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}			t_line;

typedef struct s_player_view
{
	int		px;
	int		py;
	int		len;
	float	lx;
	float	ly;
	float	rx;
	float	ry;
}			t_player_view;

typedef struct s_draw_line_args
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		color;
}			t_draw_line_args;

// init_player.c
void	init_player(t_game *game);
void	init_player_direction(t_player *player);

// draw_player.c
int		is_wall(t_game *game, float x, float y);
void	draw_player(t_game *game);
void	update_player(t_game *game);

// draw_player_orientation.c
void	draw_player_view(t_game *game, int px, int py);

// player_movements
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);

// move_player.c
void	rotate_player(t_player *p, float angle);
void	update_player_key_w(t_game *game);
void	update_player_key_s(t_game *game);
void	update_player_key_a(t_game *game);
void	update_player_key_d(t_game *game);

//minimap.c (bonus)
void	draw_minimap_player(t_game *game, int origin_x, int origin_y,
			int scale);

//move_minimap_player.c (bonus)
void	update_minimap_player(t_game *game);

#endif
