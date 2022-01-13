/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:00:55 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/06 13:28:27 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	ft_print_ants_start_end(t_room *start, int ants)
{
	int		i;
	t_room	*end;

	i = -1;
	while (start->neighbors[++i])
	{
		if (start->neighbors[i]->end)
			end = start->neighbors[i];
	}
	i = 0;
	while (++i <= ants)
	{
		if (i > 1)
			ft_putstr(" ");
		ft_putstr("L");
		ft_putnbr(i);
		ft_putstr("-");
		ft_putstr(end->name);
	}
	ft_putstr("\n");
}

void	ft_print_ants_path(t_path *path, int i, int *space)
{
	int j;

	ft_move_ants(path, i);
	j = path->len[i] + 2;
	while (--j >= 0)
	{
		if (path->tab_print[i][j])
		{
			if (*space)
				ft_putstr(" ");
			*space = 1;
			ft_putstr("L");
			ft_putnbr(path->tab_print[i][j]);
			ft_putstr("-");
			ft_putstr(path->tab[i][j]);
		}
	}
}

void	ft_print_ants(t_path *path)
{
	int				i;
	unsigned int	nb;
	int				first;
	int				space;

	first = 1;
	path->tab_print = ft_init_tab(path->nb_path, path);
	nb = 1;
	while (first || ft_check_tab_ants(path))
	{
		first = 0;
		i = -1;
		space = 0;
		while (++i < path->nb_path)
		{
			if ((path->nb_ants[i])-- > 0)
				path->tab_print[i][0] = nb++;
			else
				path->tab_print[i][0] = 0;
			ft_print_ants_path(path, i, &space);
		}
		if (ft_check_tab_ants(path))
			ft_putstr("\n");
	}
}

void	ft_final_print(t_room *start, t_path **beg_path)
{
	t_path *path;

	if (ft_start_neighbor_end(start))
	{
		ft_fill_path_ants(start, beg_path);
		path = *beg_path;
		while (path && path->next && path->next->sum > path->next->max)
			path = path->next;
		if (path)
		{
			ft_fill_path_nb_ants(path);
			ft_print_ants(path);
		}
		else
			ft_putstr("ERROR\n");
	}
	else
		ft_print_ants_start_end(start, start->ants);
}
