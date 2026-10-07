/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:47:44 by heidi             #+#    #+#             */
/*   Updated: 2026/07/09 18:59:25 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "graphics.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->win_w)
		return ;
	if (y < 0 || y >= game->win_h)
		return ;
	dst = game->image.addr + (y * game->image.line_length) + (x
			* (game->image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_scaled_square(t_game *game, t_square_args args)
{
	int	i;
	int	j;

	i = 0;
	while (i < args.size)
	{
		j = 0;
		while (j < args.size)
		{
			put_pixel(game, args.x + i, args.y + j, args.color);
			j++;
		}
		i++;
	}
}

int	get_tex_color(t_img *tex, int x, int y)
{
	char	*pixel;

	if (!tex || !tex->addr)
		return (0x000000);
	if (x < 0 || x >= 64 || y < 0 || y >= 64)
		return (0x000000);
	pixel = tex->addr + (y * tex->line_length + x * 4);
	return (*(int *)pixel);
}
