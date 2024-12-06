/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/06 16:31:20 by ootsuboyosh      ###   ########.fr       */
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

void	validate_cub_file(t_game *game, t_cub_el *cub_el_flag)
{
	if (!cub_el_flag->has_no || !cub_el_flag->has_so || !cub_el_flag->has_we
		|| !cub_el_flag->has_ea || !cub_el_flag->has_f || !cub_el_flag->has_c)
		print_error_free_exit("Missing required elements in .cub file\n", game);
	if (!validate_map(&game->game_data.map))
		print_error_free_exit("Invalid map\n", game);
}
