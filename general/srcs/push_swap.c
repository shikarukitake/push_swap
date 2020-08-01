/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:10:32 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/01 19:31:28 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_sts *sts)
{
	char	*commands;
	int		stack_len;

	stack_len = (*(sts->stackA))->len;
	commands = NULL;
	if (stack_len == 2)
		sort_two(sts);
	else if (stack_len == 3)
		commands = sort_three(sts, 0);
	else if (stack_len <= 5)
		commands = sort_five(sts);
	else if (stack_len <= 100)
		commands = sort_all(5, sts);
	else if (stack_len <= 500)
		commands = sort_all(11, sts);
	else
		commands = sort_all(30, sts);
	printf("%s", commands);
}

/*
** filling stack_a from program arguments
*/

void	read_args(int argc, char **argv, t_sts *sts)
{
	int i;

	i = argc == 2 ? (int)ft_w_count(argv[1], ' ') - 1 : argc - 1;
	argv = argc == 2 ? ft_strsplit(argv[1], ' ') : argv;
	argc = argc == 2 ? -1 : 0;
	sts->flag = FALSE;
	while (i != argc)
	{
		if (!ft_strcmp(argv[i], "-v"))
			sts->flag = TRUE;
		else if (isOnlyDigits(argv[i]) == FALSE)
			error_tf("There is non numeric param!", FALSE);
		else
			push_stack(sts->stackA, ft_atoi(argv[i]));
		i--;
	}
}

int		main(int argc, char **argv)
{
	t_sts			*sts;

	sts = error_tf(NULL, TRUE);
	if (argc == 1)
		return (0);
	else
		read_args(argc, argv, sts);
	if (check_dublicates(*(sts->stackA)))
		error_tf("There are dublicates\n", FALSE);
	if (!stack_is_sorted(*(sts->stackA)))
		sort_stack(sts);
	free_sts(sts);
	return (0);
}
