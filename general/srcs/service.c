//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

//void        ft_error(void)
//{
//    write(2, "Error\n", 6);
//    exit(1);
//}
//
//void        ft_errorText(char const *text)
//{
//    write(2, "Error: ", 7);
//    write(2, text, ft_strlen(text));
//    exit(1);
//}

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
        printf("OK!\n");
    else
        printf("KO!\n");
}

int         isOnlyDigits(char *s)
{
    int i;

    i = 0;
    if (s[0] == '-')
    {
        if (ft_strlen(s) == 1)
            return (FALSE);
        i = 1;
    }
    while (s[i])
    {
        if (ft_isdigit(s[i]) == FALSE)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

