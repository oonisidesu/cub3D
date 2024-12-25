/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:36:45 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/25 11:29:26 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

void	free_parse_obj(t_parse *parse)
{
	if (parse->line)
		free(parse->line);
	wrap_close(&parse->fd);
}
