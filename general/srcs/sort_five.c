/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:36:18 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:18:19 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_end(t_sts *sts)
{
	int		i;
	t_stack	*stack;
	char	*commas;
	int		len_of_stacka;

	stack = *(sts->stacka);
	i = 0;
	len_of_stacka = sts->chunks->len;
	while (stack)
	{
		if (stack->value == sts->chunks->array[0])
			break ;
		stack = stack->previous;
		i++;
	}
	sts->comm->command = i <= len_of_stacka - i ? "ra " : "rra ";
	sts->comm->count = i <= len_of_stacka - i ? i : len_of_stacka - i;
	commas = commands_from_tcomm(sts->comm, NULL);
	sts->darr = get_darr_commands(commas);
	exec_commands(sts);
	sts->commands = ft_strjoin_free(sts->commands, commas, 0);
}

char		*sort_five(t_sts *sts)
{
	init_chunks_comm(sts, 1);
	sts->commands = (*(sts->stacka))->len == 4 ?
					ft_strdup("pb ") : ft_strdup("pb pb ");
	if (!sts->commands)
		error_tf("sort_five ft_strdup malloc error", FALSE);
	if (!(sts->darr = get_darr_commands(sts->commands)))
		error_tf("sort_five darr error", FALSE);
	exec_commands(sts);
	if (stack_is_sorted(*(sts->stacka)) == FALSE)
		if (!(sts->commands = ft_strjoin_free(sts->commands,
				sort_three(sts, 1), 0)))
			error_tf("sort_five ft_strjoin_free error", FALSE);
	while (*(sts->stackb))
		do_r_or_rr(sts, (*(sts->stackb))->value, "pa ");
	if (stack_is_sorted(*(sts->stacka)) == FALSE)
		sort_end(sts);
	change_chr(sts->commands, ' ', '\n');
	return (sts->commands);
}