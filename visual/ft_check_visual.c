/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_visual.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:53:24 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 15:00:56 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph.h"

int		ft_check_visual(t_room *room)
{
	int start;
	int end;

	start = 0;
	end = 0;
	while (room)
	{
		if (room->end == 1)
		{
			if (end)
				return (0);
			end = 1;
		}
		if (room->start == 1)
		{
			if (start)
				return (0);
			start = 1;
		}
		room = room->next;
	}
	if (start && end)
		return (1);
	return (0);
}
