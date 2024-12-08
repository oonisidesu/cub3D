/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/08 19:16:03 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

bool	check_space_surrounded(char **map, size_t i, size_t j)
{
	// マップ境界のチェック
	if (i == 0 || j == 0 || map[i + 1] == NULL || map[i][j + 1] == '\0')
		return (false);
	// 空白セルの上下左右に "1" または " " があるかを確認
	if ((map[i - 1][j] != '1' && map[i - 1][j] != ' ') || // 上
		(map[i + 1][j] != '1' && map[i + 1][j] != ' ') || // 下
		(map[i][j - 1] != '1' && map[i][j - 1] != ' ') || // 左
		(map[i][j + 1] != '1' && map[i][j + 1] != ' '))   // 右
	{
		printf("Invalid space at (%zu, %zu): not properly surrounded\n", i, j);
		return (false);
	}
	return (true);
}

bool	check_interior_cells(t_map *map)
{
	size_t	i;
	size_t	j;
	char	cell;

	i = 1;
	while (i < (size_t)(map->height - 1)) // マップの端を除く行を検証
	{
		j = 1;
		while (j < ft_strlen(map->data[i]) - 1) // 行の端を除く列を検証
		{
			cell = map->data[i][j];
			if (cell == '0' || cell == 'N' || cell == 'S' || cell == 'E'
				|| cell == 'W')
			{
				// プレイヤー位置や床のセルが囲まれているか確認
				if (!has_two_or_more_walls_in_row(map->data[i])
					|| !has_two_or_more_walls_in_column(map->data, j,
						map->height))
				{
					printf("Cell at (%zu, %zu) is not surrounded\n", i, j);
					return (false);
				}
			}
			else if (cell == ' ') // 空白セルの検証
			{
				if (!check_space_surrounded(map->data, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (size_t)map->height)
	{
		if (!has_two_or_more_walls_in_row(map->data[i]))
		{
			printf("Row %zu does not have enough walls.\n", i);
			return (false);
		}
		i++;
	}
	j = 0;
	while (j < ft_strlen(map->data[0]))
	{
		if (!has_two_or_more_walls_in_column(map->data, j, (size_t)map->height))
		{
			printf("Column %zu does not have enough walls.\n", j);
			return (false);
		}
		j++;
	}
	return (true);
}

bool	check_map_closed(t_map *map)
{
	if (!check_map_walls(map))
		return (false);
	if (!check_interior_cells(map))
		return (false);
	return (true);
}
