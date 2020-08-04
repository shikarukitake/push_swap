/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:57:30 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/04 14:56:19 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_stackb(t_sts *sts)
{
	find_holds(sts);
	if (sts->firstholdi != 0 && sts->secondholdi != 0)
	{
		find_comm(sts, (*(sts->stacka))->len);
		sts->curcomm = commands_from_tcomm(sts->comm, NULL);
		get_darr_commands(sts);
		exec_commands(sts);
	}
	do_r_or_rr(sts, (*(sts->stacka))->value, "pb ");
}

void		sort_end_stackb(t_sts *sts)
{
	int		i;
	int		stack_len;

	i = find_id_max_in_stack(*(sts->stackb));
	stack_len = sts->chunks->len;
	if (i == 0)
		return ;
	sts->comm->command = i <= stack_len - i ? "rb " : "rrb ";
	sts->comm->count = i <= stack_len - i ? i : stack_len - i;
	sts->curcomm = commands_from_tcomm(sts->comm, NULL);
	get_darr_commands(sts);
	exec_commands(sts);
}

char		*sort_all(int how_many_chunks, t_sts *sts)
{
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
	sts->curcomm = commands_from_tcomm(sts->comm, NULL);
	get_darr_commands(sts);
	exec_commands(sts);
	change_chr(sts->commands, ' ', '\n');
	return (sts->commands);
}
