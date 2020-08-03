/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:06:24 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:06:25 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverse_rotate(t_stack **stack)
{
	t_dynamicarr	*temp;
	int				first;
	int				i;

	temp = NULL;
	i = 0;
	init_darr(&temp);
	if (*stack && (*stack)->previous)
	{
		while (*stack)
			add_darr(&temp, pop_stack(stack));
		first = temp->array[temp->len - 1];
		temp->len -= 1;
		i = temp->len - 1;
		while (i >= 0)
			push_stack(stack, temp->array[i--]);
		push_stack(stack, first);
		free(temp->array);
		free(temp);
	}
}

void		rotate(t_stack **stackbig)
{
	t_stack *swap;
	t_stack *stack;
	t_stack *temp;
	int		len;

	stack = *stackbig;
	len = stack->len;
	swap = stack;
	stack = stack->previous;
	swap->previous = NULL;
	temp = stack;
	while (stack->previous)
	{
		stack->len = len;
		stack = stack->previous;
		len--;
	}
	stack->len = 2;
	stack->previous = swap;
	stack->previous->len = 1;
	*stackbig = temp;
}

void		print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%-5d", stack_a->value);
			stack_a = stack_a->previous;
		}
		else
			ft_printf("%-5s", "");
		if (stack_b)
		{
			ft_printf("%5d\n", stack_b->value);
			stack_b = stack_b->previous;
		}
		else
			ft_printf("\n");
	}
	ft_printf("%-5s%5s\n", "_", "_");
	ft_printf("%-5s%5s\n\n", "a", "b");
	ft_printf("----------\n\n");
}

void		free_stack(t_stack *stack)
{
	t_stack *to_free;

	while (stack)
	{
		to_free = stack;
		stack = stack->previous;
		free(to_free);
	}
}
