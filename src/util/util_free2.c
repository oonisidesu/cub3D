/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:36:45 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/24 19:25:37 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

void	wrap_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	free_parse_obj(t_parse *parse)
{
	if (parse->line)
		wrap_free(parse->line);
	wrap_close(&parse->fd);
}
