/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/10 15:41:45 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

// 再帰的な探索関数
bool	is_surrounded_by_walls(char **map, int height, int width, int i, int j,
		bool **visited)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	// 範囲外アクセスを防止
	if (i < 0 || j < 0 || i >= height || j >= width)
	{
		printf("Out of bounds detected at (%d, %d)\n", i, j);
		return (false);
	}
	// 壁または空白なら探索終了（壁とみなす）
	if (map[i][j] == '1' || map[i][j] == ' ')
	{
		return (true);
	}
	// 既に訪問済みならスキップ
	if (visited[i][j])
	{
		return (true);
	}
	// 訪問済みに設定
	visited[i][j] = true;
	// プレイヤー位置や床 (`0`, `N`, `S`, `E`, `W`) に対するチェック
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W')
	{
		// 周囲を探索
		up = is_surrounded_by_walls(map, height, width, i - 1, j, visited);
		if (!up)
			return (false); // 壁が見つかったらそれ以降探索しない
		down = is_surrounded_by_walls(map, height, width, i + 1, j, visited);
		if (!down)
			return (false);
		left = is_surrounded_by_walls(map, height, width, i, j - 1, visited);
		if (!left)
			return (false);
		right = is_surrounded_by_walls(map, height, width, i, j + 1, visited);
		if (!right)
			return (false);
		return (true);
	}
	// 無効な文字があればエラー
	printf("Invalid character '%c' detected at (%d, %d)\n", map[i][j], i, j);
	return (false);
}

bool	check_map_closed(t_map *map)
{
	bool	**visited;

	// 訪問済み配列を初期化
	visited = malloc(sizeof(bool *) * map->height);
	if (!visited)
	{
		perror("Failed to allocate memory for visited array");
		return (false);
	}
	for (int i = 0; i < map->height; i++)
	{
		visited[i] = calloc(map->width, sizeof(bool));
		if (!visited[i])
		{
			perror("Failed to allocate memory for visited row");
			for (int k = 0; k < i; k++)
				free(visited[k]);
			free(visited);
			return (false);
		}
	}
	// プレイヤーの初期位置を検索
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (map->data[i][j] == 'N' || map->data[i][j] == 'S'
				|| map->data[i][j] == 'E' || map->data[i][j] == 'W')
			{
				if (!is_surrounded_by_walls(map->data, map->height, map->width,
						i, j, visited))
				{
					printf("Error: Player's position (%d, \
						%d) is not surrounded by walls.\n", i, j);
					for (int k = 0; k < map->height; k++)
						free(visited[k]);
					free(visited);
					return (false);
				}
			}
		}
	}
	// メモリ解放
	for (int i = 0; i < map->height; i++)
	{
		free(visited[i]);
	}
	free(visited);
	return (true);
}
