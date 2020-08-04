/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:58:17 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/04 16:48:32 by sdagger          ###   ########.fr       */
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

t_dynamicarr	*get_darr_commands(t_sts *sts)
{
	int		i;
	int		j;
	char	comm[5];

	i = 0;
	j = 0;
	while (sts->curcomm[i])
	{
		if (sts->curcomm[i] == ' ')
		{
			comm[j] = '\0';
			if (!add_darr(&sts->darr, check_command(comm)))
				error_tf("get_darr_commands add_darr", FALSE);
			j = 0;
			i++;
			continue ;
		}
		comm[j] = sts->curcomm[i];
		i++;
		j++;
	}
	if (!(sts->commands = ft_strjoin_free(sts->commands, sts->curcomm, 0)))
		error_tf("get_darr_commands", FALSE);
	sts->curcomm = NULL;
	return (sts->darr);
}

char			*commands_from_tcomm(t_command *comm, char const *pa_or_pb)
{
	char	*commands;
	int		count;

	count = comm->count;
	if (!(commands = ft_strnew(1)))
		error_tf("commands_from_tcomm ft_strnew", FALSE);
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
