//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

void        error(void)
{
    write(2, "Error\n", 6);
    exit(1);
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

