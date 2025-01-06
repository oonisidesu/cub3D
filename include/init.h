/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:46 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2025/01/05 21:57:13 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"
# include "draw.h"
# include <stdio.h>
# include <stdlib.h>

void	init_game(t_game *game);
void	init_mlx_texture(t_game *game);
void	init_textures(t_game *game);
void	init_wall_params(t_wall_params *wall_params, t_ray *ray);
void	init_cub_el(t_cub_el *cub_el_flag);

#endif
