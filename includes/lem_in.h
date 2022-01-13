/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:24:12 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/07 11:23:17 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				ants;
	int				x;
	int				y;
	int				value;
	int				check;
	int				path;
	int				reset;
	int				check_path;
	struct s_room	**neighbors;
	struct s_room	*next;
	struct s_room	*next_tmp;
	struct s_room	*next_free;
	struct s_room	*next_path;
	struct s_room	*prev;
	struct s_room	**prev_path;
	struct s_room	*prev_real;
	struct s_room	*next_real;
	int				pos;
}					t_room;

typedef struct		s_path
{
	char			***tab;
	unsigned int	**tab_print;
	int				*len;
	int				*nb_ants;
	int				nb_path;
	int				sum;
	int				mod;
	int				max;
	struct s_path	*next;
}					t_path;

int					ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, int n);
void				ft_putstr(char *str);
void				ft_putnbr(unsigned int n);
void				ft_putendl(char const *str);
char				*ft_strndup(char *str, int n);
char				*ft_strdup(char *str);
long long			ft_atoi(char *str);
int					get_next_line(const int fd, char **line);
char				*ft_itoa(int nb);

int					ft_check_comment(char *str);
int					ft_check_instruction(char *str);
int					ft_check_ant(char *str);
int					ft_check_room(char *str);
int					ft_room_is_ok(t_room *lst, char *name,
					long long x, long long y);
int					ft_check_tube(t_room *lst, char *str);
int					ft_check(t_room *lst, char *str, int *i);

int					ft_parse_room(t_room **lst, char *str);
int					ft_parse(t_room **lst, char *str, int *i);
void				ft_parse_file(t_room **lst);

t_room				*ft_lst_create(char *name, int x, int y);
void				ft_lst_add(t_room **beg_lst, char *name, int x, int y);
void				ft_add_neighbor(t_room *lst1, t_room *lst2);
void				ft_add_prev_path(t_room *lst1, t_room *lst2);

void				ft_print_rooms(t_room *lst);
void				ft_print_neighbors(t_room *lst);
void				ft_print_tab(t_room **tab);
void				ft_print_path(t_room *lst);

void				ft_move_ants(t_path *path, int i);
int					ft_check_tab_ants(t_path *path);

void				ft_print_path_tab(char ***tab, int *len);
int					ft_sum_path(int *len);
int					ft_max_path(int *len);
void				ft_fill_path_nb_ants(t_path *path);
t_path				*ft_create_path(int len);
t_path				*ft_add_path(t_path **beg_path, int len);
unsigned int		**ft_init_tab(int len, t_path *path);

void				ft_print_ants(t_path *path);
void				ft_print_ants_start_end(t_room *start, int ants);
void				ft_final_print(t_room *start, t_path **beg_path);

void				ft_fill_path(t_room *lst, t_path *path, int j);
void				ft_fill_path_ants(t_room *start, t_path **beg_path);

void				ft_free(t_room *lst);
void				ft_free_path(t_path *path);
void				ft_lst_next_free(t_room *lst);

int					ft_lst_len(t_room *lst);
t_room				*ft_room_start(t_room *lst);
t_room				*ft_room_end(t_room *lst);
int					ft_nb_ants(t_room *lst);

void				ft_fill_path(t_room *beg_lst, t_path *path, int j);
void				ft_fill_all_paths(t_room *stack, t_path *path);
void				ft_fill_path_ants(t_room *start, t_path **beg_path);

int					ft_path(t_room *room, t_path **beg_path);
t_room				*ft_start_room(t_room *room);
int					ft_start_neighbor_end(t_room *stack);

t_room				*ft_init_stack(t_room *room, int *end, int *value);
void				ft_stack_add(t_room *stack, t_room *room);
void				ft_stack_add_tmp(t_room *stack, t_room *room);
void				ft_stack_add_value(t_room *stack, t_room *room, int value);
t_room				*ft_fill_stack(t_room *stack, int *value, int *end);

int					ft_tail_path(t_room *stack, int i);
int					ft_start_to_end(t_room *beg_stack, int j, t_path *path);
int					ft_start_neighbor_end(t_room *stack);

void				ft_reset_all(t_room *stack);
void				ft_reset(t_room *beg);

void				ft_neighbors_stack(t_room *stack, int value, int *end);

void				ft_exit(char **str);
void				ft_exit_malloc(void);

#endif
