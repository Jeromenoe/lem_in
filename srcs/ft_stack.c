/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:20:05 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/06 13:27:56 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_init_stack(t_room *room, int *end, int *value)
{
	t_room	*stack;

	stack = room;
	*end = 0;
	*value = 0;
	stack->next = NULL;
	stack->prev = NULL;
	stack->check = 1;
	return (stack);
}

void	ft_stack_add(t_room *stack, t_room *room)
{
	while (stack->next)
		stack = stack->next;
	stack->next = room;
	stack->next->next = NULL;
}

void	ft_stack_add_value(t_room *stack, t_room *room, int value)
{
	(void)value;
	while (stack->next && room->value >= stack->next->value)
		stack = stack->next;
	room->next = stack->next;
	stack->next = room;
}

void	ft_stack_add_tmp(t_room *stack, t_room *room)
{
	while (stack->next_tmp)
		stack = stack->next_tmp;
	stack->next_tmp = room;
	stack->next_tmp->next_tmp = NULL;
}

t_room	*ft_fill_stack(t_room *stack, int *value, int *end)
{
	while (stack && !stack->end)
	{
		if (stack->next)
			stack->next->prev = stack;
		if (*value < stack->value)
			(*value)++;
		ft_neighbors_stack(stack, *value, end);
		stack = stack->next;
	}
	return (stack);
}
