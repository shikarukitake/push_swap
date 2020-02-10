//
// Created by shika on 10.02.2020.
//

#include <stdio.h>

struct      t_stack
{
    t_stack *previous;
    int     value;
}       s_stack;

t_stack     *init_stack(t_stack *previous, int value)
{
    t_stack *new;

    new = malloc(sizeof(new));
    if (new == NULL)
        return NULL;
    new->value = value;
    new->previous = previous;

    return (new);
}

t_stack     *ft_stack_push(t_stack *stack, int value)
{
    t_stack *new;

    new = init_stack(stack, value);
    return (new);
}

int         *ft_stack_pop(t_stack **stack)
{
    int value;
    t_stack *to_free;

    value = stack->value;
    to_free = *stack;
    *stack = *stack->previous;
    free(to_free);

    return (value);
}

t_stack     *ft_create_stack(int *values, int len)
{
    t_stack *new;
    int     i;

    new = init_stack(NULL, values[0]);
    i = 1;
    while (i != len)
    {
        new = ft_stack_push(new, values[i]);
        i++;
    }
    return (new);
}

int         main(void)
{



    return (0);
}