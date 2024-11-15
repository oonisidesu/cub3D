/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/15 17:12:50 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parse.h"
#include <fcntl.h>

// ファイルを解析してt_cub3d構造体にデータを保存
void	parse_cub_file(const char *filename, t_cub3d *game)
{
	int		fd;
	char	*line;
	int		map_height;

	map_height = 0;
	t_list *map_lines = NULL; // リストの初期化
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ",
				3) == 0)
		{
			parse_texture_line(line, &game->textures);
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			parse_color_line(line + 2, game->colors.floor);
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			parse_color_line(line + 2, game->colors.ceiling);
		}
		else if (ft_strlen(line) > 0)
		{
			// マップデータの行であると判断　TODO
			parse_map_line(line, &map_lines, &map_height);
		}
		free(line);
	}
	// マップを確定 TODO
	finalize_map(&game->map, map_lines, map_height);
	close(fd);
}
