/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:13:53 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/23 23:57:11 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "cub3d.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define VALID_MAP_CHARS " 01NSEW"
# define PLAYER_CHARS "NSEW"
# define WALL_CHAR '1'

typedef enum e_visit_status
{
	NOT_VISITED = '0',
	VISITED = '1'
}			t_visit_status;

typedef struct s_node
{
	size_t	i;
	size_t	j;
}			t_node;

typedef struct s_check_params
{
	t_map	*map;
	t_node	current;
	t_node	*queue;
	size_t	*front;
	size_t	*rear;
	char	**visited;
}			t_check_params;

int			validate_args(int argc, char **argv);
void		validate_line(int fd, const char *line, t_game *game,
				t_cub_el *cub_el_flag);
bool		validate_map(t_map *map);
void		validate_cub_file(t_game *game, t_cub_el *cub_el_flag);
bool		check_map_characters(t_map *map);
bool		check_player_position(t_map *map);
bool		check_map_closed(t_map *map);
bool		has_two_or_more_walls_in_row(char *row);
bool		has_two_or_more_walls_in_column(char **map, size_t column_index,
				size_t height);
bool		is_surrounded_by_walls(t_map *map, size_t i, size_t j,
				char **visited);

#endif