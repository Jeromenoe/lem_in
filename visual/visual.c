/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:12:08 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/07 11:19:22 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void	ft_str_join(char **s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if ((new = (char *)malloc(sizeof(char) *
					(ft_strlen(*s1) + ft_strlen(s2) + 2))) == NULL)
		ft_exit_malloc();
	i = -1;
	while ((*s1)[++i])
		new[i] = (*s1)[i];
	j = -1;
	while (s2[++j])
		new[i++] = s2[j];
	new[i++] = '\n';
	new[i] = '\0';
	free(*s1);
	*s1 = new;
}

char	*ft_str_input(t_room **lst)
{
	char	*s1;
	char	*line;
	int		stop;
	int		i;

	i = 1;
	stop = 0;
	s1 = NULL;
	s1 = ft_strdup("");
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!stop && ft_parse(lst, line, &i) == 0)
			stop = 1;
		ft_str_join(&s1, line);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	return (s1);
}

int		ft_invalid_map(char *str)
{
	int len;

	len = ft_strlen(str) - 2;
	while (len >= 0 && str[len] != '\n')
		len--;
	if (!ft_strcmp(str + len + 1, "ERROR\n"))
		return (0);
	return (1);
}

void	ft_str_ants_moves(char **str)
{
	char	*new;
	int		len;

	len = ft_strlen(*str) - 2;
	while (len > 0 && ((*str)[len] != '\n' || (*str)[len - 1] != '\n'))
		len--;
	if ((new = ft_strdup(*str + len + 1)) == NULL)
		ft_exit_malloc();
	free(*str);
	*str = new;
}

int		main(void)
{
	t_room	*room;
	t_coor	**tab_room;
	t_tube	**tab_tube;
	t_ant	***tab_ant;
	char	*s1;

	room = NULL;
	s1 = ft_str_input(&room);
	ft_lst_next_free(room);
	if (!ft_check_visual(room))
		ft_exit(&s1);
	if (!(ft_start_room(room))->ants)
		ft_exit(&s1);
	if (!ft_invalid_map(s1))
		ft_exit(&s1);
	else
		ft_str_ants_moves(&s1);
	tab_room = ft_create_tab_rooms(room);
	tab_tube = ft_create_tab_tubes(room);
	tab_ant = ft_create_tab_ants(s1, room, ft_start_room(room));
	lemin_visu(tab_room, tab_tube, tab_ant);
	return (0);
}
