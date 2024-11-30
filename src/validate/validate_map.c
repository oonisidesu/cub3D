/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/30 17:13:13 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

bool	is_empty_line(const char *line, t_game *game)
{
	char	*trimmed_line;
	bool	result;

	trimmed_line = ft_strtrim(line, " \t\n");
	if (!trimmed_line)
		print_error_free_exit("Failed to trim line\n", game);
	result = (ft_strlen(trimmed_line) == 0);
	free(trimmed_line);
	return (result);
}

bool	is_map_line(const char *line, t_game *game)
{
	char	*valid_chars;

	valid_chars = " 01NSEW";
	while (*line)
	{
		if (!ft_strchr(valid_chars, *line))
			print_error_free_exit("Invalid charactere in map line\n", game);
		line++;
	}
	return (true);
}

bool	is_texture_or_color_line(const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		return (true);
	}
	return (false);
}

bool	validate_and_save_line(const char *line, t_game *game)
{
	if (is_empty_line(line, game))
		return (true);
	if (is_texture_or_color_line(line))
		return (true);
	if (is_map_line(line, game))
		return (true);
	return (false);
}
