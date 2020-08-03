/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:59:12 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:42:44 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (*(sts->stacka))
		swap(sts->stacka);
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
	if (*(sts->stackb))
		swap(sts->stackb);
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
	if (*(sts->stacka))
		swap(sts->stacka);
	if (*(sts->stackb))
		swap(sts->stackb);
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
	if (*(sts->stackb))
		push_stack(sts->stacka, pop_stack(sts->stackb));
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
	if (*(sts->stacka))
		push_stack(sts->stackb, pop_stack(sts->stacka));
}
