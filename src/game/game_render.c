/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:27 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 16:31:56 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "ray.h"
#include "util.h"

void	render_scene(t_game *game)
{
	t_ray	ray;
	int		x;
	int		line_height;
	int		draw_start;
	int		draw_end;

	// 天井と床を描画
	draw_floor_and_ceiling(game);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		// レイの初期化
		init_ray(game, &ray, x);
		// DDAアルゴリズムで壁を探索
		perform_dda(game, &ray);
		// 壁までの垂直距離を計算
		calculate_wall_distance(&ray, &game->game_data.player);
		// 壁の高さを計算
		line_height = (int)(WINDOW_HEIGHT / ray.perp_wall_dist);
		// 壁の描画範囲を計算
		draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_end >= WINDOW_HEIGHT)
			draw_end = WINDOW_HEIGHT - 1;
		// 壁をテクスチャで描画
		draw_wall(game, &ray, x, draw_start, draw_end);
		x++;
	}
	// 描画した画像をウィンドウに表示
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
