/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tubes_in_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:00:43 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 11:25:53 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "minilibx_macos/mlx.h"

static void	get_tube_1(t_param *param, t_coor pta, t_coor ptb)
{
	int dp;
	int delta_e;
	int delta_ne;

	dp = (2 * (ptb.y - pta.y)) - (ptb.x - pta.x);
	delta_e = 2 * (ptb.y - pta.y);
	delta_ne = 2 * ((ptb.y - pta.y) - (ptb.x - pta.x));
	get_vertical_tube(param, pta.x, pta.y);
	while (pta.x < ptb.x)
	{
		if (dp <= 0)
		{
			dp = dp + delta_e;
			pta.x++;
		}
		else
		{
			dp = dp + delta_ne;
			pta.x++;
			pta.y++;
		}
		get_vertical_tube(param, pta.x, pta.y);
	}
}

static void	get_tube_2(t_param *param, t_coor pta, t_coor ptb)
{
	int dp;
	int delta_e;
	int delta_ne;

	dp = (2 * (ptb.x - pta.x)) - (ptb.y - pta.y);
	delta_e = 2 * (ptb.x - pta.x);
	delta_ne = 2 * ((ptb.x - pta.x) - (ptb.y - pta.y));
	get_horizontal_tube(param, pta.x, pta.y);
	while (pta.y < ptb.y)
	{
		if (dp <= 0)
		{
			dp = dp + delta_e;
			pta.y++;
		}
		else
		{
			dp = dp + delta_ne;
			pta.x++;
			pta.y++;
		}
		get_horizontal_tube(param, pta.x, pta.y);
	}
}

static void	get_tube_3(t_param *param, t_coor pta, t_coor ptb)
{
	int dp;
	int delta_e;
	int delta_ne;

	dp = (2 * (ptb.y - pta.y)) - (pta.x - ptb.x);
	delta_e = 2 * (ptb.y - pta.y);
	delta_ne = 2 * ((ptb.y - pta.y) - (pta.x - ptb.x));
	get_vertical_tube(param, pta.x, pta.y);
	while (pta.x > ptb.x)
	{
		if (dp <= 0)
		{
			dp = dp + delta_e;
			pta.x--;
		}
		else
		{
			dp = dp + delta_ne;
			pta.x--;
			pta.y++;
		}
		get_vertical_tube(param, pta.x, pta.y);
	}
}

static void	get_tube_4(t_param *param, t_coor pta, t_coor ptb)
{
	int dp;
	int delta_e;
	int delta_ne;

	dp = (2 * (pta.x - ptb.x)) - (ptb.y - pta.y);
	delta_e = 2 * (pta.x - ptb.x);
	delta_ne = 2 * ((pta.x - ptb.x) - (ptb.y - pta.y));
	get_horizontal_tube(param, pta.x, pta.y);
	while (pta.x > ptb.x)
	{
		if (dp <= 0)
		{
			dp = dp + delta_e;
			pta.y++;
		}
		else
		{
			dp = dp + delta_ne;
			pta.x--;
			pta.y++;
		}
		get_horizontal_tube(param, pta.x, pta.y);
	}
}

void		put_tube_in_tab(t_param *param, t_coor pt_h, t_coor pt_b)
{
	t_coor	tmp;

	if (pt_h.y < pt_b.y)
	{
		tmp = pt_h;
		pt_h = pt_b;
		pt_b = tmp;
	}
	if (pt_h.x >= pt_b.x)
	{
		if ((pt_h.x - pt_b.x) >= (pt_h.y - pt_b.y))
			get_tube_1(param, pt_b, pt_h);
		else
			get_tube_2(param, pt_b, pt_h);
	}
	else
	{
		if ((pt_b.x - pt_h.x) >= (pt_h.y - pt_b.y))
			get_tube_3(param, pt_b, pt_h);
		else
			get_tube_4(param, pt_b, pt_h);
	}
}
