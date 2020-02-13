//
// Created by Sole Dagger on 12/02/2020.
//

#include "checker.h"

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

void        pushStack(t_stack **stack, int value)
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
        pushStack(&new, values[i]);
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
    pushStack(stack, top);
    pushStack(stack, overTop);
}

void        rotate(t_stack **stack)
{
    t_dynamicArr    *temp;
    int             first;
    int             i;

    temp = NULL;
    i = 0;
    initDArr(&temp);
    if (*stack AND (*stack)->previous)
    {
        first = popStack(stack);
        while (*stack)
            addDArr(&temp, popStack(stack));
        pushStack(stack, first);
        i = temp->len - 1;
        while (i >= 0)
            pushStack(stack, temp->array[i--]);
    }
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
            pushStack(stack, temp->array[i--]);
        pushStack(stack, first);
        free(temp->array);
        free(temp);
    }
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
    printf("%-5s%5s\n","_", "_");
    printf("%-5s%5s\n\n","a", "b");
}