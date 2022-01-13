/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:29:27 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 11:27:53 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graph.h"
#include "minilibx_macos/mlx.h"

void		fill_center_room(t_param *param, t_coor pnt, int top, int left)
{
	if (pnt.start)
		param->img_str[left + (param->width * top)] = param->start_room_color;
	else if (pnt.end)
		param->img_str[left + (param->width * top)] = param->end_room_color;
	else
		param->img_str[left + (param->width * top)] = param->strong_grey;
}

void		fill_border_room(t_param *param, t_coor pnt, int top, int left)
{
	if (pnt.start)
		param->img_str[left + (param->width * top)] = param->border_start;
	else if (pnt.end)
		param->img_str[left + (param->width * top)] = param->border_end;
	else
		param->img_str[left + (param->width * top)] = param->light_grey;
}

void		put_room_in_tab(t_param *param, t_coor pnt)
{
	int		top;
	int		left;
	double	dist;

	top = pnt.y - (param->room_size / 2);
	while (top <= (pnt.y + (param->room_size / 2)))
	{
		left = pnt.x - (param->room_size / 2);
		while (left <= (pnt.x + (param->room_size / 2)))
		{
			dist = sqrt(((pnt.x - left) * (pnt.x - left)) \
					+ ((pnt.y - top) * (pnt.y - top)));
			if ((dist + 2) < (param->room_size / 2))
				fill_center_room(param, pnt, top, left);
			else if (dist < (param->room_size / 2))
				fill_border_room(param, pnt, top, left);
			++left;
		}
		++top;
	}
}

void		draw_ant_pixel(t_param *param, t_ant *ant)
{
	int		top;
	int		left;
	double	dist;

	top = ant->position.y - (param->ants_size / 2);
	while (top <= (ant->position.y + (param->ants_size / 2)))
	{
		left = ant->position.x - (param->ants_size / 2);
		while (left <= (ant->position.x + (param->ants_size / 2)))
		{
			dist = sqrt(((ant->position.x - left) * (ant->position.x - left)) \
					+ ((ant->position.y - top) * (ant->position.y - top)));
			if (dist < (param->ants_size / 2))
				mlx_pixel_put(param->mlx_ptr, param->win_ptr, \
						left, top, ant->color);
			++left;
		}
		++top;
	}
}
