/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:24:42 by vildan            #+#    #+#             */
/*   Updated: 2026/07/03 21:53:36 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "cub3d.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		read_cub_file(t_parser *parser, char *file_path);
int		parse_config(t_parser *parser);
int		parse_map(t_parser *parser);
int		find_player(t_parser *parser);
int		validate_map_closed(t_parser *parser);
int		is_map_line(char *line);
int		is_valid_rgb_value(char *value);
void	free_str_array(char **str_array);
void	free_parser(t_parser *parser);

#endif
