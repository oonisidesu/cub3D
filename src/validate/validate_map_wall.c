/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/24 18:53:34 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

static void	free_visited_map(char **visited, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		wrap_free(visited[i]);
		i++;
	}
	wrap_free(visited);
}

static char	**allocate_visited_map(t_map *map)
{
	char	**visited;
	size_t	i;

	visited = malloc(sizeof(char *) * map->height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		visited[i] = malloc(map->width * sizeof(char));
		if (!visited[i])
		{
			free_visited_map(visited, i);
			return (NULL);
		}
		ft_memset(visited[i], NOT_VISITED, map->width * sizeof(char));
		i++;
	}
	return (visited);
}

static bool	is_valid_player_char(t_map *map, size_t i, size_t j)
{
	return (ft_strchr(PLAYER_CHARS, map->data[i][j]) != NULL);
}

static bool	analyze_player_position(t_map *map, char **visited)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_valid_player_char(map, i, j))
			{
				if (!is_surrounded_by_walls(map, i, j, visited))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_closed(t_map *map)
{
	char	**visited;

	visited = allocate_visited_map(map);
	if (!visited)
		return (false);
	if (!analyze_player_position(map, visited))
	{
		free_visited_map(visited, map->height);
		return (false);
	}
	free_visited_map(visited, map->height);
	return (true);
}
