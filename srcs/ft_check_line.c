/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:58:57 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/22 16:26:22 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		ft_check_comment(char *str)
{
	if (str[0] == '#')
		if (str[1] != '#')
			return (1);
	return (0);
}

int		ft_check_instruction(char *str)
{
	if (str[0] == '#')
		if (str[1] == '#')
			return (1);
	return (0);
}

int		ft_check_ant(char *str)
{
	int			i;
	long long	nb_ants;

	if (!str[0])
		return (0);
	i = -1;
	if (str[0] == '+' && str[1] >= '0' && str[1] <= '9')
		i++;
	while (str[++i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
	}
	nb_ants = ft_atoi(str);
	if (nb_ants > 4294967295)
		return (0);
	return (1);
}

int		ft_check_room(char *str)
{
	int i;
	int j;

	j = -1;
	i = 0;
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[i] && str[i] != ' ')
		i++;
	if (!str[i])
		return (0);
	while (++j < 2)
	{
		i = (str[i + 1] == '-' || str[i + 1] == '+') ? i + 1 : i;
		while (str[++i] && str[i] != ' ')
		{
			if (str[i] > '9' || str[i] < '0')
				return (0);
		}
		if (!str[i] && j < 1)
			return (0);
	}
	if (!str[i])
		return (1);
	return (0);
}

int		ft_check_tube(t_room *lst, char *str)
{
	t_room *lst1;
	t_room *lst2;

	lst1 = lst;
	while (lst1)
	{
		if (!ft_strncmp(str, lst1->name, ft_strlen(lst1->name))
				&& str[ft_strlen(lst1->name)] == '-')
		{
			lst2 = lst;
			while (lst2)
			{
				if (lst1 != lst2 && !ft_strcmp(str +
							ft_strlen(lst1->name) + 1, lst2->name))
				{
					ft_add_neighbor(lst1, lst2);
					ft_add_neighbor(lst2, lst1);
					return (1);
				}
				lst2 = lst2->next;
			}
		}
		lst1 = lst1->next;
	}
	return (0);
}
