/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:03:28 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:03:30 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**read_params(int fd)
{
	char *line;
	char **params;

	params = NULL;
	while (get_next_line(fd, &line) > 0)
		params = add_array_rows(params, line);
	return (params);
}

void	show_game_params(char **params)
{
	int i;

	i = 0;
	while (params[i])
		ft_printf("%s\n", params[i++]);
	ft_printf("\n");
}
