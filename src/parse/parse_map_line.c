/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:12:23 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/15 17:14:08 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

void	parse_map_line(char *line, t_list **map_lines, int *map_height)
{
	(void)line;
	(void)map_lines;
	(void)map_height;
	// char	*line_copy;
	// // デバッグ: 受け取った行を表示
	// printf("[DEBUG] Processing line: '%s', Current height: %d\n", line,
	// 	*map_height);
	// // 空行が来た場合はスキップ
	// if (ft_strlen(line) == 0)
	// {
	// 	printf("[DEBUG] Skipping empty line\n");
	// 	free(line);
	// 	return ;
	// }
	// // `line` を解放する前にコピー
	// line_copy = ft_strdup(line);
	// if (!line_copy)
	// {
	// 	perror("[DEBUG] Error duplicating line");
	// 	free(line);
	// 	exit(EXIT_FAILURE);
	// }
	// free(line);
	// // リストに追加
	// ft_lstadd_back(map_lines, ft_lstnew(line_copy));
	// (*map_height)++;
}

void	finalize_map(t_map *map, t_list *map_lines, int map_height)
{
	(void)map;
	(void)map_lines;
	(void)map_height;
	// t_list	*tmp;
	// int		i;
	// int		line_length;
	// // デバッグ: 関数の開始
	// printf("[DEBUG] Entering finalize_map with height: %d\n", map_height);
	// tmp = map_lines;
	// i = 0;
	// // メモリ確保
	// printf("[DEBUG] Allocating memory for map->data\n");
	// map->data = malloc(sizeof(char *) * (map_height + 1));
	// if (!map->data)
	// {
	// 	perror("[DEBUG] Error allocating memory for map");
	// 	ft_lstclear(&map_lines, free);
	// 	exit(EXIT_FAILURE);
	// }
	// printf("[DEBUG] Memory allocation successful\n");
	// // リストを配列に変換
	// printf("[DEBUG] Converting list to array, starting with map_height:
	// %d\n",
	// 	map_height);
	// while (tmp)
	// {
	// 	printf("[DEBUG] Current tmp address: %p\n", (void *)tmp);
	// 	// tmp->content が NULL の場合を確認
	// 	if (!tmp->content)
	// 	{
	// 		printf("[DEBUG] Warning: tmp->content is NULL. Skipping this node.\n");
	// 		tmp = tmp->next;
	// 		continue ;
	// 	}
	// 	printf("[DEBUG] Current tmp->content: '%s'\n", (char *)tmp->content);
	// 	// ft_strdup が NULL を返した場合のエラーハンドリング
	// 	map->data[i] = ft_strdup((char *)tmp->content);
	// 	if (!map->data[i])
	// 	{
	// 		perror("[DEBUG] Error duplicating list content to map->data");
	// 		ft_lstclear(&map_lines, free);
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	printf("[DEBUG] Added line to map->data[%d]: '%s'\n", i, map->data[i]);
	// 	// 次のノードへ進む
	// 	tmp = tmp->next;
	// 	printf("[DEBUG] Moving to next tmp. New tmp address: %p\n",
	// 		(void *)tmp);
	// 	i++;
	// }
	// map->data[i] = NULL;
	// printf("[DEBUG] Finished converting list to array. Total lines: %d\n",
	// i);
	// // 幅と高さを更新
	// printf("[DEBUG] Calculating map dimensions\n");
	// map->height = map_height;
	// map->width = 0;
	// for (int j = 0; j < map_height; j++)
	// {
	// 	line_length = ft_strlen(map->data[j]);
	// 	if (line_length > map->width)
	// 		map->width = line_length;
	// 	printf("[DEBUG] Line length of map->data[%d]: %d\n", j, line_length);
	// }
	// // デバッグ: 幅と高さの確定
	// printf("[DEBUG] Final map width: %d, height: %d\n", map->width,
	// 	map->height);
	// // リストを解放
	// printf("[DEBUG] Clearing list\n");
	// ft_lstclear(&map_lines, free);
	// printf("[DEBUG] List cleared. Exiting finalize_map\n");
}
