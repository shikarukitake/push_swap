//
// Created by shika on 10.02.2020.
//
/*
 * dArr - variable for commands from user input (like ra, sa)
 * flag - variable for option -v that can display the stack’s status after each operation
 */
#include "checker.h"

int *arr_from_stack(t_stack *stack, int sortOrNot)
{
    int *array;
    int i;

    i = 0;
    if (!(array = malloc(sizeof(int) * stack->len)))
        ft_error_t("malloc arr_from_stack err!\n");
    while (stack)
    {
        array[i] = stack->value;
        stack = stack->previous;
        i++;
    }

    if (sortOrNot)
        ft_quicksort(array, 0, i - 1);
    return (array);
}

int check_dublicates(t_stack *stack)
{
    int *array;
    int i;
    int previous;

    i = 1;
    array = arr_from_stack(stack, TRUE);
    previous = array[0];
    while (i != stack->len)
    {
        if (array[i] == previous)
            return (TRUE);
        previous = array[i];
        i++;
    }
    free(array);
    return (FALSE);
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
        i = argc == 2 ? (int)ft_w_count(argv[1], ' ') -1 : argc - 1;
        argv = argc == 2 ? ft_strsplit(argv[1], ' ') : argv;
        argc = argc == 2 ? -1 : 0;
        flag = 0;


        while (i != argc)
        {
            if (!ft_strcmp(argv[i], "-v"))
                flag = 1;
            else if (isOnlyDigits(argv[i]) == FALSE)
                ft_error_t("There is non numeric parametr\n");
            else
                push_stack(&stackA, ft_atoi(argv[i]));
            i--;
        }
    }

    IF_TRUE(check_dublicates(stackA), ft_error_t("There are dublicates"));
    readingFromSTDIN(&dArr);

    if (flag)
        printTwoStacks(stackA, stackB);
    /*
     * dArr may be empty (NULL)
     */
    if (dArr)
        exec_commands(dArr, &stackA, &stackB, flag);
    checkSorted(stackA, stackB);
    return (0);
}