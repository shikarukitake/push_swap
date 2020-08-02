/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:59:09 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 17:59:41 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_int_part.h"

void	transform_long_result(char *buf, char *new_buf, int n)
{
	int i;
	int j;
	int last;

	last = n - 1;
	while (last > 0 && buf[last] == 0)
		last--;
	i = last;
	j = 0;
	while (i >= 0)
	{
		new_buf[j++] = (char)(buf[i] + '0');
		i--;
	}
	new_buf[j] = '\0';
}

t_ul	prepare_vars(char *int_part, char *result, int *was_mult, t_ui *e)
{
	t_ul mask;

	(*e)++;
	ft_memset(result, 0, MAX_F_BUF_SIZE);
	*was_mult = 0;
	int_part[0] = 1;
	mask = 1u;
	mask <<= 63lu;
	return (mask);
}

void	get_int_part(unsigned long m, unsigned e, char *buf)
{
	char			int_part[MAX_F_BUF_SIZE];
	char			result[MAX_F_BUF_SIZE];
	unsigned long	mask;
	int				was_mult;

	mask = prepare_vars(int_part, result, &was_mult, &e);
	while (e)
	{
		if ((mask & m) > 0)
		{
			if (!was_mult)
			{
				ft_memset(int_part, 0, MAX_F_BUF_SIZE);
				int_part[0] = 1;
				multiply_by_2(int_part, MAX_F_BUF_SIZE, e - 1);
				was_mult = 1;
			}
			long_sum(int_part, result, MAX_F_BUF_SIZE, 0);
		}
		if (was_mult)
			rev_divide_by_2(int_part, MAX_F_BUF_SIZE);
		mask >>= 1u;
		e--;
	}
	transform_long_result(result, buf, MAX_F_BUF_SIZE);
}
