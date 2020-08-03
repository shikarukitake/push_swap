
#include "checker.h"

void	ft_ra(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("ra:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	rotate(sts->stackA);
}

void	ft_rb(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("rb:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	rotate(sts->stackB);
}

void	ft_rr(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("rr:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	rotate(sts->stackA);
	rotate(sts->stackB);
}

void	ft_rra(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("rra:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	reverse_rotate(sts->stackA);
}

void	ft_rrb(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("rrb:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	reverse_rotate(sts->stackB);
}
