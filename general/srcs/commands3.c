
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
	reverse_rotate(sts->stackA);
	reverse_rotate(sts->stackB);
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
			if (i == sts->dArr->len - 1)
				ft_printf(COLOR_PINK);
			else
				ft_printf(COLOR_YELLOW);
		}
		print_stacks(*(sts->stackA), *(sts->stackB));
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
	while (i != sts->dArr->len)
	{
		func_table[sts->dArr->array[i]](sts);
		print_vc(sts, i);
		i++;
	}
	free(sts->dArr->array);
	free(sts->dArr);
}
