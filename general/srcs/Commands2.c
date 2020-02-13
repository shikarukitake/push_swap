//
// Created by Sole Dagger on 13/02/2020.
//
#include "checker.h"

void        ft_ra(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("ra:\n");
    rotate(stackA);
}

void        ft_rb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rb:\n");
    rotate(stackB);
}

void        ft_rr(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rr:\n");
    rotate(stackA);
    rotate(stackB);
}

void        ft_rra(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rra:\n");
    reverseRotate(stackA);
}

void        ft_rrb(t_stack **stackA, t_stack **stackB, int flag)
{
    stackA = stackA;
    if (flag)
        printf("rrb:\n");
    reverseRotate(stackB);
}