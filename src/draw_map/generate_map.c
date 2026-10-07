/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:40:02 by heidi             #+#    #+#             */
/*   Updated: 2026/07/09 19:06:12 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/player.h"
#include "../include/graphics.h"
#include <stdio.h>

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_h)
	{
		x = 0;
		while (x < game->win_w)
		{
			put_pixel(game, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	draw_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_h)
	{
		x = 0;
		while (x < game->win_w)
		{
			if (y < game->win_h / 2)
				put_pixel(game, x, y, game->config.ceiling.hex);
			else
				put_pixel(game, x, y, game->config.floor.hex);
			x++;
		}
		y++;
	}
	return (1);
}

void	raycast(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < game->win_w)
	{
		init_ray(game, &ray, x);
		init_step(game, &ray);
		perform_dda(game, &ray);
		calculate_wall(game, &ray);
		draw_wall_column(game, &ray, x);
		x++;
	}
}

int	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_player(game);
	clear_image(game);
	draw_floor_and_ceiling(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image.img, 0, 0);
	return (0);
}
