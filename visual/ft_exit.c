/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:55:06 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/30 14:14:28 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void	ft_exit(char **str)
{
	if (*str)
		free(*str);
	ft_putstr("Input is not valid\n");
	exit(0);
}

void	ft_exit_malloc(void)
{
	ft_putstr("Allocation memory issue\n");
	exit(0);
}
