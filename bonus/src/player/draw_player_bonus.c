/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:19:10 by heidi             #+#    #+#             */
/*   Updated: 2026/07/09 19:04:18 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "graphics_bonus.h"

static void	draw_player_center(t_game *game, int px, int py)
{
	int	dx;
	int	dy;

	dx = -2;
	while (dx <= 2)
	{
		dy = -2;
		while (dy <= 2)
		{
			put_pixel(game, px + dx, py + dy, 0x00FF00);
			dy++;
		}
		dx++;
	}
}

void	draw_player(t_game *game)
{
	int	px;
	int	py;

	px = (int)(game->player.player_x * 64);
	py = (int)(game->player.player_y * 64);
	draw_player_view(game, px, py);
	draw_player_center(game, px, py);
}

void	update_player(t_game *game)
{
	if (game->key_left)
		rotate_player(&game->player, -ROTATE_SPEED);
	if (game->key_right)
		rotate_player(&game->player, ROTATE_SPEED);
	if (game->key_w)
		update_player_key_w(game);
	if (game->key_s)
		update_player_key_s(game);
	if (game->key_a)
		update_player_key_a(game);
	if (game->key_d)
		update_player_key_d(game);
}

int	is_wall(t_game *game, float x, float y)
{
	int	row;
	int	col;

	if (!game || !game->map.map_rows || !isfinite(x) || !isfinite(y)
		|| x < 0 || y < 0)
		return (1);
	row = (int)y;
	col = (int)x;
	if (row >= game->map.height || !game->map.map_rows[row]
		|| col >= (int)ft_strlen(game->map.map_rows[row]))
		return (1);
	return (!(game->map.map_rows[row][col] == '0'
		|| game->map.map_rows[row][col] == 'N'
		|| game->map.map_rows[row][col] == 'S'
		|| game->map.map_rows[row][col] == 'E'
		|| game->map.map_rows[row][col] == 'W'));
}
