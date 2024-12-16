/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:12:23 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/16 17:51:23 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool	init_map_array(t_map *map, size_t initial_size)
{
	map->data = malloc(sizeof(char *) * initial_size);
	if (!map->data)
		return (false);
	ft_memset(map->data, 0, sizeof(char *) * initial_size);
	map->width = 0;
	map->height = 0;
	return (true);
}

static bool	ensure_map_cap(t_map *map, size_t *allocated_size)
{
	if (((size_t)map->height + 1) >= *allocated_size)
	{
		*allocated_size *= RESIZE_FACTOR;
		map->data = resize_array(map->data, map->height, *allocated_size);
		if (!map->data)
			return (false);
	}
	return (true);
}

static bool	add_map_line(const char *line, t_map *map)
{
	map->data[map->height] = ft_strdup(line);
	if (!map->data[map->height])
		return (false);
	map->height++;
	return (true);
}

static void	update_map_width(const char *line, t_map *map)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line_length > map->width)
		map->width = line_length;
}

bool	parse_map_line(const char *line, t_map *map)
{
	static size_t	allocated_size;

	if (map->data == NULL)
	{
		allocated_size = MAP_INITIAL_SIZE;
		if (!init_map_array(map, allocated_size))
			return (false);
	}
	if (!ensure_map_cap(map, &allocated_size))
		return (false);
	if (!add_map_line(line, map))
		return (false);
	update_map_width(line, map);
	return (true);
}
