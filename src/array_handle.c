/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:01:58 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:02:02 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**add_array_rows(char **array, char *row)
{
	int		i;
	char	**tmp;
	int		size;

	i = 0;
	size = 0;
	while (array && array[size])
		size++;
	tmp = (char **)malloc(sizeof(char *) * (size + 2));
	while (i < size)
	{
		tmp[i] = array[i];
		i++;
	}
	tmp[i++] = row;
	tmp[i] = NULL;
	if (size)
		free(array);
	return (tmp);
}

t_room		**add_node_to_array(t_room **list, t_room *node)
{
	int			i;
	int			size;
	t_room		**tmp;

	i = 0;
	size = 0;
	while (list && list[i++])
		size++;
	tmp = (t_room **)malloc((sizeof(t_room *) *
	(size + 1)) + sizeof(t_room *));
	i = 0;
	while (list && list[i])
	{
		tmp[i] = list[i];
		i++;
	}
	tmp[i] = node;
	tmp[i + 1] = NULL;
	if (size)
		free(list);
	return (tmp);
}

t_room		**remove_room_by_index(t_room **list, int index)
{
	int			i;
	int			size;
	t_room		**tmp;

	i = 0;
	size = 0;
	while (list && list[i++])
		size++;
	tmp = (t_room **)malloc((sizeof(t_room *) *
	(size)) + sizeof(t_room *));
	i = 0;
	while (list && list[i])
	{
		if (i < index)
			tmp[i] = list[i];
		else if (i > index)
			tmp[i - 1] = list[i];
		i++;
	}
	tmp[i - 1] = NULL;
	if (size)
		free(list);
	return (tmp);
}

t_link		**add_link_to_array(t_link **list, t_link *node)
{
	int			i;
	int			size;
	t_link		**tmp;

	i = 0;
	size = 0;
	while (list && list[i++])
		size++;
	tmp = (t_link **)malloc((sizeof(t_link *) *
	(size + 1)) + sizeof(t_link *));
	i = 0;
	while (list && list[i])
	{
		tmp[i] = list[i];
		i++;
	}
	tmp[i] = node;
	tmp[i + 1] = NULL;
	if (size)
		free(list);
	return (tmp);
}
