/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:28:33 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 14:19:00 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "graph.h"

int			abs(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

static void	draw_ant_right(t_param *param, t_ant *ant)
{
	if ((abs(ant->arrival.x - ant->departure.x) \
				- abs(ant->arrival.y - ant->departure.y)) >= 0)
	{
		if (ant->arrival.y >= ant->departure.y)
			draw_ant_1(param, ant, ant->departure.x, ant->departure.y);
		else
			draw_ant_1_bis(param, ant, ant->departure.x, ant->departure.y);
	}
	else
	{
		if (ant->arrival.y >= ant->departure.y)
			draw_ant_2(param, ant, ant->departure.x, ant->departure.y);
		else
			draw_ant_2_bis(param, ant, ant->departure.x, ant->departure.y);
	}
}

static void	draw_ant_left(t_param *param, t_ant *ant)
{
	if ((abs(ant->arrival.x - ant->departure.x) \
				- abs(ant->arrival.y - ant->departure.y)) >= 0)
	{
		if (ant->arrival.y >= ant->departure.y)
			draw_ant_3(param, ant, ant->departure.x, ant->departure.y);
		else
			draw_ant_3_bis(param, ant, ant->departure.x, ant->departure.y);
	}
	else
	{
		if (ant->arrival.y >= ant->departure.y)
			draw_ant_4(param, ant, ant->departure.x, ant->departure.y);
		else
			draw_ant_4_bis(param, ant, ant->departure.x, ant->departure.y);
	}
}

void		draw_ant(t_param *param, t_ant *ant, clock_t current_clock)
{
	if ((current_clock - ant->clock) \
			< (clock_t)(200000 / get_size_tube(param, *ant)))
	{
		draw_ant_pixel(param, ant);
		return ;
	}
	if (ant->arrival.x >= ant->departure.x)
		draw_ant_right(param, ant);
	else
		draw_ant_left(param, ant);
	ant->clock = clock();
	draw_ant_pixel(param, ant);
}
