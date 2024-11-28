/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:22 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 15:01:40 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

int	parse_color_line(const char *line, int color[3])
{
	int	color_index;

	color_index = 0;
	while (color_index < 3)
	{
		color[color_index] = ft_atoi_long(line);
		if (color[color_index] < 0 || color[color_index] > 255)
			return (0);
		while (*line >= '0' && *line <= '9')
			line++;
		if (color_index < 2)
		{
			if (*line != ',')
				return (0);
			line++;
		}
		color_index++;
	}
	return (1);
}
