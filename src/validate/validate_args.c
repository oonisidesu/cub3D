/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:59:04 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/21 14:57:09 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "validate.h"

static bool	has_valid_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

int	validate_args(int argc, char **argv)
{
	if (argc != 2)
		return (ERROR);
	if (!has_valid_extension(argv[1]))
		return (ERROR);
	return (SUCCESS);
}
