/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:14:35 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 11:12:41 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_fill_path(t_room *beg_lst, t_path *path, int j)
{
	int		i;
	t_room	*lst;

	lst = beg_lst;
	i = 0;
	while (lst && !lst->end)
	{
		i++;
		lst = lst->next_path;
	}
	if ((path->tab[j] = (char **)malloc(sizeof(char *) * (i + 2))) == NULL)
		ft_exit_malloc();
	path->len[j] = i - 1;
	lst = beg_lst;
	i = 0;
	while (lst && !lst->end)
	{
		if ((path->tab[j][i] = ft_strdup(lst->name)) == NULL)
			ft_exit_malloc();
		i++;
		lst = lst->next_path;
	}
	if ((path->tab[j][i++] = ft_strdup(lst->name)) == NULL)
		ft_exit_malloc();
	path->tab[j][i] = NULL;
}

void	ft_fill_path_ants(t_room *start, t_path **beg_path)
{
	int		i;
	t_path	*path;

	i = 1;
	while (ft_path(start, beg_path))
	{
		path = *beg_path;
		while (path && path->next)
			path = path->next;
		path->sum = (start->ants + ft_sum_path(path->len)) / path->nb_path;
		path->mod = (start->ants + ft_sum_path(path->len)) % path->nb_path;
		path->max = ft_max_path(path->len);
		if (path->sum <= path->max)
			break ;
		i++;
	}
}
