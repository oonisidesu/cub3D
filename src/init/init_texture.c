/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:15:45 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/07 16:20:42 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "init.h"

void	init_textures(t_game *game)
{
	load_texture(game, &game->game_data.textures.north,
		game->game_data.textures.c_north);
	load_texture(game, &game->game_data.textures.south,
		game->game_data.textures.c_south);
	load_texture(game, &game->game_data.textures.west,
		game->game_data.textures.c_west);
	load_texture(game, &game->game_data.textures.east,
		game->game_data.textures.c_east);
}
