/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bold_tube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:13:52 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 11:14:30 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "graph.h"

void		get_vertical_tube(t_param *param, int x, int y)
{
	param->img_str[x + (param->width * (y - 2))] = param->strong_grey;
	param->img_str[x + (param->width * (y - 1))] = param->strong_grey;
	param->img_str[x + (param->width * y)] = param->strong_grey;
	param->img_str[x + (param->width * (y + 1))] = param->strong_grey;
	param->img_str[x + (param->width * (y + 2))] = param->strong_grey;
}

void		get_horizontal_tube(t_param *param, int x, int y)
{
	param->img_str[(x - 2) + (param->width * y)] = param->strong_grey;
	param->img_str[(x - 1) + (param->width * y)] = param->strong_grey;
	param->img_str[x + (param->width * y)] = param->strong_grey;
	param->img_str[(x + 1) + (param->width * y)] = param->strong_grey;
	param->img_str[(x + 2) + (param->width * y)] = param->strong_grey;
}
