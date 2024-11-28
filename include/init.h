/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:46 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 17:05:56 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"
# include "draw.h"
# include <stdio.h>
# include <stdlib.h>

void	init_game_data(t_cub3d *game);
void	init_mlx(t_game *game);
void	init_textures(t_game *game);
void	init_wall_params(t_wall_params *wall_params, t_ray *ray);

#endif
