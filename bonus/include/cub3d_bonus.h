/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:24:50 by vildan            #+#    #+#             */
/*   Updated: 2026/07/09 02:37:00 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_color
{
	int									r;
	int									g;
	int									b;
	int									hex;
	bool								is_set;
}										t_color;

typedef struct s_config
{
	char								*north;
	char								*south;
	char								*west;
	char								*east;
	t_color								floor;
	t_color								ceiling;
}										t_config;

typedef struct s_player
{
	double								player_x;
	double								player_y;

	double								dir_x;
	double								dir_y;
	float								plane_x;
	float								plane_y;

	char								start_dir;
	bool								is_set;
}										t_player;

typedef struct s_map
{
	char								**map_rows;
	int									width;
	int									height;
}										t_map;

typedef struct s_parser
{
	char								*file_path;
	char								**lines;
	t_config							config;
	t_map								map;
	t_player							player;
}										t_parser;

typedef struct s_img
{
	void								*img;
	char								*addr;
	int									bits_per_pixel;
	int									line_length;
	int									endian;
}										t_img;

typedef struct s_game
{
	void								*mlx;
	void								*window;
	int									win_h;
	int									win_w;
	int									key_w;
	int									key_s;
	int									key_a;
	int									key_d;
	int									key_left;
	int									key_right;
	t_img								north;
	t_img								south;
	t_img								east;
	t_img								west;
	t_img								image;
	t_map								map;
	t_config							config;
	t_player							player;
	t_parser							parser;

}										t_game;

void		init_game(t_game *game);
int			close_win(t_game *game);

#endif
