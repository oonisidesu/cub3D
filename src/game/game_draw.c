/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:17 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 16:26:52 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "util.h"
#include <math.h>

void	draw_wall(t_game *game, t_ray *ray, int x, int draw_start,
		int draw_end)
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
	step = 1.0 * texture->height / (draw_end - draw_start);
	tex_pos = (draw_start - WINDOW_HEIGHT / 2 + (draw_end - draw_start) / 2)
		* step;
	// 壁を垂直線で描画
	for (int y = draw_start; y < draw_end; y++)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x
					* (texture->bits_per_pixel / 8)));
		put_pixel_to_image(game, x, y, color);
	}
}

void	draw_floor_and_ceiling(t_game *game)
{
	t_img	*floor_texture;
	t_img	*ceiling_texture;
	int		color;

	floor_texture = &game->game_data.textures.floor;
	ceiling_texture = &game->game_data.textures.ceiling;
	for (int y = 0; y < WINDOW_HEIGHT / 2; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH; x++)
		{
			// 天井の色
			color = *(int *)(ceiling_texture->addr + ((y
							% ceiling_texture->height)
						* ceiling_texture->line_length + (x
							% ceiling_texture->width)
						* (ceiling_texture->bits_per_pixel / 8)));
			put_pixel_to_image(game, x, y, color);
		}
	}
	for (int y = WINDOW_HEIGHT / 2; y < WINDOW_HEIGHT; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH; x++)
		{
			// 床の色
			color = *(int *)(floor_texture->addr + ((y % floor_texture->height)
						* floor_texture->line_length + (x
							% floor_texture->width)
						* (floor_texture->bits_per_pixel / 8)));
			put_pixel_to_image(game, x, y, color);
		}
	}
}
