/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:58:33 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:18:46 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rrr(t_sts *sts)
{
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_CYAN);
		ft_printf("rrr:\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	if (*(sts->stacka))
		reverse_rotate(sts->stacka);
	if (*(sts->stackb))
		reverse_rotate(sts->stackb);
}

void	init_ftable(void **func_table)
{
	func_table[0] = ft_sa;
	func_table[1] = ft_sb;
	func_table[2] = ft_ss;
	func_table[3] = ft_pa;
	func_table[4] = ft_pb;
	func_table[5] = ft_ra;
	func_table[6] = ft_rb;
	func_table[7] = ft_rr;
	func_table[8] = ft_rra;
	func_table[9] = ft_rrb;
	func_table[10] = ft_rrr;
}

void	print_vc(const t_sts *sts, int i)
{
	if (sts->vflag)
	{
		if (sts->cflag)
		{
			if (i == sts->darr->len - 1)
				ft_printf(COLOR_PINK);
			else
				ft_printf(COLOR_YELLOW);
		}
		print_stacks(*(sts->stacka), *(sts->stackb));
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
}

void	exec_commands(t_sts *sts)
{
	static void		(*func_table[11])(t_sts *sts);
	int				i;

	i = 0;
	if (!(*func_table))
		init_ftable((void **)func_table);
	while (i != sts->darr->len)
	{
		func_table[sts->darr->array[i]](sts);
		print_vc(sts, i);
		i++;
	}
	free(sts->darr->array);
	sts->darr->array = NULL;
	free(sts->darr);
	sts->darr = NULL;
}
