/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:57:30 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:18:19 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_stackb(t_sts *sts)
{
	char *commas;

	find_holds(sts);
	if (sts->firstholdi != 0 && sts->secondholdi != 0)
	{
		find_comm(sts, (*(sts->stacka))->len);
		commas = commands_from_tcomm(sts->comm, NULL);
		if (!(sts->darr = get_darr_commands(commas)))
		{
			free(commas);
			error_tf("push_to_stackb get_darr_commands error", FALSE);
		}
		exec_commands(sts);
		sts->commands = ft_strjoin_free(sts->commands, commas, 0);
	}
	do_r_or_rr(sts, (*(sts->stacka))->value, "pb ");
}

void		sort_end_stackb(t_sts *sts)
{
	int		i;
	char	*commas;
	int		stack_len;

	i = find_id_max_in_stack(*(sts->stackb));
	stack_len = sts->chunks->len;
	if (i == 0)
		return ;
	sts->comm->command = i <= stack_len - i ? "rb " : "rrb ";
	sts->comm->count = i <= stack_len - i ? i : stack_len - i;
	commas = commands_from_tcomm(sts->comm, NULL);
	if (!(sts->darr = get_darr_commands(commas)))
		error_tf("sort_end_stackb get_darr_commands malloc error", FALSE);
	exec_commands(sts);
	if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
		error_tf("sort_end_stackb ft_strjoin_free malloc error", FALSE);
}

char		*sort_all(int how_many_chunks, t_sts *sts)
{
	char	*commas;

	init_chunks_comm(sts, how_many_chunks);
	if (!(sts->commands = ft_strdup("")))
		error_tf("sort_all ft_strdup malloc error", FALSE);
	while (sts->chunks->current_c != how_many_chunks)
	{
		if (exists_in_chunk(*(sts->stacka), sts->chunks) == FALSE)
			sts->chunks->current_c++;
		if (sts->chunks->current_c != how_many_chunks)
			push_to_stackb(sts);
	}
	sort_end_stackb(sts);
	sts->comm->command = "pa ";
	sts->comm->count = (*(sts->stackb))->len;
	commas = commands_from_tcomm(sts->comm, NULL);
	if (!(sts->darr = get_darr_commands(commas)))
		error_tf("sort_all get_darr_commands malloc error", FALSE);
	exec_commands(sts);
	if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
		error_tf("sort_all ft_strjoin_free malloc error", FALSE);
	change_chr(sts->commands, ' ', '\n');
	return (sts->commands);
}
