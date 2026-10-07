/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:25:11 by vildan            #+#    #+#             */
/*   Updated: 2026/07/03 21:53:26 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	is_map_line(char *line)
{
	while (*line == ' ')
		line++;
	if (!*line)
		return (0);
	while (*line)
	{
		if (!ft_strchr(" 01NSEW", *line))
			return (0);
		line++;
	}
	return (1);
}

int	is_valid_rgb_value(char *value)
{
	int	i;

	i = 0;
	while (value[i] == ' ')
		i++;
	if (!ft_isdigit(value[i]))
		return (0);
	while (ft_isdigit(value[i]))
		i++;
	while (value[i] == ' ')
		i++;
	return (value[i] == '\0');
}
