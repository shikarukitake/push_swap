/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:57:02 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*init_stack(t_stack *previous, int value)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new == NULL)
		error_tf("init stack malloc error", FALSE);
	new->value = value;
	new->previous = previous;
	if (new->previous != NULL)
		new->len = (new->previous)->len + 1;
	else
		new->len = 1;
	return (new);
}

void		push_stack(t_stack **stack, int value)
{
	*stack = init_stack(*stack, value);
}

int			pop_stack(t_stack **stack)
{
	int		value;
	t_stack *to_free;

	value = (*stack)->value;
	to_free = *stack;
	*stack = (*stack)->previous;
	free(to_free);
	return (value);
}

void		swap(t_stack **stack)
{
	int top;
	int over_top;

	if ((*stack)->len != 1)
	{	
		if (*stack && (*stack)->previous)
		{
			top = pop_stack(stack);
			over_top = pop_stack(stack);
		}
		else
			return ;
		push_stack(stack, top);
		push_stack(stack, over_top);
	}
}
