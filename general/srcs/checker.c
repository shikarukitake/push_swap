//
// Created by shika on 10.02.2020.
//


#include "checker.h"


//typedef struct  s_stack
//{
//    struct s_stack *previous;
//    int     value;
//}               t_stack;

int         isOnlyDigits(char *s)
{
    int i;

    i = 0;

    while (s[i])
    {
        if (ft_isdigit(s[i]) == FALSE AND (s[i] == '-' AND i != 0))
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int         checkCommand(char *command)
{
    if (!ft_strcmp(command, "sa"))
        return (0);
    else if (!ft_strcmp(command, "sb"))
        return (1);
    else if (!ft_strcmp(command, "ss"))
        return (2);
    else if (!ft_strcmp(command, "pa"))
        return (3);
    else if (!ft_strcmp(command, "pb"))
        return (4);
    else if (!ft_strcmp(command, "ra"))
        return (5);
    else if (!ft_strcmp(command, "rb"))
        return (6);
    else if (!ft_strcmp(command, "rr"))
        return (7);
    else if (!ft_strcmp(command, "rra"))
        return (8);
    else if (!ft_strcmp(command, "rrb"))
        return (9);
    else if (!ft_strcmp(command, "rrr"))
        return (10);
    else
        return (-1);
}

void        error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void        readingFromSTDIN(t_dynamicArr    **dArr)
{
    char			buff[BUFF_SIZE + 1];
    char            *all;
    int             ret;
    int             command;

    all = ft_strnew(1);
    while ((ret = read(0, buff, BUFF_SIZE)) > 0)
    {
        buff[ret] = 0;
        command = checkCommand(ft_strsub(buff, 0, ft_strchrn(buff, '\n')));
        if (command == -1)
            error();
        else
            addDArr(dArr, command);
        if (!(all = ft_strjoin_free(all, buff, 1)))
            exit(1);
    }
}

void        ft_sa(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("sa:\n");
    swap(stackA);
}

void        ft_sb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("sb:\n");
    swap(stackB);
}

void        ft_ss(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("ss:\n");
    swap(stackA);
    swap(stackB);
}

void        ft_pa(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("pa:\n");
    pushStack(stackA, popStack(stackB));
}

void        ft_pb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("pb:\n");
    pushStack(stackB, popStack(stackA));
}

void        ft_ra(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("ra:\n");
    rotate(stackA);
}

void        ft_rb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rb:\n");
    rotate(stackB);
}

void        ft_rr(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rr:\n");
    rotate(stackA);
    rotate(stackB);
}

void        ft_rra(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rra:\n");
    reverseRotate(stackA);
}

void        ft_rrb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("rrb:\n");
    reverseRotate(stackB);
}

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
    initFTable((void**)func_table);
    while (i != dArr->len)
    {
        func_table[dArr->array[i]](stackA, stackB, flag);
        if (flag)
        {
            printTwoStacks(*stackA, *stackB);
            printf("\n");
        }
        i++;
    }
}

int         stackIsSorted(t_stack *stackA)
{
    int previous;

    previous = stackA->value;
    stackA = stackA->previous;
    while (stackA)
    {
        if (stackA->value < previous)
            return (FALSE);
        previous = stackA->value;
        stackA = stackA->previous;
    }
    return (TRUE);
}

void        checkSorted(t_stack *stackA, t_stack *stackB)
{
    if (stackIsSorted(stackA) AND !stackB)
        printf("OK!");
    else
        printf("KO!");
}

int         main(int argc, char **argv)
{
    t_stack         *stackA;
    t_stack         *stackB;
    int             i;
    t_dynamicArr    *dArr;
    int             flag;

    stackA = NULL;
    stackB = NULL;
    if (argc == 1)
        return (0);
    else
    {
        /*
         *  Filling stackA from program arguments
         */
        flag = 0;
        if (!ft_strcmp(argv[1], "-v"))
            flag = 1;
        i = argc - 1;
        while (i != flag)
        {
            if (argv[0])
            if (isOnlyDigits(argv[i]) == FALSE)
            {
                printf("Error\n");
                return (0);
            }
            else
                pushStack(&stackA, ft_atoi(argv[i]));
            i--;
        }
    }


    readingFromSTDIN(&dArr);
    if (flag)
        printTwoStacks(stackA, stackB);
    printf("\n");
    execCommands(dArr, &stackA, &stackB, flag);
    checkSorted(stackA, stackB);
    return (0);
}