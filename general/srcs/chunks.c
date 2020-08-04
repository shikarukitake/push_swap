/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:58:25 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			exists_in_chunk(t_stack *stack, t_chunks *chunks)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (chunks->chunk[i] != chunks->current_c)
			i++;
		while (chunks->chunk[i] == chunks->current_c)
		{
			if (stack->value == chunks->array[i])
				return (TRUE);
			i++;
		}
		stack = stack->previous;
	}
	return (FALSE);
}

int			value_in_chunk(t_chunks *chunks, int value)
{
	int	index;

	index = binary_search(chunks->array, chunks->len, value);
	if (chunks->chunk[index] == chunks->current_c)
		return (index);
	else
		return (-1);
}

static void	fill_first(const t_chunks *chunks,
		int first, int *i, int *chunk_number)
{
	(*i) = 0;
	while (first)
	{
		chunks->chunk[(*i)++] = 0;
		first--;
	}
	(*chunk_number) = 1;
}

void		create_chunks_arr(t_chunks *chunks, int how_many_chunks)
{
	int	first;
	int	other;
	int	i;
	int	chunk_number;

	first = chunks->len % how_many_chunks + chunks->len / how_many_chunks;
	other = chunks->len / how_many_chunks;
	fill_first(chunks, first, &i, &chunk_number);
	how_many_chunks--;
	while (how_many_chunks)
	{
		first = 0;
		while (first != other)
		{
			chunks->chunk[i] = chunk_number;
			first++;
			i++;
		}
		chunk_number++;
		how_many_chunks--;
	}
}

t_chunks	*fill_chunks(t_stack *stack, int how_many_chunks)
{
	t_chunks	*chunks;
	int			i;

	chunks = init_chunks(stack->len);
	i = 0;
	chunks->len = stack->len;
	while (i != chunks->len)
	{
		chunks->array[i] = stack->value;
		stack = stack->previous;
		i++;
	}
	ft_quicksort(chunks->array, 0, chunks->len - 1);
	create_chunks_arr(chunks, how_many_chunks);
	return (chunks);
}
