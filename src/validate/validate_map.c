/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/04 18:13:24 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

bool	check_map_characters(t_map *map)
{
	char	*valid_chars;
	int		i;
	int		j;

	if (!map || !map->data)
		return (false);
	valid_chars = " 01NSEW";
	i = 0;
	while (i < map->height)
	{
		if (!map->data[i])
			return (false);
		j = 0;
		while (map->data[i][j] != '\0')
		{
			if (!ft_strchr(valid_chars, map->data[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_player_position(t_map *map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->data[i][j] != '\0')
		{
			if (ft_strchr("NSEW", map->data[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

bool	validate_map(t_map *map)
{
	if (!check_map_characters(map))
		return (false);
	if (!check_player_position(map))
		return (false);
	if (!check_map_closed(map))
		return (false);
	return (true);
}
