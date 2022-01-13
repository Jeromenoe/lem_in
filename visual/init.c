/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 09:23:00 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 14:43:21 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "graph.h"

static void	init_map(t_param *param, t_coor **rooms, t_tube **tubes)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		if ((rooms[i]->x < 0 || rooms[i]->x > param->width) \
				|| (rooms[i]->y < 0 || rooms[i]->y > param->height))
			exit(0);
		++i;
	}
	i = 0;
	while (i < (param->height * param->width))
		param->img_str[i++] = param->background_color;
	i = 0;
	while (tubes[i])
	{
		put_tube_in_tab(param, tubes[i]->pt_a, tubes[i]->pt_b);
		++i;
	}
	i = 0;
	while (rooms[i])
	{
		put_room_in_tab(param, *(rooms[i]));
		++i;
	}
}

void		init_tab_color(int tab[5])
{
	tab[0] = 0xF32652;
	tab[1] = 0xBBAAEE;
	tab[2] = 0xFFFF66;
	tab[3] = 0x7FFFD4;
	tab[4] = 0xAAFFAA;
}

static void	init_clock(t_param *param)
{
	int i;
	int j;

	i = -1;
	while (param->ant[++i])
	{
		j = -1;
		while (param->ant[i][++j])
			param->ant[i][j]->clock = clock();
	}
	param->clock_size = clock();
}

static void	init_color(t_param *param)
{
	param->background_color = 0x111111;
	param->strong_grey = 0x666666;
	param->light_grey = 0x999999;
	param->start_room_color = 0xB4EEB4;
	param->end_room_color = 0xF69696;
	param->border_start = 0xB4EEB4;
	param->border_end = 0xF69696;
}

t_param		*init_param(t_coor **rooms, t_tube **tubes, t_ant ***ants)
{
	t_param *param;

	if ((param = (t_param *)malloc(sizeof(t_param))) == NULL)
		ft_exit_malloc();
	param->ant = ants;
	init_clock(param);
	param->width = 1300;
	param->height = 900;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->width, \
			param->height, "Lem-in");
	param->img_ptr = mlx_new_image(param->mlx_ptr, param->width, param->height);
	param->img_str = (int *)mlx_get_data_addr(param->img_ptr, \
			&(param->bits_per_pix), &(param->size_line), &(param->endian));
	param->room_size = 35.0;
	param->ants_size = 13.0;
	param->offset_distance = 7;
	init_color(param);
	init_map(param, rooms, tubes);
	return (param);
}
