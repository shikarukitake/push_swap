//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

void        ft_rrr(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rrr:\n");
    reverseRotate(stackA);
    reverseRotate(stackB);
}

void        initFTable(void **func_table)
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

void        execCommands(t_dynamicArr *dArr, t_stack **stackA, t_stack **stackB, int flag)
{
    static void     (*func_table[11])(t_stack **stackA, t_stack **stackB, int flag);
    int             i;

    i = 0;
    if (!(*func_table))
        initFTable((void**)func_table); //maybe need free
    while (i != dArr->len)
    {
        func_table[dArr->array[i]](stackA, stackB, flag);
        if (flag)
            printTwoStacks(*stackA, stackB ? *stackB : NULL);
        i++;
    }

}