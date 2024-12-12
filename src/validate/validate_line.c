/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/10 18:15:11 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

static bool	is_empty_line(const char *line)
{
	return (ft_strlen(line) == 0);
}

static bool	is_map_line(const char *line, t_game *game)
{
	while (*line)
	{
		if (!ft_strchr(VALID_MAP_CHARS, *line))
			print_error_free_exit("Invalid charactere in map line\n", game);
		line++;
	}
	return (true);
}

static bool	is_texture_or_color_line(const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		return (true);
	}
	return (false);
}

bool	validate_line(const char *line, t_game *game)
{
	if (is_empty_line(line))
		return (true);
	if (is_texture_or_color_line(line))
		return (true);
	if (is_map_line(line, game))
		return (true);
	return (false);
}
