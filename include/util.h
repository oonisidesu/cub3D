/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:50:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 14:54:57 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "cub3d.h"

void	put_pixel_to_image(t_game *game, int x, int y, int color);
void	load_texture(t_game *game, t_img *texture, char *path);
char	**resize_array(char **old_array, int old_size, int new_size);

#endif