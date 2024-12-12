/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wall_analyzer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/12 19:12:25 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

static bool	is_out_of_bounds(t_map *map, size_t i, size_t j)
{
	return (i >= (size_t)map->height || j >= (size_t)map->width);
}

static bool	is_wall_or_space(t_map *map, size_t i, size_t j)
{
	return (map->data[i][j] == '1' || map->data[i][j] == ' ');
}

static bool	is_valid_map_char(t_map *map, size_t i, size_t j)
{
	return (ft_strchr(VALID_MAP_CHARS, map->data[i][j]) != NULL);
}

static bool	explore_neighbors(t_map *map, size_t i, size_t j, char **visited)
{
	if (i > 0 && !is_surrounded_by_walls(map, i - 1, j, visited))
		return (false);
	if ((i + 1) < (size_t)map->height && !is_surrounded_by_walls(map, i + 1, j,
			visited))
		return (false);
	if (j > 0 && !is_surrounded_by_walls(map, i, j - 1, visited))
		return (false);
	if ((j + 1) < (size_t)map->width && !is_surrounded_by_walls(map, i, j + 1,
			visited))
		return (false);
	return (true);
}

bool	is_surrounded_by_walls(t_map *map, size_t i, size_t j, char **visited)
{
	if (is_out_of_bounds(map, i, j))
		return (false);
	if (is_wall_or_space(map, i, j))
		return (true);
	if (visited[i][j])
		return (true);
	visited[i][j] = true;
	if (!is_valid_map_char(map, i, j))
		return (false);
	return (explore_neighbors(map, i, j, visited));
}
