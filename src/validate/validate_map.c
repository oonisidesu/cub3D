/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/30 16:24:50 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include <stdio.h>

// int	validate_file_structure(t_game_data *game_data)
// {
// 	if (!game_data->textures.north || !game_data->textures.south
// 		|| !game_data->textures.west || !game_data->textures.east)
// 	{
// 		fprintf(stderr, "Error\nMissing texture paths (NO, SO, WE, EA)\n");
// 		return (0);
// 	}
// 	if (!game_data->colors.floor || !game_data->colors.ceiling)
// 	{
// 		fprintf(stderr, "Error\nMissing floor (F) or ceiling (C) colors\n");
// 		return (0);
// 	}
// 	return (1);
// }

int	skip_empty_lines(const char **lines, int *index)
{
	while (lines[*index] && lines[*index][0] == '\0')
		(*index)++;
	return (*index);
}

int	is_map_closed(char **map, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[y][x] == '0')
			{
				// 周囲を確認
				if (y == 0 || x == 0 || y == height - 1 || x == width - 1
					|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x
					- 1] == ' ' || map[y][x + 1] == ' ')
				{
					fprintf(stderr, "Error\nMap is not closed at (%d, %d)\n", x,
						y);
					return (0);
				}
			}
		}
	}
	return (1);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	validate_map_chars(char **map, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (!is_valid_map_char(map[y][x]))
			{
				fprintf(stderr, "Error\nInvalid character '%c' in map\n",
					map[y][x]);
				return (0);
			}
		}
	}
	return (1);
}

int	validate_start_position(char **map, int height, t_player *player)
{
	int	start_count;

	start_count = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				start_count++;
				player->x = x + 0.5;
				player->y = y + 0.5;
				// 開始位置をクリアに変更
				map[y][x] = '0';
			}
		}
	}
	if (start_count != 1)
	{
		fprintf(stderr, "Error\nInvalid number of start positions (%d)\n",
			start_count);
		return (0);
	}
	return (1);
}

// int	validate_map(t_game_data *game_data)
// {
// 	if (!validate_file_structure(game_data))
// 		return (0);
// 	if (!validate_map_chars(game_data->map.data, game_data->map.height))
// 		return (0);
// 	if (!validate_start_position(game_data->map.data, game_data->map.height,
// 			&game_data->player))
// 		return (0);
// 	if (!is_map_closed(game_data->map.data, game_data->map.height,
// 			game_data->map.width))
// 		return (0);
// 	return (1);
// }
