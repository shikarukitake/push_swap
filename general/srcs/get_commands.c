/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:58:17 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 16:58:19 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Additional function to sort three elements
*/

char			*get_str_commands3(int *min_mean_max, int *swap)
{
	if (swap[0] == min_mean_max[2])
	{
		if (swap[1] == min_mean_max[1])
			return (ft_strdup("ra sa "));
		return (ft_strdup("ra "));
	}
	else if (swap[2] == min_mean_max[0])
		return (ft_strdup("rra "));
	if (swap[1] == min_mean_max[2])
		return (ft_strdup("sa ra "));
	return (ft_strdup("sa "));
}

/*
** Transform str commands into darr where command have int value
*/

t_dynamicarr	*get_darr_commands(char *commandz)
{
	int				n;
	char			*commands;
	t_dynamicarr	*darr;
	char			*command;

	darr = NULL;
	if (!(commands = ft_strdup(commandz)))
		return (NULL);
	while (commands && ft_strcmp(commands, ""))
	{
		n = ft_strchrn(commands, ' ');
		if (!(command = ft_strsub_free(commands, 0, n, 0)))
			return (NULL);
		if (!add_darr(&darr, check_command(command)))
			return (NULL);
		if (!(commands = ft_strsub_free(commands,
				n + 1, ft_strlen(commands) - (n + 1), 1)))
			return (NULL);
		free(command);
	}
	free(commands);
	return (darr);
}

char			*commands_from_tcomm(t_command *comm, char const *pa_or_pb)
{
	char	*commands;
	int		count;

	count = comm->count;
	commands = ft_strnew(1);
	while (count)
	{
		if (!(commands = ft_strjoin_free(commands, comm->command, 1)))
			error_tf("commands_from_tcomm ft_strjoin_free error", FALSE);
		count--;
	}
	if (pa_or_pb != NULL)
		if (!(commands = ft_strjoin_free(commands, pa_or_pb, 1)))
			error_tf("commands_from_tcomm ft_strjoin_free error", FALSE);
	return (commands);
}
