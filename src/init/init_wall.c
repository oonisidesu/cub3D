/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:00:53 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 17:05:36 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "init.h"
#include "ray.h"

void	init_wall_params(t_wall_params *wall_params, t_ray *ray)
{
	wall_params->line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	wall_params->draw_start = -wall_params->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall_params->draw_start < 0)
		wall_params->draw_start = 0;
	wall_params->draw_end = wall_params->line_height / 2 + WINDOW_HEIGHT / 2;
	if (wall_params->draw_end >= WINDOW_HEIGHT)
		wall_params->draw_end = WINDOW_HEIGHT - 1;
}
