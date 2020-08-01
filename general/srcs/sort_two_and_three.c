/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_and_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:34:14 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/01 19:34:44 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Additional function to sort three items
*/

char	*get_string(t_stack *stack_swap)
{
	int min_mean_max[3];
	int i;
	int swap[3];

	i = 0;
	while (i != 3)
	{
		min_mean_max[i] = stack_swap->value;
		stack_swap = stack_swap->previous;
		i++;
	}
	cpyIntArray(swap, min_mean_max, 0, 3);
	if (min_mean_max[0] > min_mean_max[2])
		ft_swap(&min_mean_max[0], &min_mean_max[2]);
	if (min_mean_max[0] > min_mean_max[1])
		ft_swap(&min_mean_max[0], &min_mean_max[1]);
	if (min_mean_max[1] > min_mean_max[2])
		ft_swap(&min_mean_max[1], &min_mean_max[2]);
	return (get_str_commands3(min_mean_max, swap));
}

char	*sort_three(t_sts *sts, int flag)
{
	sts->commands = get_string(*(sts->stackA));
	if (!sts->commands)
		error_tf("sort_three_elements strdup malloc", FALSE);
	if (!(sts->dArr = get_darr_commands(sts->commands)))
		error_tf("sort_three_elements darr error", FALSE);
	exec_commands(sts->dArr, sts->stackA, NULL, 0);
	if (flag == 0)
		change_chr(sts->commands, ' ', '\n');
	return (sts->commands);
}

void	*sort_two(t_sts *sts)
{
	printf("sa\n");
	free_sts(sts);
	exit(0);
}
