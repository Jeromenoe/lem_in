/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:59:31 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/23 13:58:43 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	ft_free(t_room *lst)
{
	t_room *tmp;

	while (lst)
	{
		free(lst->neighbors);
		free(lst->prev_path);
		free(lst->name);
		tmp = lst;
		lst = lst->next_free;
		free(tmp);
	}
}

void	ft_free_tab(t_path *path)
{
	int i;
	int j;

	i = -1;
	while (path->tab[++i])
	{
		j = -1;
		while (path->tab[i][++j])
			free(path->tab[i][j]);
		free(path->tab[i]);
	}
	free(path->tab);
}

void	ft_free_path(t_path *path)
{
	t_path	*tmp;
	int		i;

	while (path)
	{
		tmp = path;
		if (path->nb_ants)
			free(path->nb_ants);
		ft_free_tab(path);
		if (path->len)
			free(path->len);
		if (path->tab_print)
		{
			i = -1;
			while (path->tab_print[++i])
				free(path->tab_print[i]);
			free(path->tab_print);
		}
		path = path->next;
		free(tmp);
	}
}

void	ft_lst_next_free(t_room *lst)
{
	while (lst)
	{
		lst->next_free = lst->next;
		lst = lst->next;
	}
}
