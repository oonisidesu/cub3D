/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:15:45 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 16:43:37 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/util.h"
#include "init.h"

void	init_textures(t_game *game)
{
	load_texture(game, &game->game_data.textures.north, "texture/wood.xpm");
	load_texture(game, &game->game_data.textures.south, "texture/brick.xpm");
	load_texture(game, &game->game_data.textures.west, "texture/concrete.xpm");
	load_texture(game, &game->game_data.textures.east, "texture/twinkle.xpm");
	load_texture(game, &game->game_data.textures.floor, "texture/ground.xpm");
	load_texture(game, &game->game_data.textures.ceiling, "texture/sky.xpm");
}
