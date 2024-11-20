/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:27 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/20 17:26:48 by ootsuboyosh      ###   ########.fr       */
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
	int		color;

	// ウィンドウ全体を背景色で塗りつぶす (例: 黒色)
	for (int y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH; x++)
			put_pixel_to_image(game, x, y, 0x000000); // 黒で塗りつぶし
	}
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		// レイの初期化
		initialize_ray(game, &ray, x);
		// DDAアルゴリズムで壁を探索
		perform_dda(game, &ray);
		// 壁までの垂直距離を計算
		calculate_wall_distance(&ray);
		// 壁の高さを計算
		line_height = (int)(WINDOW_HEIGHT / ray.perp_wall_dist);
		// 壁の描画範囲を計算
		draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_end >= WINDOW_HEIGHT)
			draw_end = WINDOW_HEIGHT - 1;
		// 壁を描画（暫定的に色を設定: x方向は青、y方向は赤）
		color = (ray.side == 0) ? 0x0000FF : 0xFF0000;
		draw_vertical_line(game, x, draw_start, draw_end, color);
		x++;
	}
	// 描画した画像をウィンドウに表示
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
