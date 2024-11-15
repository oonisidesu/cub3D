/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:22 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/15 15:50:50 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

// 色を解析する関数
int	parse_color_line(const char *line, int color[3])
{
	for (int i = 0; i < 3; i++)
	{
		color[i] = ft_atoi_long(line);
		if (color[i] < 0 || color[i] > 255)
		{
			return (0); // エラー: 範囲外の値
		}
		// 数字部分をスキップ
		while (*line >= '0' && *line <= '9')
		{
			line++;
		}
		if (i < 2)
		{ // カンマチェック
			if (*line != ',')
			{
				return (0); // エラー: カンマが不足
			}
			line++; // カンマをスキップ
		}
	}
	return (1); // 成功
}
