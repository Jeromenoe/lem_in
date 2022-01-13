/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:23:43 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/28 14:16:00 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_room_is_ok(t_room *lst, char *name, long long x, long long y)
{
	if (x > 2147483647 || x < -2147483648 || y > 2147483647 || y < -2147483648)
		return (0);
	while (lst)
	{
		if (ft_strcmp(name, lst->name) == 0)
			return (0);
		if (x == lst->x && y == lst->y)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		ft_check(t_room *lst, char *str, int *i)
{
	if (ft_check_comment(str))
		return (4);
	if (*i == 1)
	{
		if (ft_check_ant(str))
		{
			(*i)++;
			return (1);
		}
		return (0);
	}
	if (*i == 2)
	{
		if (ft_check_instruction(str))
			return (5);
		if (ft_check_room(str))
			return (2);
		else
			(*i)++;
	}
	if (*i == 3)
		if (ft_check_tube(lst, str))
			return (3);
	return (0);
}
