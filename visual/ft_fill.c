/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:59:20 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/28 14:15:48 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	ft_fill_instruction(t_room *lst, int *start, int *end, int *ants)
{
	while (lst && lst->next)
		lst = lst->next;
	if (*start == 1)
	{
		lst->start = 1;
		lst->ants = *ants;
		*start = -1;
		*ants = 0;
	}
	if (*end == 1)
	{
		lst->end = 1;
		*end = -1;
	}
}

int		ft_parse_room(t_room **lst, char *str)
{
	int			i;
	char		*name;
	long long	x;
	long long	y;

	i = 0;
	while (str[i] != ' ')
		i++;
	name = ft_strndup(str, i);
	x = ft_atoi(str + i);
	i++;
	while (str[i] != ' ')
		i++;
	y = ft_atoi(str + i);
	if (!ft_room_is_ok(*lst, name, x, y))
	{
		free(name);
		return (0);
	}
	ft_lst_add(lst, name, x, y);
	return (1);
}

int		ft_parse_instruction(char *str, int *start, int *end)
{
	if (!(*start) && !ft_strcmp(str, "##start"))
		*start = 1;
	else if (!(*end) && !ft_strcmp(str, "##end"))
		*end = 1;
	else if (*start && !ft_strcmp(str, "##start"))
		return (0);
	else if (*end && !ft_strcmp(str, "##end"))
		return (0);
	return (1);
}

int		ft_parse(t_room **lst, char *str, int *i)
{
	static int	ants = 0;
	static int	start = 0;
	static int	end = 0;
	int			res;

	res = ft_check(*lst, str, i);
	if (res == 0)
		return (0);
	else if (res == 1)
		ants = ft_atoi(str);
	else if (res == 2)
	{
		if (!ft_parse_room(lst, str))
			return (0);
		ft_fill_instruction(*lst, &start, &end, &ants);
	}
	else if (start == 1 || end == 1)
		return (0);
	else if (res == 5)
		return (ft_parse_instruction(str, &start, &end));
	return (1);
}

void	ft_parse_file(t_room **lst)
{
	char	*str;
	int		i;
	int		stop;

	*lst = NULL;
	str = NULL;
	i = 1;
	stop = 0;
	while (get_next_line(0, &str) > 0)
	{
		if (!stop && ft_parse(lst, str, &i) == 0)
			stop = 1;
		ft_putendl(str);
		free(str);
	}
	ft_putstr("\n");
	free(str);
}
