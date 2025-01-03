/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:15:44 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 14:24:27 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ray.h"
#include <math.h>

void	cal_ray_direct(t_player *player, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
}

void	cal_delta_dist(t_ray *ray)
{
	if (fabs(ray->ray_dir_x) < 1e-6)
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (fabs(ray->ray_dir_y) < 1e-6)
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	init_side_step(t_player *player, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int x)
{
	t_player	*player;

	player = &game->game_data.player;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	cal_ray_direct(player, ray, x);
	cal_delta_dist(ray);
	init_side_step(player, ray);
}
