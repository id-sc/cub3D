/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:24:56 by vildan            #+#    #+#             */
/*   Updated: 2026/07/09 18:44:09 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_bonus.h"
#include "parser_bonus.h"

static int	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	return (1);
}

static int	has_cub_extension(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (i < 5)
		return (0);
	return (file_name[i - 4] == '.' && file_name[i - 3] == 'c' && file_name[i
			- 2] == 'u' && file_name[i - 1] == 'b');
}

static int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Usage: ./cub3D <map.cub>"));
	if (!argv[1] || !argv[1][0])
		return (print_error("Invalid map file"));
	if (!has_cub_extension(argv[1]))
		return (print_error("Map file must have .cub extension"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_parser	parser;
	t_game		game;

	ft_bzero(&parser, sizeof(t_parser));
	ft_bzero(&game, sizeof(t_game));
	if (check_args(argc, argv))
		return (1);
	if (read_cub_file(&parser, argv[1]))
	{
		free_parser(&parser);
		return (1);
	}
	if (parse_config(&parser))
	{
		free_parser(&parser);
		return (1);
	}
	init_game_from_parser(&game, &parser);
	return (start_graphics(&game));
}
