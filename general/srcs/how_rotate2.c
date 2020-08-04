/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_rotate2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:04:04 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/04 15:10:23 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*ra_or_rra(t_sts *sts, int value)
{
	int			len_of_stacka;
	t_command	*comm;
	int			i;

	i = 0;
	len_of_stacka = (*(sts->stacka))->len;
	if (!(comm = (t_command*)malloc(sizeof(t_command))))
		error_tf("ra_or_rra malloc ft_error", FALSE);
	i = find_next_stacka(sts, value);
	comm->command = i <= len_of_stacka - i ? "ra " : "rra ";
	comm->count = i <= len_of_stacka - i ? i : len_of_stacka - i;
	return (comm);
}

t_command	*rb_or_rrb(t_sts *sts, int value)
{
	int			len_of_stacka;
	t_command	*comm;
	int			i;

	i = 0;
	if (!(comm = (t_command*)malloc(sizeof(t_command))))
		error_tf("rb_or_rrb malloc ft_error", FALSE);
	if ((*(sts->stackb)) == NULL)
	{
		comm->count = 0;
		return (comm);
	}
	len_of_stacka = (*(sts->stackb))->len;
	i = find_next_stackb(sts, value);
	comm->command = i <= len_of_stacka - i ? "rb " : "rrb ";
	comm->count = i <= len_of_stacka - i ? i : len_of_stacka - i;
	return (comm);
}

void		do_r_or_rr(t_sts *sts, int value, char *pa_or_pb)
{
	t_command	*comm;

	if (!ft_strcmp(pa_or_pb, "pa "))
		comm = ra_or_rra(sts, value);
	else
		comm = rb_or_rrb(sts, value);
	sts->curcomm = commands_from_tcomm(comm, pa_or_pb);
	free(comm);
	get_darr_commands(sts);
	exec_commands(sts);
}
