//
// Created by Sole Dagger on 12/02/2020.
//

#include "checker.h"

t_stack     *init_stack(t_stack *previous, int value)
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

void        push_stack(t_stack **stack, int value)
{
    *stack = init_stack(*stack, value);
}

int         popStack(t_stack **stack)
{
    int value;
    t_stack *to_free;

    value = (*stack)->value;
    to_free = *stack;
    *stack = (*stack)->previous;
    free(to_free);

    return (value);
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

void        swap(t_stack **stack)
{
    int top;
    int overTop;

    if (*stack AND (*stack)->previous)
    {
        top = popStack(stack);
        overTop = popStack(stack);
    }
    else
        return ;
    push_stack(stack, top);
    push_stack(stack, overTop);
}

void        reverseRotate(t_stack **stack)
{
    t_dynamicArr    *temp;
    int             first;
    int             i;

    temp = NULL;
    i = 0;
    initDArr(&temp);
    if (*stack AND (*stack)->previous)
    {
        while (*stack)
            addDArr(&temp, popStack(stack));
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

void        printStack(t_stack *stack)
{
    t_stack *temp;

    temp = stack;
    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->previous;
    }
}

void        printTwoStacks(t_stack *stackA, t_stack *stackB)
{
    while (stackA OR stackB)
    {
        if (stackA)
        {
            printf("%-5d", stackA->value);
            stackA = stackA->previous;
        }
        else
            printf("%-5s", "");
        if (stackB)
        {
            printf("%5d\n", stackB->value);
            stackB = stackB->previous;
        }
        else
            printf("\n");
    }
    ft_printf("%-5s%5s\n","_", "_");
    ft_printf("%-5s%5s\n\n","a", "b");
}

void        free_stack(t_stack *stack)
{
    t_stack *to_free;

    while (stack)
    {
        to_free = stack;
        stack = stack->previous;
        free(to_free);
    }
}