/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:04:06 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:04:08 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_room(char *line)
{
	int i;
	int sp_count;

	i = 0;
	sp_count = 0;
	while (line && line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			sp_count++;
			if (line[i + 1] == '\0' || line[i + 1] == ' ')
				return (0);
		}
		else if (sp_count > 0 && !ft_isdigit(line[i])
		&& !ft_strchr(" -", line[i]))
			return (0);
		else if (sp_count > 0 && line[i] == '-' &&
		(line[i - 1] != ' ' || !ft_isdigit(line[i + 1])))
			return (0);
		i++;
	}
	if (sp_count == 2)
		return (1);
	return (0);
}

int	is_start_end(char **params)
{
	int i;
	int start;
	int end;

	i = -1;
	start = 0;
	end = 0;
	while (params[++i])
	{
		if (ft_strequ(params[i], "##start"))
		{
			if (!params[i + 1] || !is_room(params[i + 1]))
				return (0);
			start++;
		}
		if (ft_strequ(params[i], "##end"))
		{
			if (!params[i + 1] || !is_room(params[i + 1]))
				return (0);
			end++;
		}
	}
	if (start != 1 || end != 1)
		return (0);
	return (1);
}

int	is_room_not_eq(char *room1, char *room2)
{
	int len1;
	int len2;

	len1 = get_index_of(room1, ' ');
	len2 = get_index_of(room2, ' ');
	if (len2 == len1 && !ft_strncmp(room1, room2, len1))
		return (0);
	if (ft_strequ(ft_strchr(room1, ' ') + 1, ft_strchr(room2, ' ') + 1))
		return (0);
	return (1);
}

int	valid_rooms(char *line, char **valided)
{
	int		i;
	int		valid_res;

	i = -1;
	valid_res = 1;
	if (!is_room(line) || line[0] == 'L')
	{
		ft_printf("Room error\n");
		return (0);
	}
	while (valided[++i])
		if (is_room(valided[i]))
		{
			if (!is_room_not_eq(line, valided[i]))
				valid_res = 0;
		}
	if (valid_res)
		return (1);
	ft_printf("Room error\n");
	return (0);
}
