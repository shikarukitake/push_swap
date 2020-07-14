//
// Created by Sole Dagger on 13/02/2020.
//

//
// Created by shika on 10.02.2020.
//
#include "checker.h"

char        *getStrCommands3(int *minMeanMax, int *swap)
{

    if (swap[0] == minMeanMax[2])
    {
        if (swap[1] == minMeanMax[1])
            return ft_strdup("ra\nsa\n");
        return ft_strdup("ra\n");
    }
    else if (swap[2] == minMeanMax[0])
        return ft_strdup("rra\n");
    if (swap[1] == minMeanMax[2])
        return ft_strdup("sa\nra\n");
    return ft_strdup("sa\n");
}

t_dynamicArr    *getDArrCommands3(char *commands)
{
    int             n;
    char            *swap;
    t_dynamicArr    *dArr;
    char            *command;

    dArr = NULL;
    swap = commands;
    while(ft_strcmp(commands, ""))
    {
        n = ft_strchrn(commands, ' ');
        command = ft_strsub(commands, 0, n);
        addDArr(&dArr, checkCommand(command));
        commands = ft_strsub(commands, n + 1, ft_strlen(commands));
        free(command);
    }
    free(swap);
    return (dArr);
}

void        sortThreeElements(t_stack **stackA)
{
    int minMeanMax[3];
    int i;
    int swap[3];
    t_stack *stackSwap;
    t_dynamicArr *dArr;

    stackSwap = *stackA;
    i = 0;
    while (i != 3)
    {
        minMeanMax[i] = stackSwap->value;
        stackSwap = stackSwap->previous;
        i++;
    }
    cpyIntArray(swap, minMeanMax, 0, 3);
    if (minMeanMax[0] > minMeanMax[2])
        ft_swap(&minMeanMax[0], &minMeanMax[2]);
    if (minMeanMax[0] > minMeanMax[1])
        ft_swap(&minMeanMax[0], &minMeanMax[1]);
    if (minMeanMax[1] > minMeanMax[2])
        ft_swap(&minMeanMax[1], &minMeanMax[2]);

    printf("%s", getStrCommands3(minMeanMax, swap));
//    dArr = getDArrCommands3(getStrCommands3(minMeanMax, swap));
//    execCommands(dArr, stackA, NULL, 0);
}

void        sortFiveElements(t_stack **stackA, t_stack **stackB)
{
    return ;
}

void        sortElements(t_stack **stackA, t_stack **stackB)
{


}

void        sortStack(t_stack **stackA, t_stack **stackB)
{
    if ((*stackA)->len == 3)
        sortThreeElements(stackA);
    else if ((*stackA)->len <= 5)
        sortFiveElements(stackA, stackB);
    else
        sortElements(stackA, stackB);
}

int         main(int argc, char **argv)
{
    t_stack         *stackA;
    t_stack         *stackB;
    int             i;
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

    if (stackIsSorted(stackA) == FALSE)
        sortStack(&stackA, &stackB);
    return (0);
}