//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

int         stack_is_sorted(t_stack *stackA)
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
    if (stack_is_sorted(stackA) AND !stackB)
        ft_printf("OK!\n");
    else
        ft_printf("KO!\n");
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

void        free_sts_stacks(const t_sts *sts)
{
    if (sts->stackA)
        if (*(sts->stackA))
            free_stack(*(sts->stackA));
    if (sts->stackB)
        if (*(sts->stackB))
            free_stack(*(sts->stackB));
}

void        free_sts(t_sts *sts)
{
    if (sts->chunks)
    {
        if (sts->chunks->array)
            free(sts->chunks->array);
        if (sts->chunks->chunk)
            free(sts->chunks->chunk);
        free(sts->chunks);
    }
    if (sts->comm)
        free(sts->comm);
    if (sts->commands)
        free(sts->commands);
//    if (sts->dArr)
//    {
//        if (sts->dArr->array)
//            free(sts->dArr->array);
//        free(sts->dArr);
//    }
    free_sts_stacks(sts);
    free(sts);
}

t_sts       *get_sts(void)
{
    t_sts *sts;
    static t_stack *stackA;
    static t_stack *stackB;

    sts = malloc(sizeof(t_sts));
    if (!sts)
        ft_error_t("init_sts_new malloc error");
    stackA = NULL;
    stackB = NULL;
    sts->stackA = &stackA;
    sts->stackB = &stackB;
    sts->dArr = NULL;
    sts->commands = NULL;
    sts->comm = NULL;
    sts->chunks = NULL;
    return (sts);
}

int         check_dublicates(t_stack *stack)
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

t_sts       *error_tf(char const *text, int init)
{
    static t_sts *sts;

    if (init) {
        sts = get_sts();
        return (sts);
    }
    free_sts(sts);
    ft_error_t(text);
    return (NULL);
}

