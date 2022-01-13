/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:21:48 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 11:37:39 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "minilibx_macos/mlx.h"
#include "graph.h"

void	check_ant_position(t_param *param, int *i)
{
	int j;

	j = -1;
	while (param->ant[*i][++j])
	{
		if ((param->ant[*i][j]->position.x != param->ant[*i][j]->arrival.x) \
			|| (param->ant[*i][j]->position.y != param->ant[*i][j]->arrival.y))
			return ;
	}
	j = 0;
	if (param->ant[*i + 1])
	{
		usleep(300000);
		++(*i);
	}
	else
	{
		usleep(1000000);
		exit(84);
	}
}

void	print_stat(t_param *param, int i)
{
	int j;

	j = 0;
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1015, 20, \
			0xffffff, "Number of iterations:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1235, 20, \
			0xffffff, ft_itoa(i + 1));
	while (param->ant[i][j])
		++j;
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1015, 40, \
			0xffffff, "Number of ants on map:");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1245, 40, \
			0xffffff, ft_itoa(j));
}

int		manage_moves(t_param *param)
{
	static int	i = 0;
	clock_t		current_clock;
	int			j;

	j = -1;
	current_clock = clock();
	check_ant_position(param, &i);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, \
			param->img_ptr, 0, 0);
	print_stat(param, i);
	while (param->ant[i][++j])
		draw_ant(param, param->ant[i][j], current_clock);
	return (0);
}

int		lemin_visu(t_coor **rooms, t_tube **tubes, t_ant ***ants)
{
	t_param *param;

	if (!(param = init_param(rooms, tubes, ants)))
		return (0);
	mlx_loop_hook(param->mlx_ptr, manage_moves, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
