/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:57:22 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/15 15:15:30 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cub3d.h"
# include <stdio.h>
# include <stdlib.h>

void	display_textures(t_texture *textures);
void	display_colors(t_color *colors);
void	display_map(t_map *map);
void	display_cub3d(t_cub3d *cub3d);

#endif
