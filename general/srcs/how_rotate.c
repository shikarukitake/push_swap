/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:56:55 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_findnexta(const t_sts *sts,
		int value, int *index, t_stack **stack)
{
	(*stack) = *(sts->stacka);
	(*index) = binary_search(sts->chunks->array, sts->chunks->len, value) + 1;
	if (smaller_or_greater((*stack), value))
		(*index) = 0;
}

/*
** The function find next number for current value in stacka
** The next number is the element before which you need to put a value
*/

int			find_next_stacka(t_sts *sts, int value)
{
	int		index;
	t_stack	*stack;
	int		i;

	init_findnexta(sts, value, &index, &stack);
	while (index != sts->chunks->len)
	{
		if (exist_in_stack(stack, sts->chunks->array[index]) == TRUE)
			break ;
		index++;
	}
	i = 0;
	while (stack)
	{
		if (stack->value == sts->chunks->array[index])
			return (i);
		i++;
		stack = stack->previous;
	}
	error_tf("Cant find the next number in find_next_stacka function", FALSE);
	return (0);
}

void		init_findnext(const t_sts *sts, int value,
		int *index, t_stack **stack)
{
	(*stack) = *(sts->stackb);
	(*index) = binary_search(sts->chunks->array, sts->chunks->len, value) - 1;
	if (smaller_or_greater((*stack), value))
		(*index) = sts->chunks->len - 1;
}

/*
** The function find next number for current value in stackb
** The next number is the element before which you need to put a value
*/

int			find_next_stackb(t_sts *sts, int value)
{
	int		index;
	t_stack	*stack;
	int		i;

	init_findnext(sts, value, &index, &stack);
	while (index >= 0)
	{
		if (exist_in_stack(stack, sts->chunks->array[index]) == TRUE)
			break ;
		index--;
	}
	i = 0;
	while (stack)
	{
		if (stack->value == sts->chunks->array[index])
			return (i);
		i++;
		stack = stack->previous;
	}
	error_tf("Cant find the next number in find_next_stacka function\n", FALSE);
	return (0);
}
