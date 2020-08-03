//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

void        ft_sa(t_sts *sts)
{
    if (sts->flag)
        ft_printf("sa:\n");
    swap(sts->stackA);
}

void        ft_sb(t_sts *sts)
{
    if (sts->flag)
        ft_printf("sb:\n");
    swap(sts->stackB);
}

void        ft_ss(t_sts *sts)
{
    if (sts->flag)
        ft_printf("ss:\n");
    swap(sts->stackA);
    swap(sts->stackB);
}

void        ft_pa(t_sts *sts)
{
    if (sts->flag)
        ft_printf("pa:\n");
    if (*(sts->stackB))
        push_stack(sts->stackA, pop_stack(sts->stackB));
}

void        ft_pb(t_sts *sts)
{
    if (sts->flag)
        ft_printf("pb:\n");
    if (*(sts->stackA))
        push_stack(sts->stackB, pop_stack(sts->stackA));
}