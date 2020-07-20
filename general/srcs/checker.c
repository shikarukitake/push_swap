//
// Created by shika on 10.02.2020.
//
/*
 * dArr - variable for commands from user input (like ra, sa)
 * flag - variable for option -v that can display the stack’s status after each operation
 */
#include "checker.h"

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
    /*
     * dArr may be empty (NULL)
     */
    if (dArr)
        execCommands(dArr, &stackA, &stackB, flag);
    checkSorted(stackA, stackB);
    return (0);
}