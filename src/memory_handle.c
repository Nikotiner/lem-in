/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:03:17 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:03:19 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*set_empty_zero(int size)
{
	int i;
	int *res;

	i = 0;
	res = (int *)malloc(sizeof(int) * size);
	while (i < size)
		res[i++] = 0;
	return (res);
}

void		free_splits(char **split)
{
	int i;

	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
}

t_room		*create_room(char *name)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	room->name = name;
	room->nodes = NULL;
	room->par_nodes = NULL;
	room->fin_steps = -1;
	room->num_ant = 0;
	room->is_checked = 0;
	room->type = 0;
	room->num_path = 0;
	room->to_end = -1;
	return (room);
}

void		free_s_link(t_link **link_l)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (link_l[size])
		size++;
	while (i < size)
	{
		free(link_l[i]);
		link_l[i] = NULL;
		i++;
	}
	free(link_l);
}

t_link		*create_link(t_room *room1, t_room *room2)
{
	t_link *link;

	link = (t_link *)malloc(sizeof(t_link));
	link->room1 = room1;
	link->room2 = room2;
	return (link);
}
