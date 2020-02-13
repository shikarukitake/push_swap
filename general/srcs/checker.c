//
// Created by shika on 10.02.2020.
//
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
        flag = 0;
        if (!ft_strcmp(argv[1], "-v"))
            flag = 1;
        i = argc - 1;
        while (i != flag)
        {
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
    execCommands(dArr, &stackA, &stackB, flag);
    checkSorted(stackA, stackB);
    return (0);
}