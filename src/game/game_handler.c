/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:34:21 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/25 18:40:10 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

// キー入力イベントを処理
int	handle_keypress(int keycode, t_game *game)
{
	t_offset	offset;
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &game->game_data.player;
	// 構造体全体をゼロ初期化
	printf("[DEBUG] Key pressed: %d\n", keycode);
	ft_memset(&offset, 0, sizeof(t_offset));
	// 前進・後退の処理
	if (keycode == KEY_W)
	{
		offset.dx = player->dir_x * MOVE_SPEED;
		offset.dy = player->dir_y * MOVE_SPEED;
	}
	else if (keycode == KEY_S)
	{
		offset.dx = -player->dir_x * MOVE_SPEED;
		offset.dy = -player->dir_y * MOVE_SPEED;
	}
	// 左右移動（ストレイフ）の処理
	else if (keycode == KEY_A)
	{
		printf("player->plane_x : %f, player->plane_y : %f\n", player->plane_x,
			player->plane_y);
		offset.dx = -player->plane_x * MOVE_SPEED;
		offset.dy = -player->plane_y * MOVE_SPEED;
		printf("[DEBUG] Calculated Offset: dx = %.2f, dy = %.2f\n", offset.dx,
			offset.dy);
	}
	else if (keycode == KEY_D)
	{
		offset.dx = player->plane_x * MOVE_SPEED;
		offset.dy = player->plane_y * MOVE_SPEED;
	}
	// 左右回転の処理
	else if (keycode == KEY_LEFT) // 左回転
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y
			* sin(-ROT_SPEED);
		player->dir_y = old_dir_x * sin(-ROT_SPEED) + player->dir_y
			* cos(-ROT_SPEED);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y
			* sin(-ROT_SPEED);
		player->plane_y = old_plane_x * sin(-ROT_SPEED) + player->plane_y
			* cos(-ROT_SPEED);
	}
	else if (keycode == KEY_RIGHT) // 右回転
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y
			* sin(ROT_SPEED);
		player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y
			* cos(ROT_SPEED);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y
			* sin(ROT_SPEED);
		player->plane_y = old_plane_x * sin(ROT_SPEED) + player->plane_y
			* cos(ROT_SPEED);
	}
	// ESCキーで終了
	else if (keycode == KEY_ESC)
	{
		printf("Exiting game.\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	printf("[DEBUG] Offset: dx = %f, dy = %f\n", offset.dx, offset.dy);
	// 壁衝突判定と移動処理
	if (offset.dx != 0 || offset.dy != 0)
		move_player(&game->game_data.map, &game->game_data.player, offset);
	// 新しいシーンを描画
	render_scene(game);
	return (0);
}

// プログラム終了処理
int	exit_program(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win); // ウィンドウを破棄
	// 必要に応じて追加リソースを解放
	exit(0);    // プログラム終了
	return (0); // 必須のリターン値（無意味だが MiniLibX のために必要）
}
