/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:01:12 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/23 14:15:52 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

int		main(void)
{
	t_room	*lst;
	t_room	*start;
	t_path	*beg_path;

	beg_path = NULL;
	ft_parse_file(&lst);
	ft_lst_next_free(lst);
	if ((start = ft_start_room(lst)) != NULL)
		ft_final_print(start, &beg_path);
	else
		ft_putstr("ERROR\n");
	if (beg_path)
		ft_free_path(beg_path);
	if (lst)
		ft_free(lst);
	return (0);
}
