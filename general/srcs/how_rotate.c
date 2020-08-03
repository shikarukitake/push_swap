
#include "push_swap.h"

void		init_findnexta(const t_sts *sts,
		int value, int *index, t_stack **stack)
{
	(*stack) = *(sts->stackA);
	(*index) = binary_search(sts->chunks->array, sts->chunks->len, value) + 1;
	if (smaller_or_greater((*stack), value))
		(*index) = 0;
}

/*
** The function find next number for current value in stackA
** The next number is the element before which you need to put a value
*/

int			find_next_stacka(t_sts *sts, int value)
{
	int		index;
	t_stack	*stack;
	int		i;

	init_findnexta(sts, value, &index, &stack);
	while (index != sts->chunks->len)
	{
		if (exist_in_stack(stack, sts->chunks->array[index]) == TRUE)
			break ;
		index++;
	}
	i = 0;
	while (stack)
	{
		if (stack->value == sts->chunks->array[index])
			return (i);
		i++;
		stack = stack->previous;
	}
	error_tf("Cant find the next number in find_next_stacka function", FALSE);
	return (0);
}

void		init_findnext(const t_sts *sts, int value,
		int *index, t_stack **stack)
{
	(*stack) = *(sts->stackB);
	(*index) = binary_search(sts->chunks->array, sts->chunks->len, value) - 1;
	if (smaller_or_greater((*stack), value))
		(*index) = sts->chunks->len - 1;
}

/*
** The function find next number for current value in stackB
** The next number is the element before which you need to put a value
*/

int			find_next_stackb(t_sts *sts, int value)
{
	int		index;
	t_stack	*stack;
	int		i;

	init_findnext(sts, value, &index, &stack);
	while (index >= 0)
	{
		if (exist_in_stack(stack, sts->chunks->array[index]) == TRUE)
			break ;
		index--;
	}
	i = 0;
	while (stack)
	{
		if (stack->value == sts->chunks->array[index])
			return (i);
		i++;
		stack = stack->previous;
	}
	error_tf("Cant find the next number in find_next_stacka function\n", FALSE);
	return (0);
}

t_command	*ra_or_rra(t_sts *sts, int value)
{
	int			len_of_stacka;
	t_command	*comm;
	int			i;

	i = 0;
	len_of_stacka = (*(sts->stackA))->len;
	if (!(comm = (t_command*)malloc(sizeof(t_command))))
		error_tf("ra_or_rra malloc ft_error", FALSE);
	i = find_next_stacka(sts, value);
	comm->command = i <= len_of_stacka - i ? "ra " : "rra ";
	comm->count = i <= len_of_stacka - i ? i : len_of_stacka - i;
	return (comm);
}

t_command	*rb_or_rrb(t_sts *sts, int value)
{
	int			len_of_stacka;
	t_command	*comm;
	int			i;

	i = 0;
	if (!(comm = (t_command*)malloc(sizeof(t_command))))
		error_tf("rb_or_rrb malloc ft_error", FALSE);
	if ((*(sts->stackB)) == NULL)
	{
		comm->count = 0;
		return (comm);
	}
	len_of_stacka = (*(sts->stackB))->len;
	i = find_next_stackb(sts, value);
	comm->command = i <= len_of_stacka - i ? "rb " : "rrb ";
	comm->count = i <= len_of_stacka - i ? i : len_of_stacka - i;
	return (comm);
}

void		do_r_or_rr(t_sts *sts, int value, char *pa_or_pb)
{
	t_command	*comm;
	char		*commas;

	if (!ft_strcmp(pa_or_pb, "pa "))
		comm = ra_or_rra(sts, value);
	else
		comm = rb_or_rrb(sts, value);
	commas = commands_from_tcomm(comm, pa_or_pb);
	free(comm);
	if (!(sts->dArr = get_darr_commands(commas)))
		error_tf("do_r_or_rr getdarrcommands error", FALSE);
	exec_commands(sts);
	if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
		error_tf("do_r_or_rr ft_strjoin free error", FALSE);
}
