/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:38:01 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/20 16:38:02 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "display.h"
#include "game.h"
#include "get_next_line.h"
#include "init.h"
#include "parse.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// エラーメッセージと使用方法の表示
void	display_usage_and_exit(const char *program_name)
{
	fprintf(stderr, "Usage: %s <map.cub>\n", program_name);
	exit(1);
}

// メインの描画ループ関数
int	main_loop(t_game *game)
{
	// 背景とシーンの描画
	render_scene(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	// 引数チェック
	if (argc != 2)
		display_usage_and_exit(argv[0]);
	// MinilibX の初期化
	init_minilibx(&game);
	// ゲームデータの初期化とマップの読み込み
	init_game_data(&game.game_data);
	parse_cub_file(argv[1], &game.game_data);
	set_player_position(&game.game_data.map, &game.game_data.player);
	// 描画ループのフック
	mlx_loop_hook(game.mlx, main_loop, &game);
	// キーボード入力イベントフック
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	// イベントループ
	mlx_loop(game.mlx);
	return (0);
}
