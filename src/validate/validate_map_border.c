/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_border.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/07 16:22:28 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

bool	check_top_bottom_border(char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] != '1' && line[j] != ' ')
			return (false);
		j++;
	}
	return (true);
}

bool	check_left_right_border(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height - 1)
	{
		if (map->data[i][0] != '1' && map->data[i][0] != ' ')
			return (false);
		j = ft_strlen(map->data[i]) - 1;
		if (map->data[i][j] != '1' && map->data[i][j] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	is_surrounded(char **map, int i, int j)
{
	bool	is_top_invalid;
	bool	is_bottom_invalid;
	bool	is_left_invalid;
	bool	is_right_invalid;

	is_top_invalid = (map[i - 1][j] == ' ' || map[i - 1][j] == '\0');
	is_bottom_invalid = (map[i + 1][j] == ' ' || map[i + 1][j] == '\0');
	is_left_invalid = (map[i][j - 1] == ' ' || map[i][j - 1] == '\0');
	is_right_invalid = (map[i][j + 1] == ' ' || map[i][j + 1] == '\0');
	return (!(is_top_invalid || is_bottom_invalid || is_left_invalid
			|| is_right_invalid));
}

bool	check_interior_cells(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)(map->height - 1))
	{
		j = 1;
		while (j < ft_strlen(map->data[i]) - 1)
		{
			if (map->data[i][j] == '0' || map->data[i][j] == 'N'
				|| map->data[i][j] == 'S' || map->data[i][j] == 'E'
				|| map->data[i][j] == 'W')
			{
				if (!is_surrounded(map->data, i, j))
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
	if (!check_top_bottom_border(map->data[0]))
		return (false);
	if (!check_top_bottom_border(map->data[map->height - 1]))
		return (false);
	if (!check_left_right_border(map))
		return (false);
	if (!check_interior_cells(map))
		return (false);
	return (true);
}
