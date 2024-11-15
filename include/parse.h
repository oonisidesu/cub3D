/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/15 16:52:36 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

int		parse_color_line(const char *line, int color[3]);
void	parse_cub_file(const char *filename, t_cub3d *game);
void	parse_texture_line(const char *line, t_texture *textures);
void	parse_map_line(char *line, t_list **map_lines, int *map_height);
void	finalize_map(t_map *map, t_list *map_lines, int map_height);

#endif
