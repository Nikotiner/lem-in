/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:03:42 by dlian             #+#    #+#             */
/*   Updated: 2019/07/02 21:03:43 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**set_only_rooms(char **valid_args, char **params)
{
	int i;

	i = 0;
	while (params[i])
	{
		if (is_link(params[i]))
			break ;
		if (!is_comment(params[i]))
		{
			if (ft_strequ(params[i], "##start") ||
			ft_strequ(params[i], "##end"))
				valid_args = add_array_rows(valid_args, params[i]);
			else if (valid_rooms(params[i], valid_args))
				valid_args = add_array_rows(valid_args, params[i]);
			else
				return (NULL);
		}
		i++;
	}
	return (valid_args);
}

char	**set_only_links(char **valid_args, char **params)
{
	int i;

	i = -1;
	while (params[++i])
	{
		if (is_link(params[i]))
			break ;
	}
	while (params[i])
	{
		if (params[i][0] == '\0')
			return (valid_args);
		if (!is_comment(params[i]))
		{
			if (valid_link(params[i], valid_args))
				valid_args = add_array_rows(valid_args, params[i]);
			else
			{
				ft_printf("Link is not valid\n");
				return (NULL);
			}
		}
		i++;
	}
	return (valid_args);
}

char	**clean_params(char **params)
{
	char	**valid_args;
	int		i;

	i = 0;
	valid_args = NULL;
	if (!params)
	{
		ft_printf("Error input\n");
		return (NULL);
	}
	while (params[i] && is_comment(params[i]))
		i++;
	if (valid_numants(params[i]))
		valid_args = add_array_rows(valid_args, params[i++]);
	else
	{
		ft_printf("Error in quantity ants\n");
		return (NULL);
	}
	if (valid_args)
		valid_args = set_only_rooms(valid_args, &params[i]);
	if (valid_args)
		valid_args = set_only_links(valid_args, &params[i]);
	return (valid_args);
}
