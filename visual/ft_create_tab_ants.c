/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:25:15 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 11:10:14 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"
#include <stdio.h>

t_ant	*ft_create_ant(char *str, int n)
{
	int		i;
	int		j;
	t_ant	*ant;

	if ((ant = (t_ant *)malloc(sizeof(t_ant))) == NULL)
		ft_exit_malloc();
	j = -1;
	i = 0;
	while (++j < n)
	{
		while (str[i] && str[i] != ' ')
			i++;
		i++;
	}
	ant->num = ft_atoi(&str[i + 1]);
	while (str[i] && str[i] != '-')
		i++;
	j = 0;
	while (str[++i] && str[i] != ' ')
		j++;
	ant->room_name = ft_strndup(&str[i - j], j);
	return (ant);
}

t_ant	**ft_alloc_tab_ant(char *str)
{
	int		i;
	int		count;
	t_ant	**tab;

	count = 1;
	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			count++;
	if ((tab = (t_ant **)malloc(sizeof(t_ant *) * (count + 1))) == NULL)
		ft_exit_malloc();
	i = -1;
	while (++i < count)
		tab[i] = ft_create_ant(str, i);
	tab[i] = NULL;
	return (tab);
}

t_room	*ft_find_room_prev(t_ant ***tab, int i, int j, t_room *room)
{
	int num;
	int l;

	l = j;
	num = tab[i][j]->num;
	j = 0;
	while (tab[i - 1][j] && tab[i - 1][j]->num != num)
		j++;
	if (tab[i - 1][j])
	{
		tab[i][l]->color = tab[i - 1][j]->color;
		return (ft_find_room(tab[i - 1][j]->room_name, room));
	}
	return (NULL);
}

t_room	*ft_find_room(char *name, t_room *room)
{
	while (room && ft_strcmp(room->name, name))
		room = room->next;
	return (room);
}

t_ant	***ft_create_tab_ants(char *str, t_room *room, t_room *start)
{
	int		i;
	int		count;
	int		tab_color[5];
	t_ant	***tab;

	init_tab_color(tab_color);
	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			count++;
	if ((tab = (t_ant ***)malloc(sizeof(t_ant **) * (count + 1))) == NULL)
		ft_exit_malloc();
	ft_fill_tab_ants(tab, count, str);
	ft_fill_prev_room(tab, room, start, tab_color);
	ft_fill_position(tab);
	return (tab);
}
