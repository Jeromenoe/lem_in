/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:23:05 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/07 10:23:45 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_start_neighbor_end(t_room *stack)
{
	int		i;

	i = -1;
	while (stack->neighbors[++i])
		if (stack->neighbors[i]->end)
			return (0);
	return (1);
}
