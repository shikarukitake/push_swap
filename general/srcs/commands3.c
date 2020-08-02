//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

void        ft_rrr(t_sts *sts)
{
    if (sts->flag)
        ft_printf("rrr:\n");
    reverseRotate(sts->stackA);
    reverseRotate(sts->stackB);
}

void        init_ftable(void **func_table)
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

void exec_commands(t_sts *sts)
{
    static void     (*func_table[11])(t_sts *sts);
    int             i;

    i = 0;
    if (!(*func_table))
		init_ftable((void **) func_table); //maybe need free
    while (i != sts->dArr->len)
    {
        func_table[sts->dArr->array[i]](sts);
        if (sts->flag)
			print_stacks(*(sts->stackA), *(sts->stackB) ? *(sts->stackB) : NULL);
        i++;
    }
    free(sts->dArr->array);
    free(sts->dArr);
}