/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wall_analyzer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/22 18:41:19 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

static bool	is_map_edge(t_map *map, size_t i, size_t j)
{
	if (((i == 0 || j == 0 || i == (map->height - 1) \
			|| j == (map->width - 1))) && map->data[i][j] == '0')
		return (true);
	return (false);
}

static bool	is_wall(t_map *map, size_t i, size_t j)
{
	if (i >= map->height || j >= map->width)
		return (false);
	return (map->data[i][j] == '1');
}

static bool	explore_neighbors(t_map *map, size_t i, size_t j, char **visited)
{
	if (i > 0 && !is_surrounded_by_walls(map, i - 1, j, visited))
		return (false);
	if ((i + 1) < map->height && !is_surrounded_by_walls(map, i + 1, j,
			visited))
		return (false);
	if (j > 0 && !is_surrounded_by_walls(map, i, j - 1, visited))
		return (false);
	if ((j + 1) < map->width && !is_surrounded_by_walls(map, i, j + 1,
			visited))
		return (false);
	return (true);
}

bool	is_surrounded_by_walls(t_map *map, size_t i, size_t j, char **visited)
{
	if (is_map_edge(map, i, j))
		return (false);
	if (is_wall(map, i, j))
		return (true);
	if (visited[i][j] == VISITED)
		return (true);
	visited[i][j] = VISITED;
	return (explore_neighbors(map, i, j, visited));
}
