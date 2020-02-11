//
// Created by shika on 10.02.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "checker.h"
#include "../libft/includes/libft.h"
# define FALSE 0
# define TRUE 1
# define AND &&
# define OR ||

//typedef struct  s_stack
//{
//    struct s_stack *previous;
//    int     value;
//}               t_stack;
typedef struct s_dynamicArr
{
    int     *array;
    int     len;
    int     freeSpace;
}              t_dynamicArr;

void        cpyIntArray(int *dest, int *src, int freeOrNot, int len)
{
    int i;

    i = 0;
    if (dest )
    while (i != len)
    {
        dest[i] = src[i];
        i++;
    }
    if (freeOrNot)
        free(src);
}

void        initDArr(t_dynamicArr **arr)
{
    int *swap;

    if (arr AND *arr)
    {
        swap = (*arr)->array;
        (*arr)->array = (int*)malloc(sizeof(int) * ((*arr)->len * 2));
        cpyIntArray((*arr)->array, swap, 1, (*arr)->len);
        (*arr)->freeSpace = (*arr)->freeSpace * 2;
        free(swap);
    }
    else
    {
        (*arr) = (t_dynamicArr*)malloc(sizeof(t_dynamicArr));
        (*arr)->array = (int*)malloc(sizeof(int)*100);
        (*arr)->len = 0;
        (*arr)->freeSpace = 100;
    }
}

void        addDArr(t_dynamicArr **arr, int value)
{
    if (arr)
    {
        if (!(*arr))
            initDArr(arr);
        if (!(*arr)->freeSpace)
            initDArr(arr);
        (*arr)->array[(*arr)->len] = value;
        (*arr)->len += 1;
        (*arr)->freeSpace -= 1;
    }
}

t_stack     *init_stack(t_stack *previous, int value)
{
    t_stack *new;

    new = (t_stack*)malloc(sizeof(t_stack));
    if (new == NULL)
        exit(1);
    new->value = value;
    new->previous = previous;

    return (new);
}

int         peekStack(t_stack *stack)
{
    return (stack->value);
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

int         StackIsEmpty(t_stack *stack)
{
    if (stack == NULL)
        return (0);
    else
        return (1);
}

int         isOnlyDigits(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (ft_isdigit(s[i]) == FALSE AND s[i] != '-')
            return (FALSE);
        i++;
    }
    return (TRUE);
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
    printf("%-5s%5s\n","a", "b");
}

int         main(int argc, char **argv)
{
    t_stack *stackA;
    t_stack *stackB;
    int     i;

    stackA = NULL;
    stackB = NULL;
    if (argc == 1)
        return (0);
    else
    {
        i = argc - 1;
        while (i != 0)
        {
            if (isOnlyDigits(argv[i]) == FALSE)
            {
                printf("Error\n");
                return (0);
            }
            else
                pushStack(&stackA, ft_atoi(argv[i]));
            i--;
        }
    }
    printTwoStacks(stackA, stackB);
    printf("\n");
    while(stackA)
        pushStack(&stackB, popStack(&stackA));
    printTwoStacks(stackA, stackB);
    printf("\n");
    while(stackB)
    {
        reverseRotate(&stackB);
        pushStack(&stackA, popStack(&stackB));
        printTwoStacks(stackA, stackB);
        printf("\n");
    }

//    while(stackA)
//        pushStack(&stackB, popStack(&stackA));
//    while(stackB)
//        pushStack(&stackA, popStack(&stackB));
//    while (stackA)
//        printf("%d\n", popStack(&stackA));

    return (0);
}