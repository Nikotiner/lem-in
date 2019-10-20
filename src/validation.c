/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:04:30 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:04:32 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_numants(char *line)
{
	int			i;
	long int	k;

	i = 0;
	k = 0;
	if (!line || line[i] == '0')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		k = !k ? line[i] + 48 : k * 10 + line[i] + 48;
		i++;
	}
	if (k > 2147483647 || k == 0)
		return (0);
	return (1);
}

int		is_comment(char *line)
{
	if (!line)
		return (0);
	return (line[0] == '#' &&
		!ft_strequ(line, "##start") && !ft_strequ(line, "##end"));
}

char	**valid(char **params)
{
	int		i;
	char	**valid_args;

	i = 0;
	valid_args = clean_params(params);
	if (!valid_args)
		return (NULL);
	if (!is_start_end(valid_args))
	{
		ft_printf("Error with quantity system commands\n");
		return (NULL);
	}
	return (valid_args);
}
