/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:34:21 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 18:48:15 by ootsuboyosh      ###   ########.fr       */
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
	if (keycode == KEY_W)
		offset = (t_offset){0, -1}; // 上方向
	else if (keycode == KEY_S)
		offset = (t_offset){0, 1}; // 下方向
	else if (keycode == KEY_A)
		offset = (t_offset){-1, 0}; // 左方向
	else if (keycode == KEY_D)
		offset = (t_offset){1, 0}; // 右方向
	else if (keycode == KEY_ESC)
	{
		printf("Exiting game.\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == KEY_LEFT) // 左矢印キーで左回転
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
	else if (keycode == KEY_RIGHT) // 右矢印キーで右回転
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
	// 移動処理を呼び出し
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
