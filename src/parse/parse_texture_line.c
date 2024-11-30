/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/29 18:59:56 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <string.h>

bool	parse_texture_line(const char *line, t_texture *textures)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		textures->c_north = ft_strdup(line + 3);
		if (!textures->c_north)
			return (false);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		textures->c_south = ft_strdup(line + 3);
		if (!textures->c_south)
			return (false);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		textures->c_west = ft_strdup(line + 3);
		if (!textures->c_west)
			return (false);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		textures->c_east = ft_strdup(line + 3);
		if (!textures->c_east)
			return (false);
	}
	return (true);
}
