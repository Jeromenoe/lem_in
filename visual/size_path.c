/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 09:17:05 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 09:35:32 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int			get_size_tube(t_param *param, t_ant ant)
{
	if ((abs(ant.arrival.x - ant.departure.x) \
				- abs(ant.arrival.y - ant.departure.y)) >= 0)
		return (abs(ant.arrival.x - ant.departure.x) / param->offset_distance);
	else
		return (abs(ant.arrival.y - ant.departure.y) / param->offset_distance);
}
