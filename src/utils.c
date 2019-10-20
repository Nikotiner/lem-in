/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:04:16 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:04:19 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_index_of(char *str, char ch)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == ch)
			return (index);
		index++;
	}
	return (-1);
}

void		set_check_false(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		rooms[i++]->is_checked = 0;
	}
}

void		set_null_parent_child_without_path(t_room **rooms)
{
	int i;
	int j;

	i = -1;
	while (rooms[++i])
	{
		if (rooms[i]->type == 1)
		{
			j = -1;
			while (rooms[i]->nodes[++j])
				if (!rooms[i]->nodes[j]->num_path)
					rooms[i]->nodes =
					remove_room_by_index(rooms[i]->nodes, j--);
		}
		else if (!rooms[i]->num_path)
		{
			if (rooms[i]->par_nodes)
				free(rooms[i]->par_nodes);
			if (rooms[i]->nodes)
				free(rooms[i]->nodes);
			rooms[i]->par_nodes = NULL;
			rooms[i]->nodes = NULL;
		}
	}
}

void		sort_nodes_by_finsteps(t_room *room)
{
	int			i;
	t_room		*swap;

	i = 0;
	while (room->nodes && room->nodes[i + 1])
	{
		if (room->nodes[i]->fin_steps == -1 &&
		room->nodes[i + 1]->fin_steps == -1)
		{
			i++;
			continue;
		}
		else if ((room->nodes[i]->fin_steps > room->nodes[i + 1]->fin_steps
		&& room->nodes[i + 1]->fin_steps != -1) ||
		room->nodes[i]->fin_steps == -1)
		{
			swap = room->nodes[i];
			room->nodes[i] = room->nodes[i + 1];
			room->nodes[i + 1] = swap;
			i = -1;
		}
		i++;
	}
}

void		sort_rooms_by_finsteps(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		sort_nodes_by_finsteps(rooms[i]);
		i++;
	}
}
