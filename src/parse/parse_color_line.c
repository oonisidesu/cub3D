/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:22 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/18 14:30:02 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

static bool	parse_color_value(const char **line, int *color_value)
{
	const char	*start;
	int			digit_count;

	start = *line;
	digit_count = 0;
	while (ft_isdigit(**line))
	{
		digit_count++;
		if (digit_count > 3)
			return (false);
		(*line)++;
	}
	while (ft_isdigit(**line))
		(*line)++;
	if (start == *line)
		return (false);
	*color_value = ft_atoi_long(start);
	if (*color_value < 0 || *color_value > 255)
		return (false);
	return (true);
}

static bool	parse_comma(const char **line, int color_index)
{
	if (color_index < 2)
	{
		if (**line != ',')
			return (false);
		(*line)++;
	}
	return (true);
}

bool	parse_color_line(const char *line, int color[3])
{
	int	color_index;

	color_index = 0;
	while (color_index < 3)
	{
		if (!parse_color_value(&line, &color[color_index]))
			return (false);
		if (!parse_comma(&line, color_index))
			return (false);
		color_index++;
	}
	while (*line == ' ')
		line++;
	return (*line == '\0');
}
