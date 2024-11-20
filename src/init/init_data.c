/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:36 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/20 17:41:42 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ray.h"
#include <math.h>

void	init_game_data(t_cub3d *game)
{
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.west = NULL;
	game->textures.east = NULL;
	game->colors.floor[0] = 0;
	game->colors.floor[1] = 0;
	game->colors.floor[2] = 0;
	game->colors.ceiling[0] = 0;
	game->colors.ceiling[1] = 0;
	game->colors.ceiling[2] = 0;
	game->map.data = NULL;
	game->map.width = 0;
	game->map.height = 0;
}

void	init_minilibx(t_game *game)
{
	// MinilibX の初期化
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error initializing MinilibX");
		exit(EXIT_FAILURE);
	}
	// ウィンドウの作成
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!game->win)
	{
		perror("Error creating window");
		exit(EXIT_FAILURE);
	}
	// 画像の作成
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img.img)
	{
		perror("Error creating image");
		exit(EXIT_FAILURE);
	}
	// 画像データの取得
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (!game->img.addr)
	{
		perror("Error getting image address");
		exit(EXIT_FAILURE);
	}
}

void	initialize_ray(t_game *game, t_ray *ray, int x)
{
	t_player	*player;

	player = &game->game_data.player;
	// カメラ平面のx座標を計算
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	// レイの方向ベクトルを計算
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	// 現在のマップグリッド位置を計算
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	// delta_dist を計算 (レイがグリッドを横断するのにかかる距離)
	if (fabs(ray->ray_dir_x) < 1e-6) // ゼロ除算回避
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (fabs(ray->ray_dir_y) < 1e-6) // ゼロ除算回避
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	// サイドディスタンスとステップ方向を初期化
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
