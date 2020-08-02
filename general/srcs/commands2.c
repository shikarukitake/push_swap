//
// Created by Sole Dagger on 13/02/2020.
//
#include "checker.h"

void        ft_ra(t_sts *sts)
{
    if (sts->flag)
        ft_printf("ra:\n");
    rotate(sts->stackA);
}

void        ft_rb(t_sts *sts)
{
    if (sts->flag)
        ft_printf("rb:\n");
    rotate(sts->stackB);
}

void        ft_rr(t_sts *sts)
{
    if (sts->flag)
        ft_printf("rr:\n");
    rotate(sts->stackA);
    rotate(sts->stackB);
}

void        ft_rra(t_sts *sts)
{
    t_stack **stack;

    stack = sts->stackB;
    stack = NULL;

    if (sts->flag)
        ft_printf("rra:\n");
    reverseRotate(sts->stackA);
}

void        ft_rrb(t_sts *sts)
{
    t_stack **stack;

    stack = sts->stackA;
    stack = NULL;
    if (sts->flag)
        ft_printf("rrb:\n");
    reverseRotate(sts->stackB);
}