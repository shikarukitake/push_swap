/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:57:53 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/04 16:26:10 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			cpy_intarray(int *dest, int *src, int freeornot, int len)
{
	int i;

	i = 0;
	if (dest)
		while (i != len)
		{
			dest[i] = src[i];
			i++;
		}
	if (freeornot)
		free(src);
}

t_dynamicarr	*init_darrfromint(int *array, int len)
{
	t_dynamicarr	*new;
	int				i;

	new = NULL;
	if (len > 0)
	{
		i = 0;
		while (i != len)
		{
			add_darr(&new, array[i]);
			i++;
		}
	}
	return (new);
}

int				init_darr(t_dynamicarr **arr)
{
	int *swap;

	if (arr)
	{
		if (*arr)
		{
			swap = (*arr)->array;
			if (!((*arr)->array = (int*)malloc(sizeof(int) *
					(((*arr)->len * 2) + 2))))
				return (0);
			cpy_intarray((*arr)->array, swap, 1, (*arr)->len);
			(*arr)->freespace = (*arr)->len;
		}
		else
		{
			(*arr) = (t_dynamicarr*)malloc(sizeof(t_dynamicarr));
			if (!(*arr))
				return (0);
			(*arr)->array = (int*)malloc(sizeof(int) * 102);
			if (!(*arr)->array)
				return (0);
			(*arr)->len = 0;
			(*arr)->freespace = 100;
		}
	}
	return (1);
}

int				add_darr(t_dynamicarr **arr, int value)
{
	if (arr)
	{
		if (!(*arr))
			if (!init_darr(arr))
				return (0);
		if (!(*arr)->freespace)
			if (!init_darr(arr))
				return (0);
		(*arr)->array[(*arr)->len] = value;
		(*arr)->len += 1;
		(*arr)->freespace -= 1;
	}
	return (1);
}

void			print_darr(t_dynamicarr *arr)
{
	int i;

	i = 0;
	while (i != arr->len)
		ft_printf("%d ", arr->array[i++]);
	ft_printf("\n");
}
