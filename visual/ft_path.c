/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:33:14 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 11:18:51 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

t_path	*ft_create_path(int len)
{
	t_path	*path;
	char	***tab;
	int		*tab_len;

	if ((path = (t_path *)malloc(sizeof(t_path))) == NULL)
		ft_exit_malloc();
	if ((tab = (char ***)malloc(sizeof(**tab) * (len + 1))) == NULL)
		ft_exit_malloc();
	tab[len] = NULL;
	if ((tab_len = (int *)malloc(sizeof(int) * (len + 1))) == NULL)
		ft_exit_malloc();
	tab_len[len] = 0;
	path->tab = tab;
	path->len = tab_len;
	path->nb_ants = NULL;
	path->tab_print = NULL;
	path->nb_path = len;
	path->next = NULL;
	return (path);
}

t_path	*ft_add_path(t_path **beg_path, int len)
{
	t_path *path;

	path = *beg_path;
	while (path && path->next)
		path = path->next;
	if (!*beg_path)
	{
		*beg_path = ft_create_path(len);
		return (*beg_path);
	}
	else
		path->next = ft_create_path(len);
	return (path->next);
}

int		ft_sum_path(int *len)
{
	int		i;
	int		s;

	s = 0;
	i = -1;
	while (len[++i])
		s += len[i];
	return (s);
}

int		ft_max_path(int *len)
{
	int		i;
	int		max;

	max = len[0];
	i = -1;
	while (len[++i])
	{
		if (len[i] > max)
			max = len[i];
	}
	return (max);
}
