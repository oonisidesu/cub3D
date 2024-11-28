/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:17 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 16:19:08 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "draw.h"
#include "util.h"
#include <math.h>

void	draw_wall(t_game *game, t_ray *ray, t_wall_params *params)
{
	t_img	*texture;
	int		color;
	double	wall_x;

	int tex_x, tex_y;
	double step, tex_pos;
	// 壁に応じたテクスチャを選択
	if (ray->side == 0)
		texture = (ray->step_x < 0) ? &game->game_data.textures.west : &game->game_data.textures.east;
	else
		texture = (ray->step_y < 0) ? &game->game_data.textures.north : &game->game_data.textures.south;
	// 壁のX座標を計算（テクスチャ内）
	wall_x = (ray->side == 0) ? ray->map_y + ray->perp_wall_dist
		* ray->ray_dir_y : ray->map_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	// テクスチャの縦方向ステップ
	step = 1.0 * texture->height / params->line_height;
	tex_pos = (params->draw_start - WINDOW_HEIGHT / 2 + params->line_height / 2)
		* step;
	// 壁を描画
	for (int y = params->draw_start; y < params->draw_end; y++)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x
					* (texture->bits_per_pixel / 8)));
		put_pixel_to_image(game, params->x, y, color);
	}
}
