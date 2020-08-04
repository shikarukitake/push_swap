/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:00:04 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_float_part.h"

void	get_float_bits(unsigned long m, unsigned e, char *buf, int flag)
{
	t_ul	mask;
	t_ui	i;

	mask = 1u;
	i = 0;
	if (flag)
		mask = mask << (63lu - (e + 1u));
	else
		mask <<= 63u;
	while (mask)
	{
		if (m & mask)
			buf[i++] = '1';
		else
			buf[i++] = '0';
		mask >>= 1;
	}
	buf[i] = '\0';
}

void	transform_float_part(const char *float_part, int n, char *buf)
{
	int i;

	i = 0;
	while (i < n)
	{
		buf[i] = (char)(float_part[i] + '0');
		i++;
	}
	buf[i] = '\0';
}

void	add_float_zeros(char *buf, unsigned exp)
{
	char	*zeros;

	zeros = ft_memalloc(MAX_F_BUF_SIZE);
	while (exp != 1)
	{
		ft_strcat(zeros, "0");
		exp--;
	}
	ft_strcat(zeros, buf);
	ft_strcpy(buf, zeros);
	free(zeros);
}

void	get_float_part(unsigned long m, unsigned exp, char *buf, int flag)
{
	char			bin_buf[MAX_F_BUF_SIZE];
	t_ull			i;
	unsigned int	n;
	char			*divided;
	char			*result;

	i = 0;
	ft_bzero(bin_buf, MAX_F_BUF_SIZE);
	get_float_bits(m, exp, bin_buf, flag);
	if (flag == 0)
		add_float_zeros(bin_buf, exp);
	n = 0.3 * exp + 800;
	divided = ft_memalloc(n);
	result = ft_memalloc(n);
	divided[0] = 5;
	while (bin_buf[i])
	{
		if (bin_buf[i] == '1')
			long_sum(divided, result, n, 1);
		i++;
		divide_by_2(divided, n);
	}
	transform_float_part(result, n, buf);
	free(divided);
	free(result);
}
