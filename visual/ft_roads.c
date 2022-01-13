/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:19:42 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/23 14:28:08 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

t_room	*ft_start_room(t_room *room)
{
	while (room)
	{
		if (room->start)
			return (room);
		room = room->next;
	}
	return (NULL);
}

void	ft_neighbors_stack_tmp(t_room *stack_tmp)
{
	int		i;

	i = -1;
	while (stack_tmp->neighbors[++i])
	{
		if (!stack_tmp->neighbors[i]->check && !stack_tmp->neighbors[i]->path)
		{
			stack_tmp->neighbors[i]->check = 1;
			ft_stack_add_tmp(stack_tmp, stack_tmp->neighbors[i]);
			ft_add_prev_path(stack_tmp->neighbors[i], stack_tmp);
			stack_tmp->neighbors[i]->value = stack_tmp->value + 1;
		}
	}
}

void	ft_modif_path(t_room *stack, int value)
{
	t_room	*stack_tmp;
	t_room	*tmp;

	while (stack->prev_path[0]->path)
	{
		stack = stack->prev_path[0];
		stack->path = 0;
	}
	stack_tmp = stack;
	stack_tmp->check = 1;
	stack_tmp->value = stack_tmp->prev_path[0]->value + 1;
	while (stack_tmp && !stack_tmp->end && stack_tmp->value <= value)
	{
		ft_neighbors_stack_tmp(stack_tmp);
		stack_tmp = stack_tmp->next_tmp;
	}
	while (stack_tmp)
	{
		ft_stack_add(stack, stack_tmp);
		tmp = stack_tmp;
		stack_tmp = stack_tmp->next;
		tmp->next = NULL;
	}
}

void	ft_neighbors_stack(t_room *stack, int value, int *end)
{
	int		i;

	i = -1;
	while (stack->neighbors[++i])
	{
		if (!stack->neighbors[i]->check && \
				!stack->neighbors[i]->path && !(*end))
		{
			stack->neighbors[i]->check = 1;
			ft_stack_add(stack, stack->neighbors[i]);
			ft_add_prev_path(stack->neighbors[i], stack);
			stack->neighbors[i]->value = stack->value + 1;
			if (stack->neighbors[i]->end)
				*end = 1;
		}
		else if (!stack->start && stack->neighbors[i]->path && \
				!stack->neighbors[i]->check)
		{
			stack->neighbors[i]->check = 1;
			ft_add_prev_path(stack->neighbors[i], stack);
			ft_modif_path(stack->neighbors[i], value);
		}
	}
}

int		ft_path(t_room *room, t_path **beg_path)
{
	t_room	*stack;
	t_path	*path;
	int		end;
	int		value;
	int		i;

	stack = ft_init_stack(room, &end, &value);
	stack = ft_fill_stack(stack, &value, &end);
	if (stack && stack->end)
	{
		i = 0;
		while (stack->prev_path[i])
			i++;
		path = ft_add_path(beg_path, i);
		ft_start_to_end(stack, i - 1, path);
		ft_reset(room);
		return (1);
	}
	return (0);
}
