/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:32:08 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/04 18:36:05 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "ray.h"
#include "util.h"

void	perform_dda(t_game *game, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		// 範囲外アクセスのチェック
		if (ray->map_x < 0 || ray->map_x >= game->game_data.map.width
			|| ray->map_y < 0 || ray->map_y >= game->game_data.map.height)
		{
			fprintf(stderr, "Error: Out-of-bounds access at map[%d][%d]\n",
				ray->map_y, ray->map_x);
			exit(EXIT_FAILURE);
		}
		// マップデータのNULLチェック
		if (game->game_data.map.data == NULL)
		{
			fprintf(stderr, "Error: Map data is NULL\n");
			exit(EXIT_FAILURE);
		}
		// マップデータへのアクセス
		if (game->game_data.map.data[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
}
