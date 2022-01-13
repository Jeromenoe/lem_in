/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:52:44 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 10:49:09 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

void	ft_fill_start_room(t_ant ***tab, t_room *beg_room, t_room *start,
		int tab_color[5])
{
	int		i;
	t_room	*room1;

	i = -1;
	while (tab[0][++i])
	{
		room1 = ft_find_room(tab[0][i]->room_name, beg_room);
		ft_fill_coor(tab[0][i], room1, start);
		tab[0][i]->color = tab_color[0];
	}
}

void	ft_fill_coor(t_ant *tab, t_room *room, t_room *room_prev)
{
	tab->departure.x = room_prev->x;
	tab->departure.y = room_prev->y;
	tab->arrival.x = room->x;
	tab->arrival.y = room->y;
}

void	ft_fill_prev_room(t_ant ***tab, t_room *beg_room, t_room *start,
		int tab_color[5])
{
	int		i;
	int		j;
	t_room	*room1;
	t_room	*room2;

	ft_fill_start_room(tab, beg_room, start, tab_color);
	i = 0;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			room1 = ft_find_room_prev(tab, i, j, beg_room);
			if (!room1)
				room1 = start;
			room2 = ft_find_room(tab[i][j]->room_name, beg_room);
			ft_fill_coor(tab[i][j], room2, room1);
			if (room1 == start)
				tab[i][j]->color = tab_color[i % 5];
		}
	}
}

void	ft_fill_position(t_ant ***tab)
{
	int i;
	int j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			tab[i][j]->position.x = tab[i][j]->departure.x;
			tab[i][j]->position.y = tab[i][j]->departure.y;
		}
	}
}

void	ft_fill_tab_ants(t_ant ***tab, int count, char *str)
{
	int		i;
	int		j;
	int		l;
	char	*s;

	i = -1;
	j = -1;
	while (++i < count)
	{
		l = 0;
		j++;
		while (str[j] != '\n')
		{
			j++;
			l++;
		}
		s = ft_strndup(str + j - l, l);
		tab[i] = ft_alloc_tab_ant(s);
		free(s);
	}
	tab[i] = NULL;
}
