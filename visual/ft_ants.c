/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:36:43 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 11:09:14 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void			ft_fill_path_nb_ants(t_path *path)
{
	int		i;
	int		rest;

	if ((path->nb_ants = (int *)malloc(sizeof(int) *
					(path->nb_path + 1))) == NULL)
		ft_exit_malloc();
	path->nb_ants[path->nb_path] = 0;
	i = -1;
	while (++i < path->nb_path)
	{
		if ((path->mod)-- > 0)
			rest = 1;
		else
			rest = 0;
		path->nb_ants[i] = path->sum + rest - path->len[i];
	}
}

unsigned int	**ft_init_tab(int len, t_path *path)
{
	unsigned int	**tab_len;
	int				i;
	int				j;

	if ((tab_len = (unsigned int **)malloc(sizeof(unsigned int *)
					* (len + 1))) == NULL)
		ft_exit_malloc();
	tab_len[len] = NULL;
	i = -1;
	while (++i < len)
	{
		if ((tab_len[i] = (unsigned int *)malloc(sizeof(unsigned int) \
				* (path->len[i] + 2))) == NULL)
			ft_exit_malloc();
		j = -1;
		while (++j < path->len[i] + 2)
			tab_len[i][j] = 0;
	}
	return (tab_len);
}

void			ft_move_ants(t_path *path, int i)
{
	int		j;

	j = path->len[i] + 1;
	while (--j >= 0)
		path->tab_print[i][j + 1] = path->tab_print[i][j];
	path->tab_print[i][0] = 0;
}

int				ft_check_tab_ants(t_path *path)
{
	int		i;
	int		j;

	i = -1;
	while (++i < path->nb_path)
	{
		j = -1;
		while (++j < path->len[i] + 2)
			if (path->tab_print[i][j])
				return (1);
	}
	return (0);
}
