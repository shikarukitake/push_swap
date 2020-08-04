/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_ps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:40:26 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns 1 if value greater than all in given stack
** 0 if not greater or smaller
** -1 if smaller
*/

int		smaller_or_greater(t_stack *stack, int value)
{
	int min;
	int max;

	min = stack->value;
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		if (stack->value < min)
			min = stack->value;
		stack = stack->previous;
	}
	if (value > max)
		return (1);
	else if (value < min)
		return (-1);
	else
		return (0);
}

void	first_hold(t_sts *sts)
{
	t_stack *stack;
	int		j;

	j = 0;
	stack = *(sts->stacka);
	sts->firstholdi = -1;
	while (stack)
	{
		if (value_in_chunk(sts->chunks, stack->value) != -1)
		{
			sts->firstholdi = j;
			break ;
		}
		stack = stack->previous;
		j++;
	}
}

/*
** Find numbers from current chunk
** first hold - first number from top of the stack
** second hold - first number from bottom of the stack
** first hold
*/

void	find_holds(t_sts *sts)
{
	t_stack		*stack;
	int			i;
	int			j;

	first_hold(sts);
	j = 0;
	i = -1;
	stack = *(sts->stacka);
	sts->secondholdi = -1;
	while (stack)
	{
		if ((i = value_in_chunk(sts->chunks, stack->value)) != -1)
			sts->secondholdi = j;
		stack = stack->previous;
		j++;
	}
}

void	find_comm(t_sts *sts, int len_of_stack)
{
	int ind;
	int i;
	int j;

	ind = sts->secondholdi;
	j = ind <= len_of_stack - ind ? ind : len_of_stack - ind;
	ind = sts->firstholdi;
	i = ind <= len_of_stack - ind ? ind : len_of_stack - ind;
	if (sts->firstholdi == sts->secondholdi)
	{
		sts->comm->command = ind <= len_of_stack - ind ? "ra " : "rra ";
		sts->comm->count = ind <= len_of_stack - ind ? ind : len_of_stack - ind;
		return ;
	}
	else if (i <= j)
		sts->comm->command = sts->firstholdi <=
							len_of_stack - sts->firstholdi ? "ra " : "rra ";
	else if (i > j)
		sts->comm->command = sts->secondholdi <=
							len_of_stack - sts->secondholdi ? "ra " : "rra ";
	sts->comm->count = i <= j ? i : j;
}
