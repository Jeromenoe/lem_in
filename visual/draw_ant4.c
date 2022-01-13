/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ant4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:41:28 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 14:01:49 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "graph.h"

static void	init_data(t_ant *ant, int *dp, int *delta_e, int *delta_ne)
{
	*dp = (2 * abs(ant->departure.x - ant->arrival.x)) \
			- abs(ant->arrival.y - ant->departure.y);
	*delta_e = 2 * abs(ant->departure.x - ant->arrival.x);
	*delta_ne = 2 * (abs(ant->departure.x - ant->arrival.x) \
			- abs(ant->arrival.y - ant->departure.y));
}

void		draw_ant_4(t_param *param, t_ant *ant, int x, int y)
{
	int dp;
	int delta_e;
	int delta_ne;

	init_data(ant, &dp, &delta_e, &delta_ne);
	while (y < ant->arrival.y)
	{
		if (y == (ant->position.y + param->offset_distance))
			break ;
		if (dp <= 0)
		{
			dp = dp + delta_e;
			y++;
		}
		else
		{
			dp = dp + delta_ne;
			x--;
			y++;
		}
	}
	ant->position.x = x;
	ant->position.y = y;
}

void		draw_ant_4_bis(t_param *param, t_ant *ant, int x, int y)
{
	int dp;
	int delta_e;
	int delta_ne;

	init_data(ant, &dp, &delta_e, &delta_ne);
	while (y > ant->arrival.y)
	{
		if (y == (ant->position.y - param->offset_distance))
			break ;
		if (dp <= 0)
		{
			dp = dp + delta_e;
			y--;
		}
		else
		{
			dp = dp + delta_ne;
			x--;
			y--;
		}
	}
	ant->position.x = x;
	ant->position.y = y;
}
