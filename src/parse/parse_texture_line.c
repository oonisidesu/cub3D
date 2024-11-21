/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 17:56:00 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <string.h>

// テクスチャ情報を解析し、t_texture構造体に保存
void	parse_texture_line(const char *line, t_texture *textures)
{
	if (ft_strncmp(line, "NO ", 3) == 0) // NOテクスチャ
		textures->c_north = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0) // SOテクスチャ
		textures->c_south = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0) // WEテクスチャ
		textures->c_west = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0) // EAテクスチャ
		textures->c_east = ft_strdup(line + 3);
	else
		fprintf(stderr, "Error: Invalid texture identifier in line: %s\n",
			line);
}
