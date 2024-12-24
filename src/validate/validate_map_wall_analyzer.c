/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wall_analyzer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/24 18:53:21 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

static bool	is_map_edge(t_map *map, size_t i, size_t j)
{
	if ((i == 0 || j == 0 || i == (map->height - 1) || j == (map->width - 1)))
	{
		if (map->data[i][j] == '0')
			return (true);
	}
	return (false);
}

static void	check_neighbors(t_check_params *params)
{
	size_t				new_i;
	size_t				new_j;
	size_t				d;
	static const int	directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	d = 0;
	while (d < 4)
	{
		new_i = params->current.i + directions[d][0];
		new_j = params->current.j + directions[d][1];
		if (new_i >= params->map->height || new_j >= params->map->width)
		{
			d++;
			continue ;
		}
		if (params->visited[new_i][new_j] == VISITED
			|| params->map->data[new_i][new_j] == WALL_CHAR)
		{
			d++;
			continue ;
		}
		params->visited[new_i][new_j] = VISITED;
		params->queue[(*params->rear)++] = (t_node){new_i, new_j};
		d++;
	}
}

static bool	process_queue(t_check_params *params)
{
	t_node	current;

	while (*(params->front) < *(params->rear))
	{
		current = params->queue[(*(params->front))++];
		params->current = current;
		if (is_map_edge(params->map, current.i, current.j))
		{
			wrap_free(params->queue);
			return (false);
		}
		check_neighbors(params);
	}
	wrap_free(params->queue);
	return (true);
}

bool	is_surrounded_by_walls(t_map *map, size_t start_i, size_t start_j,
		char **visited)
{
	t_node			*queue;
	size_t			front;
	size_t			rear;
	t_check_params	params;

	front = 0;
	rear = 0;
	queue = malloc((map->height * map->width) * sizeof(t_node));
	if (!queue)
		return (false);
	queue[rear++] = (t_node){start_i, start_j};
	visited[start_i][start_j] = VISITED;
	params = (t_check_params){map, {start_i, start_j}, queue, &front, &rear,
		visited};
	return (process_queue(&params));
}
