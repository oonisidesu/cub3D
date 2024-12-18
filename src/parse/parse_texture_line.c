/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/18 18:42:16 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "utils.h"
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
	while (*line != '\0' && ft_strchr(" ", *line) != NULL)
		line++;
	return (set_texture(texture_path, line));
}

bool	parse_texture_line(const char *line, t_texture *textures,
		t_cub_el *cub_el_flag)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (process_texture(line, "NO ", &cub_el_flag->has_no,
				&textures->c_north));
	else if (!ft_strncmp(line, "SO ", 3))
		return (process_texture(line, "SO ", &cub_el_flag->has_so,
				&textures->c_south));
	else if (!ft_strncmp(line, "WE ", 3))
		return (process_texture(line, "WE ", &cub_el_flag->has_we,
				&textures->c_west));
	else if (!ft_strncmp(line, "EA ", 3))
		return (process_texture(line, "EA ", &cub_el_flag->has_ea,
				&textures->c_east));
	return (false);
}

bool	is_texture_line(const char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (true);
	if (!ft_strncmp(line, "SO", 2))
		return (true);
	if (!ft_strncmp(line, "WE", 2))
		return (true);
	if (!ft_strncmp(line, "EA", 2))
		return (true);
	return (false);
}
