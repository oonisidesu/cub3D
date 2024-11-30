/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:13:53 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/30 18:02:28 by ootsuboyosh      ###   ########.fr       */
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
bool	check_map_closed(t_map *map);

#endif