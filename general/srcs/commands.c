//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

void        ft_sa(t_stack **stackA, t_stack **stackB, int flag)
{
    t_stack **stack;

    stack = stackB;
    stack = NULL;
    if (flag)
        printf("sa:\n");
    swap(stackA);
}

void        ft_sb(t_stack **stackA, t_stack **stackB, int flag)
{
    t_stack **stack;

    stack = stackA;
    stack = NULL;
    if (flag)
        printf("sb:\n");
    swap(stackB);
}

void        ft_ss(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("ss:\n");
    swap(stackA);
    swap(stackB);
}

void        ft_pa(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("pa:\n");
    if (*stackB)
        push_stack(stackA, popStack(stackB));
}

void        ft_pb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("pb:\n");
    if (*stackA)
        push_stack(stackB, popStack(stackA));
}