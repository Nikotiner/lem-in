/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:02:22 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:02:24 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_not_finished(int *ants, int size)
{
	int i;

	i = 0;
	ft_printf("\n");
	while (i < size)
	{
		if (!ants[i])
			return (1);
		i++;
	}
	return (0);
}

int		start(t_room **rooms, int quantity_ants)
{
	int i;
	int steps;
	int finished_ants;
	int move_status;
	int *ants;

	finished_ants = 0;
	i = -1;
	steps = 0;
	ants = set_empty_zero(quantity_ants);
	while (++i < quantity_ants)
	{
		if (!ants[i] && (move_status = move(rooms, i + 1)))
			if (move_status == 2)
				ants[i] = 1;
		if (i + 1 == quantity_ants && is_not_finished(ants, quantity_ants))
		{
			steps++;
			i = -1;
		}
	}
	free(ants);
	return (steps + 1);
}

void	prepare(t_room **rooms, int qnt_ants)
{
	t_room *first_room;
	t_room *last_room;

	first_room = get_start_end_room(rooms, 1);
	last_room = get_start_end_room(rooms, 0);
	first_room->num_ant = 1;
	first_room->quantity = qnt_ants;
	last_room->fin_steps = 0;
}

void	show_comand(int args, char **argv, int steps)
{
	int i;

	i = 1;
	while (i < args)
	{
		if (ft_strequ(argv[i], "-r"))
			ft_printf("Steps = %i\n", steps);
		else if (ft_strequ(argv[i], "-help"))
			ft_printf("-r show steps\n-l show leaks\n");
		else if (ft_strequ(argv[i], "-l"))
			system("leaks -q lem-in");
		i++;
	}
}

int		main(int args, char **argv)
{
	char		**params;
	char		**validated;
	int			steps;
	t_room		**rooms;
	int			qnt_ants;

	params = read_params(0);
	validated = valid(params);
	if (!validated)
		return (0);
	qnt_ants = get_quantity_ants(validated);
	rooms = get_rooms(validated);
	if (!set_links(get_links_list(rooms, params),
	rooms, get_start_end_room(rooms, 1)))
		return (0);
	show_game_params(params);
	set_check_false(rooms);
	sort_rooms_by_finsteps(rooms);
	prepare(rooms, qnt_ants);
	steps = start(rooms, qnt_ants);
	show_comand(args, argv, steps);
	return (0);
}
