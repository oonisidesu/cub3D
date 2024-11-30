/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/30 18:01:30 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

bool	check_top_bottom_border(char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] != '1' && line[j] != ' ')
			return (false);
		j++;
	}
	return (true);
}

bool	check_left_right_border(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height - 1)
	{
		if (map->data[i][0] != '1' && map->data[i][0] != ' ')
			return (false);
		j = ft_strlen(map->data[i]) - 1;
		if (map->data[i][j] != '1' && map->data[i][j] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_map_closed(t_map *map)
{
	if (!check_top_bottom_border(map->data[0]))
		return (false);
	if (!check_top_bottom_border(map->data[map->height - 1]))
		return (false);
	if (!check_left_right_border(map))
		return (false);
	return (true);
}
