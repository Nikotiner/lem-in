/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:02:43 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:02:44 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_path_from_end(t_room *pre_end, int npath)
{
	t_room		*curr_room;
	int			steps;

	curr_room = pre_end;
	steps = 1;
	while (curr_room->type != 1)
	{
		curr_room->num_path = npath;
		if (curr_room->par_nodes[0]->type == 1)
			curr_room->fin_steps = steps;
		curr_room = curr_room->par_nodes[0];
		steps++;
	}
}

void		add_links(t_link **links, t_room *curr_room)
{
	int			i;
	t_room		*r1;
	t_room		*r2;

	i = 0;
	while (links[i])
		i++;
	while (--i >= 0)
	{
		r1 = links[i]->room1;
		r2 = links[i]->room2;
		if (ft_strequ(curr_room->name, r1->name) && !r2->par_nodes)
		{
			if (r2->type != 1)
				r2->par_nodes = add_node_to_array(r2->par_nodes, curr_room);
			curr_room->nodes = add_node_to_array(curr_room->nodes, r2);
		}
		else if (ft_strequ(curr_room->name, r2->name) && !r1->par_nodes)
		{
			if (r1->type != 1)
				r1->par_nodes = add_node_to_array(r1->par_nodes, curr_room);
			curr_room->nodes = add_node_to_array(curr_room->nodes, r1);
		}
	}
}

t_link		**get_links_list(t_room **rooms, char **params)
{
	t_link		**links;
	char		**split_link;
	int			i;

	i = 0;
	links = NULL;
	while (params[i])
	{
		if (is_link(params[i]))
		{
			split_link = ft_strsplit(params[i], '-');
			links = add_link_to_array(links,
			create_link(get_room_by_name(rooms, split_link[0]),
			get_room_by_name(rooms, split_link[1])));
			free_splits(split_link);
		}
		i++;
	}
	return (links);
}

int			is_add_new_path(t_link **links, t_room *start, int npath)
{
	int			i;
	int			j;
	t_room		**que;

	i = -1;
	que = NULL;
	que = add_node_to_array(que, start);
	while (que[++i])
		if (que[i]->type == 1 || !que[i]->nodes)
		{
			add_links(links, que[i]);
			j = -1;
			while (que[i]->nodes && que[i]->nodes[++j])
			{
				if (que[i]->type != 1 && que[i]->nodes[j]->type == 2)
				{
					set_path_from_end(que[i], npath++);
					free(que);
					return (1);
				}
				que = add_node_to_array(que, que[i]->nodes[j]);
			}
		}
	free(que);
	return (0);
}

int			set_links(t_link **links, t_room **rooms, t_room *room)
{
	int npath;
	int i;

	i = 0;
	npath = 0;
	if (!links)
	{
		ft_printf("No connection with end\n");
		return (0);
	}
	while (is_add_new_path(links, room, ++npath))
		set_null_parent_child_without_path(rooms);
	free_s_link(links);
	if (npath - 1 == 0)
	{
		while (room->nodes[i])
		{
			if (room->nodes[i]->type == 2)
				return (1);
			i++;
		}
	}
	if (!(npath - 1))
		ft_printf("No connection with end\n");
	return (npath - 1);
}
