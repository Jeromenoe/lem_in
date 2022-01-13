/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:18:08 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/23 14:19:05 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_reset_all(t_room *stack)
{
	while (stack)
	{
		stack->check = 0;
		stack->check_path = 0;
		stack->value = 0;
		stack->reset = 0;
		stack = stack->next;
	}
}

void	ft_reset(t_room *beg)
{
	t_room	*stack;
	int		i;

	stack = beg;
	stack->next = NULL;
	stack->reset = 1;
	while (stack)
	{
		i = -1;
		while (stack->neighbors[++i])
		{
			if (!stack->neighbors[i]->reset)
			{
				ft_stack_add(stack, stack->neighbors[i]);
				stack->neighbors[i]->reset = 1;
			}
		}
		stack = stack->next;
	}
	ft_reset_all(beg);
}
