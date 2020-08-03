/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:59:19 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:42:21 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (*(sts->stacka))
		rotate(sts->stacka);
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
	if (*(sts->stackb))
		rotate(sts->stackb);
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
	if (*(sts->stacka))
		rotate(sts->stacka);
	if (*(sts->stackb))
		rotate(sts->stackb);
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
	if (*(sts->stacka))
		reverse_rotate(sts->stacka);
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
	if (*(sts->stackb))
		reverse_rotate(sts->stackb);
}
