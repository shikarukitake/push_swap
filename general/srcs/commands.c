
#include "checker.h"

void	ft_sa(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("sa:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	swap(sts->stackA);
}

void	ft_sb(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("sb:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	swap(sts->stackB);
}

void	ft_ss(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("ss:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	swap(sts->stackA);
	swap(sts->stackB);
}

void	ft_pa(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("pa:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	if (*(sts->stackB))
		push_stack(sts->stackA, pop_stack(sts->stackB));
}

void	ft_pb(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("pb:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	if (*(sts->stackA))
		push_stack(sts->stackB, pop_stack(sts->stackA));
}
