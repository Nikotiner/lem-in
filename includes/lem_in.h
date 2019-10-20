/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:02:32 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:02:34 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct			s_room_list
{
	int					quantity;
	int					num_ant;
	int					fin_steps;
	int					size;
	char				*name;
	int					type;
	int					is_checked;
	int					num_path;
	int					to_end;
	struct s_room_list	**par_nodes;
	struct s_room_list	**nodes;
}						t_room;

typedef struct			s_link_list
{
	t_room				*room1;
	t_room				*room2;
}						t_link;

char					**read_params(int fd);
char					**add_array_rows(char **array, char *row);
void					free_splits(char **split);
void					set_check_false(t_room **rooms);
void					set_null_parent_child_without_path(t_room **rooms);
char					**valid(char **params);
char					**clean_params(char **params);
int						is_comment(char *line);
int						valid_numants(char *line);
void					show_game_params(char **params);
t_room					*create_room(char *name);
t_room					**add_node_to_array(t_room **list, t_room *node);
int						is_room(char *line);
int						is_start_end(char **params);
int						valid_rooms(char *line, char **valided);
int						is_link(char *line);
int						set_links(t_link **links, t_room **rooms, t_room *room);
t_link					**get_links_list(t_room **rooms, char **params);
t_room					**get_rooms(char **params);
int						change_room(t_room *from, t_room *to);
t_room					*get_room_by_name(t_room **rooms, char *name);
t_room					*get_start_end_room(t_room **rooms, int is_find_start);
int						valid_link(char *line, char **valided);
int						get_quantity_ants(char **params);
int						set_qnt_finish_steps(t_room *room, int step);
int						move(t_room **rooms, int ant);
void					put_null(t_room **stack, int from);
int						start(t_room **rooms, int quantity_ants);
int						main(int args, char **argv);
int						decision(t_room *room);
void					sort_nodes_by_finsteps(t_room *room);
void					sort_rooms_by_finsteps(t_room **rooms);
t_link					**add_link_to_array(t_link **list, t_link *node);
t_link					*create_link(t_room *room1, t_room *room2);
int						get_index_of(char *str, char ch);
void					free_s_link(t_link **link_list);
int						*set_empty_zero(int size);
t_room					**remove_room_by_index(t_room **list, int index);

#endif
