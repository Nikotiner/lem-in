/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:03:54 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:03:56 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*get_room_by_name(t_room **rooms, char *name)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		if (ft_strequ(name, rooms[i]->name))
			return (rooms[i]);
		i++;
	}
	return (NULL);
}

t_room		*get_start_end_room(t_room **rooms, int is_find_start)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		if (is_find_start && rooms[i]->type == 1)
			return (rooms[i]);
		else if (!is_find_start && rooms[i]->type == 2)
			return (rooms[i]);
		i++;
	}
	return (NULL);
}

t_room		**get_rooms(char **params)
{
	t_room		*new;
	int			i;
	char		*split;
	t_room		**rooms;
	t_room		*first_room;

	i = 0;
	rooms = NULL;
	while (params[i])
	{
		if (is_room(params[i]))
		{
			split = ft_strsub(params[i], 0, get_index_of(params[i], ' '));
			new = create_room(split);
			rooms = add_node_to_array(rooms, new);
		}
		if (i != 0 && ft_strequ(params[i - 1], "##start"))
			first_room = new;
		if (i != 0 && ft_strequ(params[i - 1], "##end"))
			new->type = 2;
		i++;
	}
	first_room->type = 1;
	return (rooms);
}

int			change_room(t_room *from, t_room *to)
{
	int num_ant;

	num_ant = from->num_ant;
	if (to->num_ant)
		return (0);
	if (from->type == 1 && from->quantity)
		from->num_ant++;
	else
		from->num_ant = 0;
	from->quantity--;
	ft_printf("L%i-%s ", num_ant, to->name);
	if (to->type == 2)
		return (2);
	to->num_ant = num_ant;
	to->quantity++;
	return (1);
}
