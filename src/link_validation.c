/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:02:54 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:02:56 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_link(char *line)
{
	int i;
	int sp_count;

	i = 0;
	sp_count = 0;
	if (!line || line[0] == '#' || ft_strchr(line, ' '))
		return (0);
	while (line && line[i] != '\0')
	{
		if (line[i++] == '-')
		{
			sp_count++;
			if (line[i] == '\0')
				return (0);
		}
	}
	if (sp_count == 1)
		return (1);
	return (0);
}

int	is_exist_room_by_link(char *room, char *link)
{
	int len3;
	int len;
	int len2;

	len = get_index_of(room, ' ');
	len2 = get_index_of(link, '-');
	len3 = ft_strlen(ft_strchr(link, '-') + 1);
	if (len == len2 && !ft_strncmp(room, link, len))
		return (1);
	if (len == len3 && !ft_strncmp(room, ft_strchr(link, '-') + 1, len))
		return (1);
	return (0);
}

int	is_link_to_self(char *line)
{
	int		len;
	int		len2;
	char	*ch;

	ch = ft_strchr(line, '-') + 1;
	len = get_index_of(line, '-');
	len2 = ft_strlen(ch);
	if (len == len2 && !ft_strncmp(line, ch, len))
		return (1);
	return (0);
}

int	valid_link(char *line, char **valided)
{
	int		i;
	int		is_rooms_exist;

	i = -1;
	is_rooms_exist = 0;
	if (!is_link(line) || is_link_to_self(line))
		return (0);
	while (valided[++i])
	{
		if (is_room(valided[i]) &&
		(is_exist_room_by_link(valided[i], line)))
			is_rooms_exist++;
	}
	if (is_rooms_exist != 2)
		return (0);
	return (1);
}
