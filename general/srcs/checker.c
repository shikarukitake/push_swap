
#include "checker.h"

int		*arr_from_stack(t_stack *stack, int sort_or_not)
{
	int	*array;
	int	i;

	i = 0;
	if (!(array = malloc(sizeof(int) * stack->len)))
		ft_error_t("malloc arr_from_stack err!\n");
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->previous;
		i++;
	}
	if (sort_or_not)
		ft_quicksort(array, 0, i - 1);
	return (array);
}

int		main(int ac, char **av)
{
	t_sts	*sts;

	sts = error_tf(NULL, TRUE);
	if (ac == 1)
		return (0);
	else
		read_args(ac, av, sts);
	if (check_dublicates(*(sts->stackA)))
		error_tf("There are dublicates!", FALSE);
	reading_from_stdin(&(sts->dArr));
	if (sts->flag)
		print_stacks(*(sts->stackA), *(sts->stackB));
	if (sts->dArr)
		exec_commands(sts);
	checkSorted(*(sts->stackA), *(sts->stackB));
	free_sts(sts);
	return (0);
}
