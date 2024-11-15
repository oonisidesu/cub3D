/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:12:23 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/15 18:42:07 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 配列を拡張する関数
char	**resize_map_array(char **old_array, int old_size, int new_size)
{
	char	**new_array;
	int		i;

	// 新しい配列を確保
	new_array = malloc(sizeof(char *) * new_size);
	if (!new_array)
	{
		perror("Error allocating memory for new array");
		exit(EXIT_FAILURE);
	}
	// 古い配列の内容をコピー
	for (i = 0; i < old_size; i++)
		new_array[i] = old_array[i];
	// 古い配列を解放
	free(old_array);
	return (new_array);
}

// マップデータを直接格納する
void	parse_map_line(const char *line, t_map *map)
{
	static int	allocated_size;
	int			line_length;

	// 初回のみ初期サイズを確保
	if (map->data == NULL)
	{
		allocated_size = 10; // 初期サイズ
		map->data = malloc(sizeof(char *) * allocated_size);
		if (!map->data)
		{
			perror("Error allocating initial map data");
			exit(EXIT_FAILURE);
		}
	}
	// 配列が満杯になった場合、サイズを拡張
	if (map->height >= allocated_size)
	{
		allocated_size *= 2; // 配列サイズを2倍に
		map->data = resize_map_array(map->data, map->height, allocated_size);
	}
	// 行を複製して配列に追加
	map->data[map->height] = ft_strdup(line);
	if (!map->data[map->height])
	{
		perror("Error duplicating map line");
		exit(EXIT_FAILURE);
	}
	// マップの幅を更新（改行分-1する）（もっといい方法があるかも）
	line_length = ft_strlen(line) - 1;
	if (line_length > map->width)
		map->width = line_length;
	// マップの高さを更新
	map->height++;
}
