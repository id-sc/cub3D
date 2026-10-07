/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_minimap_player_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 01:01:42 by hesainte          #+#    #+#             */
/*   Updated: 2026/07/09 19:03:54 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "player_bonus.h"

static void	update_mini_player_key_a(t_game *game)
{
	float	nx;
	float	ny;

	nx = game->player.player_x + game->player.dir_y * SPEED;
	ny = game->player.player_y - game->player.dir_x * SPEED;
	if (!is_wall(game, nx, game->player.player_y))
		game->player.player_x = nx;
	if (!is_wall(game, game->player.player_x, ny))
		game->player.player_y = ny;
}

static void	update_mini_player_key_d(t_game *game)
{
	float	nx;
	float	ny;

	nx = game->player.player_x - game->player.dir_y * SPEED;
	ny = game->player.player_y + game->player.dir_x * SPEED;
	if (!is_wall(game, nx, game->player.player_y))
		game->player.player_x = nx;
	if (!is_wall(game, game->player.player_x, ny))
		game->player.player_y = ny;
}

void	update_minimap_player(t_game *game)
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
		update_mini_player_key_a(game);
	if (game->key_d)
		update_mini_player_key_d(game);
}
