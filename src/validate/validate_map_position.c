/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/12 16:30:34 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

bool	check_map_characters(t_map *map)
{
	size_t	i;
	size_t	j;

	if (!map || !map->data)
		return (false);
	i = 0;
	while (i < (size_t)map->height)
	{
		if (!map->data[i])
			return (false);
		j = 0;
		while (map->data[i][j] != '\0')
		{
			if (!ft_strchr(VALID_MAP_CHARS, map->data[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_player_position(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	player_count;

	if (!map || !map->data)
		return (false);
	i = 0;
	player_count = 0;
	while (i < (size_t)map->height)
	{
		if (!map->data[i])
			return (false);
		j = 0;
		while (map->data[i][j] != '\0')
		{
			if (ft_strchr(PLAYER_CHARS, map->data[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	return (player_count == 1);
}
