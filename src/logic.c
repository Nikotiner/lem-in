/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:03:05 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:03:07 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_quantity_ants(char **params)
{
	int quantity_ants;

	quantity_ants = ft_atoi(params[0]);
	return (quantity_ants);
}

int	is_optim_move(t_room *next_room, t_room *curr_room)
{
	int i;
	int step;

	i = 0;
	step = 0;
	if (curr_room->type == 1)
	{
		if (!next_room || next_room->fin_steps == -1)
			return (0);
		while (curr_room->nodes[i] &&
		!ft_strequ(next_room->name, curr_room->nodes[i]->name))
			step += next_room->fin_steps - curr_room->nodes[i++]->fin_steps;
		if (curr_room->quantity < step)
			return (0);
	}
	else if (next_room->num_path != curr_room->num_path)
		return (0);
	return (1);
}

int	decision(t_room *room)
{
	int			i;
	int			step;
	int			quant_rooms;
	t_room		*new_room;

	i = 0;
	step = 0;
	new_room = NULL;
	quant_rooms = 0;
	while (room->nodes[i])
	{
		if (room->nodes[i]->type == 2)
			return (change_room(room, room->nodes[i]));
		if (!new_room && room->type == 1 && !room->nodes[i]->num_ant)
			new_room = room->nodes[i];
		else if (room->type != 1 && room->nodes[i]->num_path == room->num_path)
			new_room = room->nodes[i];
		i++;
	}
	if (!is_optim_move(new_room, room))
		return (-1);
	return (change_room(room, new_room));
}

int	move(t_room **rooms, int ant)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		if (rooms[i]->num_ant == ant)
		{
			return (decision(rooms[i]));
		}
		i++;
	}
	return (-1);
}
