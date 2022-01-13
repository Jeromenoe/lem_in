/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_roads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:24:26 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/06 13:25:23 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_tail_path(t_room *stack, int i)
{
	while (stack->prev_path[i] && !stack->end && \
			stack->prev_path[i]->check_path)
	{
		i++;
		if (!stack->prev_path[i])
		{
			i--;
			break ;
		}
	}
	if (!stack->start && !stack->end)
	{
		stack->path = 1;
		stack->check_path = 1;
	}
	return (i);
}

int		ft_start_to_end(t_room *beg_stack, int j, t_path *path)
{
	t_room	*stack;
	int		i;

	i = j;
	stack = beg_stack;
	stack->next_path = NULL;
	while (stack && !stack->start)
	{
		i = ft_tail_path(stack, i);
		stack->check = 0;
		stack->prev_path[i]->next_path = stack;
		stack = stack->prev_path[i];
		i = 0;
	}
	ft_fill_path(stack, path, j);
	if (j > 0)
		ft_start_to_end(beg_stack, j - 1, path);
	return (1);
}

int		ft_start_neighbor_end(t_room *stack)
{
	int		i;

	i = -1;
	while (stack->neighbors[++i])
		if (stack->neighbors[i]->end)
			return (0);
	return (1);
}
