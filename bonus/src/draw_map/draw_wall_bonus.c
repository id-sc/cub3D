/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 02:08:12 by hesainte          #+#    #+#             */
/*   Updated: 2026/07/09 02:43:31 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "graphics_bonus.h"

static void	helper_draw_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex = &game->west;
	else if (ray->side == 0)
		ray->tex = &game->east;
	else if (ray->ray_dir_y > 0)
		ray->tex = &game->north;
	else
		ray->tex = &game->south;
	if (ray->side == 0)
		ray->wall_x = game->player.player_y
			+ ray->perp_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.player_x
			+ ray->perp_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * 64);
	ray->step = 64.0 / ray->line_height;
	ray->tex_pos = (ray->draw_start - game->win_h / 2
			+ ray->line_height / 2) * ray->step;
}

void	draw_wall_column(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	color;

	helper_draw_wall(game, ray);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & 63;
		ray->tex_pos += ray->step;
		color = get_tex_color(ray->tex, ray->tex_x, ray->tex_y);
		put_pixel(game, x, y, color);
		y++;
	}
}
