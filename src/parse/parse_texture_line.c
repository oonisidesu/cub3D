/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/06 17:32:31 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "util.h"
#include <string.h>

static bool	set_texture(char **texture_field, const char *path)
{
	*texture_field = ft_strdup(path);
	return (*texture_field != NULL);
}

static bool	process_texture(const char *line, const char *identifier,
		bool *flag, char **texture_path)
{
	if (*flag)
		return (false);
	*flag = true;
	line += ft_strlen(identifier);
	while (*line != '\0' && ft_strchr(WHITESPACE_CHARS, *line) != NULL)
		line++;
	return (set_texture(texture_path, line));
}

bool	parse_texture_line(const char *line, t_texture *textures,
		t_cub_el *cub_el_flag)
{
	if (is_prefix_and_whitespace(line, "NO", WHITESPACE_CHARS))
		return (process_texture(line, "NO", &cub_el_flag->has_no,
				&textures->c_north));
	else if (is_prefix_and_whitespace(line, "SO", WHITESPACE_CHARS))
		return (process_texture(line, "SO", &cub_el_flag->has_so,
				&textures->c_south));
	else if (is_prefix_and_whitespace(line, "WE", WHITESPACE_CHARS))
		return (process_texture(line, "WE", &cub_el_flag->has_we,
				&textures->c_west));
	else if (is_prefix_and_whitespace(line, "EA", WHITESPACE_CHARS))
		return (process_texture(line, "EA", &cub_el_flag->has_ea,
				&textures->c_east));
	return (false);
}
