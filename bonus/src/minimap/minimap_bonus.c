/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:47:40 by hesainte          #+#    #+#             */
/*   Updated: 2026/07/09 18:59:25 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "graphics_bonus.h"

#define MINIMAP_SCALE 8
#define MINIMAP_MARGIN 10

static void	draw_minimap_cell(t_game *game, int x, int y, int origin_x)
{
	t_square_args	args;

	args.x = origin_x + x * MINIMAP_SCALE;
	args.y = MINIMAP_MARGIN + y * MINIMAP_SCALE;
	args.size = MINIMAP_SCALE;
	args.color = 0;
	if (game->map.map_rows[y][x] == '1')
		args.color = 0x123345;
	else if (game->map.map_rows[y][x] == '0'
		|| game->map.map_rows[y][x] == 'N'
		|| game->map.map_rows[y][x] == 'E'
		|| game->map.map_rows[y][x] == 'S'
		|| game->map.map_rows[y][x] == 'W')
		args.color = 0x546321;
	if (args.color)
		draw_scaled_square(game, args);
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	origin_x;

	origin_x = game->win_w - game->map.width * MINIMAP_SCALE
		- MINIMAP_MARGIN;
	y = 0;
	while (game->map.map_rows[y])
	{
		x = 0;
		while (game->map.map_rows[y][x])
		{
			draw_minimap_cell(game, x, y, origin_x);
			x++;
		}
		y++;
	}
	draw_minimap_player(game, origin_x, MINIMAP_MARGIN, MINIMAP_SCALE);
}

void	draw_minimap_player(t_game *game, int origin_x, int origin_y, int scale)
{
	int	px;
	int	py;
	int	dx;
	int	dy;

	px = origin_x + (int)(game->player.player_x * scale);
	py = origin_y + (int)(game->player.player_y * scale);
	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			put_pixel(game, px + dx, py + dy, 0x00FF00);
			dy++;
		}
		dx++;
	}
	put_pixel(game, px + (int)(game->player.dir_x * scale * 2),
		py + (int)(game->player.dir_y * scale * 2), 0xFF0000);
}
