/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:32:55 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/14 18:14:48 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	parse_cub_file(const char *filename, t_cub3d *game)
{
	int		fd;
	char	*line;

	(void)game;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		// TODO: テクスチャ情報、色情報、マップ行の仮チェックを行う
		printf("Parsed line: %s", line);
		free(line);
	}
	close(fd);
}

// エラーメッセージと使用方法の表示
void	display_usage_and_exit(const char *program_name)
{
	fprintf(stderr, "Usage: %s <map.cub>\n", program_name);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		display_usage_and_exit(argv[0]);
	}
	t_cub3d game;                   // ゲームデータの構造体を作成
	parse_cub_file(argv[1], &game); // パース処理の呼び出し
	// TODO: パースされたデータを用いて描画処理やゲームロジックを開始する
	// 正常終了
	return (0);
}
