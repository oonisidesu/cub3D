/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/04 17:37:35 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define MAP_INITIAL_SIZE 10
# define RESIZE_FACTOR 2
# define WHITESPACE_CHARS " \t\n\r\v\f"

int		parse_color_line(const char *line, int color[3]);
void	parse_cub_file(const char *filename, t_game *game);
bool	parse_texture_line(const char *line, t_texture *textures);
void	parse_map_line(const char *line, t_map *map);

#endif
