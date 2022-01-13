/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ant1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:31:23 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 14:03:06 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "graph.h"

static void	init_data(t_ant *ant, int *dp, int *delta_e, int *delta_ne)
{
	*dp = (2 * abs(ant->arrival.y - ant->departure.y)) \
			- abs(ant->arrival.x - ant->departure.x);
	*delta_e = 2 * abs(ant->arrival.y - ant->departure.y);
	*delta_ne = 2 * (abs(ant->arrival.y - ant->departure.y) \
			- abs(ant->arrival.x - ant->departure.x));
}

void		draw_ant_1(t_param *param, t_ant *ant, int x, int y)
{
	int dp;
	int delta_e;
	int delta_ne;

	init_data(ant, &dp, &delta_e, &delta_ne);
	while (x < ant->arrival.x)
	{
		if (x == (ant->position.x + param->offset_distance))
			break ;
		if (dp <= 0)
		{
			dp = dp + delta_e;
			x++;
		}
		else
		{
			dp = dp + delta_ne;
			x++;
			y++;
		}
	}
	ant->position.x = x;
	ant->position.y = y;
}

void		draw_ant_1_bis(t_param *param, t_ant *ant, int x, int y)
{
	int dp;
	int delta_e;
	int delta_ne;

	init_data(ant, &dp, &delta_e, &delta_ne);
	while (x < ant->arrival.x)
	{
		if (x == (ant->position.x + param->offset_distance))
			break ;
		if (dp <= 0)
		{
			dp = dp + delta_e;
			x++;
		}
		else
		{
			dp = dp + delta_ne;
			x++;
			y--;
		}
	}
	ant->position.x = x;
	ant->position.y = y;
}
