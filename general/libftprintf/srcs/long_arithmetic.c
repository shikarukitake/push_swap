/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:42:31 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:44:49 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long_arithmetic.h"

void		multiply_by_2(char *buf, int size, unsigned n)
{
	int			carry;
	int			i;
	unsigned	p;

	p = 0;
	while (p < n)
	{
		carry = 0;
		i = 0;
		while (i < size)
		{
			carry = carry + buf[i] * 2;
			buf[i] = carry % 10;
			carry /= 10;
			i++;
		}
		p++;
	}
}

void		set_res(char *result, int i, int swap, int direct)
{
	if (swap < 10)
		result[i] = swap;
	else
	{
		result[i] = swap - 10;
		if (i != 0 && direct)
			set_res(result, i - 1, result[i - 1] + 1, direct);
		else if (direct == 0)
			set_res(result, i + 1, result[i + 1] + 1, direct);
	}
}

void		long_sum(char *to_sum, char *result, int n, int direct)
{
	int i;
	int swap;

	i = 0;
	while (i != n)
	{
		swap = result[i] + to_sum[i];
		if (swap != 0 && to_sum[i] != 0)
			set_res(result, i, swap, direct);
		i++;
	}
}

void		divide_by_2(char *divided, int n)
{
	int i;

	i = 0;
	while (i != n)
	{
		if (divided[i] % 2 == 1)
			divided[i + 1] += 10;
		divided[i] /= 2;
		i++;
	}
}

void		rev_divide_by_2(char *divided, int n)
{
	int i;

	i = n - 1;
	if (divided[0] == 1 && divided[1] == 0)
		return ;
	while (i >= 0)
	{
		if (divided[i] == 0)
		{
			i--;
			continue;
		}
		if (divided[i] % 2 == 1 && i != 0)
			divided[i - 1] += 10;
		divided[i] /= 2;
		i--;
	}
}
