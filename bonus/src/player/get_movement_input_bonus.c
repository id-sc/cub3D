/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_movement_input_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:50:06 by heidi             #+#    #+#             */
/*   Updated: 2026/07/09 02:38:35 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "player_bonus.h"

int	key_press(int key, t_game *game)
{
	if (key == W_KEY)
		game->key_w = 1;
	if (key == S_KEY)
		game->key_s = 1;
	if (key == A_KEY)
		game->key_a = 1;
	if (key == D_KEY)
		game->key_d = 1;
	if (key == L_ARROW)
		game->key_left = 1;
	if (key == R_ARROW)
		game->key_right = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == ESC)
		close_win(game);
	if (key == W_KEY)
		game->key_w = 0;
	if (key == S_KEY)
		game->key_s = 0;
	if (key == A_KEY)
		game->key_a = 0;
	if (key == D_KEY)
		game->key_d = 0;
	if (key == L_ARROW)
		game->key_left = 0;
	if (key == R_ARROW)
		game->key_right = 0;
	return (0);
}
