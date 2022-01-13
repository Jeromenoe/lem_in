/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab_rooms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:01:59 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 11:11:03 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "lem_in.h"

t_coor	*ft_create_room(int x, int y, int start, int end)
{
	t_coor	*room;

	if ((room = (t_coor *)malloc(sizeof(t_coor))) == NULL)
		ft_exit_malloc();
	room->x = x;
	room->y = y;
	room->start = start;
	room->end = end;
	return (room);
}

t_coor	**ft_create_tab_rooms(t_room *beg_room)
{
	t_coor	**tab;
	t_room	*room;
	int		i;
	int		len;

	room = beg_room;
	len = 0;
	while (room)
	{
		len++;
		room = room->next;
	}
	if ((tab = (t_coor **)malloc(sizeof(t_coor *) * (len + 1))) == NULL)
		ft_exit_malloc();
	room = beg_room;
	i = -1;
	while (++i < len)
	{
		tab[i] = ft_create_room(room->x, room->y, room->start, room->end);
		room = room->next;
	}
	tab[i] = NULL;
	return (tab);
}
