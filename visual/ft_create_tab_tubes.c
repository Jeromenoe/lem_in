/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creates_tab_tubes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:29:28 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 11:11:51 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "lem_in.h"
#include <stdlib.h>

int		ft_nb_tubes(t_room *beg_room)
{
	t_room	*room;
	int		count;
	int		i;

	count = 0;
	room = beg_room;
	while (room)
	{
		i = -1;
		while (room->neighbors[++i])
			count++;
		room = room->next;
	}
	return (count);
}

t_tube	*ft_create_tube(t_room *room1, t_room *room2)
{
	t_tube	*tube;

	if ((tube = (t_tube *)malloc(sizeof(t_tube))) == NULL)
		ft_exit_malloc();
	tube->pt_a.x = room1->x;
	tube->pt_a.y = room1->y;
	tube->pt_b.x = room2->x;
	tube->pt_b.y = room2->y;
	return (tube);
}

t_tube	**ft_create_tab_tubes(t_room *room)
{
	t_tube	**tab;
	int		i;
	int		j;

	if ((tab = (t_tube **)malloc(sizeof(t_tube*)
					* (ft_nb_tubes(room) + 1))) == NULL)
		ft_exit_malloc();
	j = -1;
	while (room)
	{
		i = -1;
		while (room->neighbors[++i])
			tab[++j] = ft_create_tube(room, room->neighbors[i]);
		room = room->next;
	}
	tab[++j] = NULL;
	return (tab);
}
