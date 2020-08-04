/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:57:39 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*arr_from_stack(t_stack *stack, int sort_or_not)
{
	int *array;
	int i;

	i = 0;
	if (!(array = malloc(sizeof(int) * stack->len)))
		error_tf("malloc arr_from_stack err!", FALSE);
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

void	change_chr(char *string, char f, char c)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (string[i] == f)
			string[i] = c;
		i++;
	}
}

int		binary_search(int *array, int len, int value)
{
	int	l;
	int	r;
	int	m;

	l = 0;
	r = len - 1;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (array[m] == value)
			return (m);
		if (array[m] < value)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}

/*
** Function to check if value in stack
*/

int		exist_in_stack(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (TRUE);
		stack = stack->previous;
	}
	return (FALSE);
}

int		find_id_max_in_stack(t_stack *stack)
{
	int i;
	int max;
	int max_id;

	i = 0;
	max = stack->value;
	max_id = 0;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_id = i;
		}
		i++;
		stack = stack->previous;
	}
	return (max_id);
}
