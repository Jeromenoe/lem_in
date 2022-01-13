/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:19:42 by trlevequ          #+#    #+#             */
/*   Updated: 2019/02/06 18:24:44 by jnoe             ###   ########.fr       */
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

void	ft_modif_path(t_room *stack, int value, t_room *real_stack)
{
	int		i;

	i = 0;
	while (!stack->end && stack->prev_real && stack->prev_real->path \
			&& !stack->prev_real->check)
	{
		stack->path = 0;
		stack = stack->prev_real;
		i++;
	}
	if (i != 0)
	{
		stack->value = stack->prev_real->value + 1;
		ft_stack_add_value(real_stack, stack, value);
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
				!stack->neighbors[i]->check && !(*end))
		{
			stack->neighbors[i]->check = 1;
			ft_add_prev_path(stack->neighbors[i], stack);
			ft_modif_path(stack->neighbors[i], value, stack);
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
		if (!ft_start_to_end(stack, i - 1, path))
			return (0);
		ft_reset(room);
		return (1);
	}
	return (0);
}
