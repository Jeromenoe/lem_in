/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:59:41 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/05 15:37:06 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_init_lst_value(t_room *lst)
{
	lst->start = 0;
	lst->end = 0;
	lst->ants = 0;
	lst->check = 0;
	lst->path = 0;
	lst->reset = 0;
	lst->check_path = 0;
	lst->value = 0;
	lst->next_real = NULL;
	lst->prev_real = NULL;
	lst->pos = 0;
}

t_room	*ft_lst_create(char *name, int x, int y)
{
	t_room	*lst;

	if ((lst = (t_room *)malloc(sizeof(t_room))) == NULL)
		ft_exit_malloc();
	if ((lst->neighbors = (t_room **)malloc(sizeof(t_room *))) == NULL)
		ft_exit_malloc();
	lst->neighbors[0] = NULL;
	if ((lst->prev_path = (t_room **)malloc(sizeof(t_room *))) == NULL)
		ft_exit_malloc();
	lst->prev_path[0] = NULL;
	ft_init_lst_value(lst);
	lst->name = name;
	lst->x = x;
	lst->y = y;
	lst->next = NULL;
	lst->next_path = NULL;
	lst->next_tmp = NULL;
	return (lst);
}

void	ft_lst_add(t_room **beg_lst, char *name, int x, int y)
{
	t_room	*lst;

	if (!beg_lst)
		return ;
	lst = *beg_lst;
	while (lst && lst->next)
		lst = lst->next;
	if (!lst)
		*beg_lst = ft_lst_create(name, x, y);
	else
		lst->next = ft_lst_create(name, x, y);
}

void	ft_add_neighbor(t_room *lst1, t_room *lst2)
{
	int		i;
	t_room	**tab;

	i = 0;
	while (lst1->neighbors[i])
	{
		if (lst1->neighbors[i] == lst2)
			return ;
		i++;
	}
	if ((tab = (t_room **)malloc(sizeof(t_room *) * (i + 2))) == NULL)
		ft_exit_malloc();
	i = -1;
	while (lst1->neighbors[++i])
		tab[i] = lst1->neighbors[i];
	tab[i] = lst2;
	tab[i + 1] = NULL;
	free(lst1->neighbors);
	lst1->neighbors = tab;
}

void	ft_add_prev_path(t_room *lst1, t_room *lst2)
{
	int		i;
	t_room	**tab;

	i = 0;
	while (lst1->prev_path[i])
	{
		if (lst1->prev_path[i] == lst2)
			return ;
		i++;
	}
	if ((tab = (t_room **)malloc(sizeof(t_room *) * (i + 2))) == NULL)
		ft_exit_malloc();
	i = -1;
	while (lst1->prev_path[++i])
		tab[i] = lst1->prev_path[i];
	tab[i] = lst2;
	tab[i + 1] = NULL;
	free(lst1->prev_path);
	lst1->prev_path = tab;
}
