/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:50:53 by vildan            #+#    #+#             */
/*   Updated: 2026/07/10 14:50:54 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_BONUS_H
# define GRAPHICS_BONUS_H

# include "cub3d_bonus.h"
# include "../../lib/mlx_linux/mlx.h"
# include <math.h>

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double	delta_dist_x;
	double	delta_dist_y;

	double	side_dist_x;
	double	side_dist_y;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;

	double	perp_dist;

	int		line_height;
	int		draw_start;
	int		draw_end;

	double	wall_x;
	int		tex_x;
	int		tex_y;

	double	step;
	double	tex_pos;

	t_img	*tex;
}	t_ray;

typedef struct s_square_args
{
	int	x;
	int	y;
	int	color;
	int	size;
}		t_square_args;

int		start_graphics(t_game *game);
int		render_frame(void *param);
void	init_game_from_parser(t_game *game, t_parser *parser);
int		load_images(t_game *game);
void	free_game(t_game *game);

// bonus/minimap/minimap.c
void	draw_minimap(t_game *game);

// draw_map/draw_utils.c
int		get_tex_color(t_img *tex, int x, int y);

//draw_map/raycasting.c
void	init_ray(t_game *game, t_ray *ray, int x);
void	init_step(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calculate_wall(t_game *game, t_ray *ray);
void	draw_wall_column(t_game *game, t_ray *ray, int x);

// draw_map/draw_utils.c
void	put_pixel(t_game *game, int x, int y, int color);
void	draw_scaled_square(t_game *game, t_square_args args);

#endif
