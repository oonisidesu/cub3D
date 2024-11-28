/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:27 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 16:22:38 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game.h"
#include "ray.h"
#include "util.h"

void	render_scene(t_game *game)
{
	t_ray			ray;
	t_wall_params	wall_params;

	// 天井と床を描画
	draw_floor_and_ceiling(game);
	wall_params.x = 0;
	while (wall_params.x < WINDOW_WIDTH)
	{
		// レイの初期化
		init_ray(game, &ray, wall_params.x);
		// DDAアルゴリズムで壁を探索
		perform_dda(game, &ray);
		// 壁までの垂直距離を計算
		calculate_wall_distance(&ray, &game->game_data.player);
		// 壁の高さを計算
		wall_params.line_height = (int)(WINDOW_HEIGHT / ray.perp_wall_dist);
		// 壁の描画範囲を計算
		wall_params.draw_start = -wall_params.line_height / 2 + WINDOW_HEIGHT
			/ 2;
		if (wall_params.draw_start < 0)
			wall_params.draw_start = 0;
		wall_params.draw_end = wall_params.line_height / 2 + WINDOW_HEIGHT / 2;
		if (wall_params.draw_end >= WINDOW_HEIGHT)
			wall_params.draw_end = WINDOW_HEIGHT - 1;
		// 壁を描画
		draw_wall(game, &ray, &wall_params);
		wall_params.x++;
	}
	// 描画した画像をウィンドウに表示
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	handle_loop(t_game *game)
{
	render_scene(game);
	return (0);
}
