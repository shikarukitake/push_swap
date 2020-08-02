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

int         main(int argc, char **argv)
{
	t_sts			*sts;

	sts = error_tf(NULL, TRUE);
	if (argc == 1)
		return (0);
	else
		read_args(argc, argv, sts);
	if (check_dublicates(*(sts->stackA)))
		error_tf("There are dublicates\n", FALSE);
	reading_from_stdin(&(sts->dArr));

    if (sts->flag)
		print_stacks(*(sts->stackA), *(sts->stackB));
    /*
     * dArr may be empty (NULL)
     */
    if (sts->dArr)
		exec_commands(sts);
    checkSorted(*(sts->stackA), *(sts->stackB));
    return (0);
}