/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:12:23 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/10 17:12:22 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	init_map_array(t_map *map, int initial_size)
{
	map->data = malloc(sizeof(char *) * initial_size);
	if (!map->data)
	{
		perror("Error allocating initial map data");
		exit(EXIT_FAILURE);
	}
	map->width = 0;
	map->height = 0;
}

void	ensure_map_cap(t_map *map, int *allocated_size)
{
	if (map->height >= *allocated_size)
	{
		*allocated_size *= RESIZE_FACTOR;
		map->data = resize_array(map->data, map->height, *allocated_size);
	}
}

void	add_map_line(const char *line, t_map *map)
{
	map->data[map->height] = ft_strdup(line);
	if (!map->data[map->height])
	{
		perror("Error duplicating map line");
		exit(EXIT_FAILURE);
	}
	map->height++;
}

void	update_map_width(const char *line, t_map *map)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line_length > map->width)
		map->width = line_length;
}

void	parse_map_line(const char *line, t_map *map)
{
	static int	allocated_size;

	if (map->data == NULL)
	{
		allocated_size = MAP_INITIAL_SIZE;
		init_map_array(map, allocated_size);
	}
	ensure_map_cap(map, &allocated_size);
	add_map_line(line, map);
	update_map_width(line, map);
}
