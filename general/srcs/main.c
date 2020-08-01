//
// Created by shika on 10.02.2020.
//

//#include "../libft/includes/libft.h"

#include <unistd.h>
#include "libft.h"

typedef struct  s_stack
{
    struct s_stack *previous;
    int     value;
    int     len;
}               t_stack;

t_stack     *init_stack(t_stack *previous, int value)
{
    t_stack *new;

    new = (t_stack*)malloc(sizeof(t_stack));
    if (new == NULL)
        exit(1);
    new->value = value;
    new->previous = previous;
    if (new->previous != NULL)
        new->len = (new->previous)->len + 1;
    else
        new->len = 1;
    return (new);
}

void        push_stack(t_stack **stack, int value)
{
    *stack = init_stack(*stack, value);
}

t_stack     *newStack(int *values, int len)
{
    t_stack *new;
    int     i;

    new = init_stack(NULL, values[0]);
    i = 1;
    while (i != len)
    {
        push_stack(&new, values[i]);
        i++;
    }
    return (new);
}

void        rotate(t_stack **stackbig)
{
    t_stack *swap;
    t_stack *stack;
    t_stack *temp;
    int     len;

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

void        reverse_rotate(t_stack **stack)

int main(int argc, char **argv)
{
    t_stack *stack;
    t_stack *swap;
    t_stack *temp;
    int i = 0;

    int array[] = {1, 2};
    stack = newStack(array, 2);
//    swap = stack;
//    stack = stack->previous;
//    swap->previous = NULL;
//    temp = stack;
//    while (stack->previous)
//    {
//        stack = stack->previous;
//    }
//    stack->previous = swap;
    rotate(&stack);
    while (stack)
    {
        printf("%d %d\n", stack->value, stack->len);
        stack = stack->previous;
    }
    return (0);
}
