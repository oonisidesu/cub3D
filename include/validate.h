/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:13:53 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/06 16:30:46 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "cub3d.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

int		validate_args(int argc, char **argv);
bool	validate_and_save_line(const char *line, t_game *game);
bool	validate_map(t_map *map);
void	validate_cub_file(t_game *game, t_cub_el *cub_el_flag);
bool	check_map_closed(t_map *map);

#endif