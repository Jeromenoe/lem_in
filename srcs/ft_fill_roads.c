/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_roads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:25:27 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/07 10:23:46 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_pos(t_room **stack)
{
	while (!(*stack)->end && !(*stack)->start &&
			(*stack)->prev_path[(*stack)->pos])
	{
		if ((*stack)->prev_path[(*stack)->pos]->check_path)
			(*stack)->pos = (*stack)->pos + 1;
		else
		{
			(*stack)->prev_path[(*stack)->pos]->next_path = (*stack);
			(*stack)->check_path = 1;
			(*stack)->path = 1;
			(*stack) = (*stack)->prev_path[(*stack)->pos];
			(*stack)->next_path->pos = (*stack)->next_path->pos + 1;
		}
	}
}

void	ft_back_path(t_room **stack)
{
	(*stack)->pos = 0;
	(*stack)->check_path = 0;
	(*stack)->path = 0;
	*stack = (*stack)->next_path;
}

int		ft_is_end(t_room **stack, t_room *beg_stack, int j)
{
	if ((*stack)->pos > j)
		return (0);
	*stack = beg_stack->prev_path[(*stack)->pos]->next_real;
	beg_stack->pos = beg_stack->pos + 1;
	return (1);
}

int		ft_is_start(t_room **stack, t_room *beg_stack, t_path *path)
{
	(*stack)->next_path->prev_real = (*stack);
	if (beg_stack->pos > 0)
		beg_stack->prev_path[beg_stack->pos - 1]->next_real =
			(*stack)->next_path;
	(*stack) = (*stack)->next_path;
	beg_stack->pos = beg_stack->pos - 1;
	if (beg_stack->pos < 0)
	{
		ft_fill_all_paths((*stack)->prev_real, path);
		return (1);
	}
	(*stack) = beg_stack->prev_path[beg_stack->pos];
	(*stack)->next_path = beg_stack;
	return (0);
}

int		ft_start_to_end(t_room *beg_stack, int j, t_path *path)
{
	t_room *stack;

	beg_stack->pos = j;
	stack = beg_stack->prev_path[beg_stack->pos];
	stack->next_path = beg_stack;
	while (beg_stack->pos >= 0)
	{
		ft_check_pos(&stack);
		if (!stack->start && !stack->end && !stack->prev_path[stack->pos])
			ft_back_path(&stack);
		if (stack->end)
			if (!ft_is_end(&stack, beg_stack, j))
				return (0);
		if (stack->start)
			if (ft_is_start(&stack, beg_stack, path))
				return (1);
	}
	return (1);
}
