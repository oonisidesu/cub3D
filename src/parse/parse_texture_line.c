/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/04 17:42:32 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <string.h>

bool	set_texture(char **texture_field, const char *path)
{
	*texture_field = ft_strdup(path);
	return (*texture_field != NULL);
}

bool	parse_texture_line(const char *line, t_texture *textures)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_texture(&textures->c_north, line + 3));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_texture(&textures->c_south, line + 3));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_texture(&textures->c_west, line + 3));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_texture(&textures->c_east, line + 3));
	return (false);
}
