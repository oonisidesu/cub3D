/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/12 16:32:33 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

static bool	has_all_required_el(t_cub_el *cub_el_flag)
{
	if (!cub_el_flag->has_no)
		return (false);
	if (!cub_el_flag->has_so)
		return (false);
	if (!cub_el_flag->has_we)
		return (false);
	if (!cub_el_flag->has_ea)
		return (false);
	if (!cub_el_flag->has_f)
		return (false);
	if (!cub_el_flag->has_c)
		return (false);
	return (true);
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
	if (!has_all_required_el(cub_el_flag))
		print_error_free_exit("Missing required elements in .cub file\n", game);
	if (!validate_map(&game->game_data.map))
		print_error_free_exit("Invalid map\n", game);
}
