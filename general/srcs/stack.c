
#include "checker.h"

t_stack		*init_stack(t_stack *previous, int value)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new == NULL)
		error_tf("init stack malloc err||", FALSE);
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

void		reverse_rotate(t_stack **stack)
{
	t_dynamicArr	*temp;
	int				first;
	int				i;

	temp = NULL;
	i = 0;
	initDArr(&temp);
	if (*stack && (*stack)->previous)
	{
		while (*stack)
			addDArr(&temp, pop_stack(stack));
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
