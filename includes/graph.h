/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:17:37 by trlevequ          #+#    #+#             */
/*   Updated: 2019/01/30 15:01:24 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <time.h>
# include "lem_in.h"

typedef struct		s_coor
{
	int				x;
	int				y;
	int				start;
	int				end;
}					t_coor;

typedef struct		s_tube
{
	t_coor			pt_a;
	t_coor			pt_b;
}					t_tube;

typedef struct		s_ant
{
	int				num;
	char			*room_name;
	t_coor			departure;
	t_coor			arrival;
	t_coor			position;
	int				color;
	clock_t			clock;
}					t_ant;

typedef struct		s_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_str;
	int				*img_str2;
	int				width;
	int				height;
	int				bits_per_pix;
	int				size_line;
	int				endian;
	double			room_size;
	double			ants_size;
	int				background_color;
	int				strong_grey;
	int				light_grey;
	int				start_room_color;
	int				end_room_color;
	int				border_start;
	int				border_end;
	clock_t			clock_size;
	int				offset_distance;
	t_ant			***ant;
}					t_param;

t_coor				*ft_create_room(int x, int y, int start, int end);
t_coor				**ft_create_tab_rooms(t_room *beg_room);
void				ft_print_tab_rooms(t_coor **tab);

int					ft_check_visual(t_room *room);

int					ft_nb_tubes(t_room *beg_room);
t_tube				**ft_create_tab_tubes(t_room *room);
void				ft_print_tab_tubes(t_tube **tube);

t_ant				*ft_create_ant(char *str, int n);
t_ant				**ft_alloc_tab_ant(char *str);
void				ft_fill_prev_room(t_ant ***tab, t_room *beg_room,
					t_room *start, int tab_color[5]);
t_room				*ft_find_room(char *name, t_room *room);
t_ant				***ft_create_tab_ants(char *str, t_room *room,
					t_room *start);

void				ft_print_tab_ants(t_ant ***tab);
void				ft_fill_coor(t_ant *tab, t_room *room, t_room *room_prev);
t_room				*ft_find_room_prev(t_ant ***tab, int i, int j,
					t_room *room);
void				ft_fill_position(t_ant ***tab);
void				ft_fill_tab_ants(t_ant ***tab, int count, char *str);

int					lemin_visu(t_coor **rooms, t_tube **tubes, t_ant ***ants);
void				put_tube_in_tab(t_param *param, t_coor pt_h, t_coor pt_b);
void				put_room_in_tab(t_param *param, t_coor pnt);
void				draw_ant(t_param *param, t_ant *ant, clock_t current_clock);
void				draw_ant_pixel(t_param *param, t_ant *ant);
int					get_size_tube(t_param *param, t_ant ant);
int					abs(int nb);
t_param				*init_param(t_coor **rooms, t_tube **tubes, t_ant ***ants);
void				init_tab_color(int tab[5]);

void				draw_ant_1(t_param *param, t_ant *ant, int x, int y);
void				draw_ant_1_bis(t_param *param, t_ant *ant, int x, int y);
void				draw_ant_2(t_param *param, t_ant *ant, int x, int y);
void				draw_ant_2_bis(t_param *param, t_ant *ant, int x, int y);
void				draw_ant_3(t_param *param, t_ant *ant, int x, int y);
void				draw_ant_3_bis(t_param *param, t_ant *ant, int x, int y);
void				draw_ant_4(t_param *param, t_ant *ant, int x, int y);
void				draw_ant_4_bis(t_param *param, t_ant *ant, int x, int y);

void				get_vertical_tube(t_param *param, int x, int y);
void				get_horizontal_tube(t_param *param, int x, int y);

#endif
