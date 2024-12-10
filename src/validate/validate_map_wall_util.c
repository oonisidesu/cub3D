/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_wall_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/08 19:15:47 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

bool	has_two_or_more_walls_in_row(char *row)
{
	int		wall_count;
	size_t	j;

	wall_count = 0;
	j = 0;
	while (row[j] != '\0')
	{
		if (row[j] == '1')
		{
			wall_count++;
			if (wall_count >= 2)
				return (true);
		}
		j++;
	}
	return (false);
}

bool	has_two_or_more_walls_in_column(char **map, size_t column_index,
		size_t height)
{
	int		wall_count;
	size_t	i;

	wall_count = 0;
	i = 0;
	while (i < height)
	{
		if (map[i][column_index] == '1')
		{
			wall_count++;
			if (wall_count >= 2)
				return (true);
		}
		i++;
	}
	return (false);
}
