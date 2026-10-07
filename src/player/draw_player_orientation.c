/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_orientation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:12:48 by heidi             #+#    #+#             */
/*   Updated: 2026/07/09 02:45:49 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"
#include "graphics.h"

static void	helper_draw_line(t_line *line, t_draw_line_args *args)
{
	line->dx = abs(args->x1 - args->x0);
	line->dy = -abs(args->y1 - args->y0);
	if (args->x0 < args->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (args->y0 < args->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx + line->dy;
}

static void	draw_line(t_game *game, t_draw_line_args args)
{
	t_line	line;
	int		e2;

	helper_draw_line(&line, &args);
	while (1)
	{
		put_pixel(game, args.x0, args.y0, args.color);
		if (args.x0 == args.x1 && args.y0 == args.y1)
			break ;
		e2 = 2 * line.err;
		if (e2 >= line.dy)
		{
			line.err += line.dy;
			args.x0 += line.sx;
		}
		if (e2 <= line.dx)
		{
			line.err += line.dx;
			args.y0 += line.sy;
		}
	}
}

static void	compute_player_view_vectors(t_game *game, t_player_view *view)
{
	float	dx;
	float	dy;
	float	spread;

	dx = game->player.dir_x;
	dy = game->player.dir_y;
	spread = 0.7f;
	view->lx = dx * cos(spread) - dy * sin(spread);
	view->ly = dx * sin(spread) + dy * cos(spread);
	view->rx = dx * cos(-spread) - dy * sin(-spread);
	view->ry = dx * sin(-spread) + dy * cos(-spread);
}

static void	draw_player_rays(t_game *game, t_player_view *view)
{
	float				i;
	float				vx;
	float				vy;
	t_draw_line_args	args;

	i = 0.0f;
	while (i < 1.0f)
	{
		vx = view->lx + (view->rx - view->lx) * i;
		vy = view->ly + (view->ry - view->ly) * i;
		{
			args.x0 = view->px;
			args.y0 = view->py;
			args.x1 = view->px + vx * view->len;
			args.y1 = view->py + vy * view->len;
			args.color = 0xFF0000;
			draw_line(game, args);
		}
		i += 0.05f;
	}
}

void	draw_player_view(t_game *game, int px, int py)
{
	t_player_view	view;

	view.px = px;
	view.py = py;
	view.len = 60;
	compute_player_view_vectors(game, &view);
	draw_player_rays(game, &view);
}
