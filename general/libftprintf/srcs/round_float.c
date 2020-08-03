/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:30:11 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 16:40:37 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "round_float.h"

void		change_first_digits(char *buf)
{
	char tmp[MAX_LD_BUF_SIZE];

	ft_strcpy(tmp, buf);
	if (tmp[0] != '-')
	{
		ft_strcpy(buf, "10");
		ft_strcat(buf, tmp + 1);
	}
	else
	{
		ft_strcpy(buf, "-10");
		ft_strcat(buf, tmp + 2);
	}
}

void		round_int_part(char *buf)
{
	int i;
	int is_sign;

	i = ft_strchri(buf, '.');
	is_sign = (buf[0] == '-');
	i--;
	while (i >= is_sign)
	{
		if (buf[i] == '9')
			buf[i] = '0';
		else
		{
			buf[i] += 1;
			break ;
		}
		i--;
	}
	if (i == -1 + is_sign && buf[is_sign] == '0')
		change_first_digits(buf);
}

int			round_float_part(char *buf, int i, int last, char n)
{
	if (buf[i] > n && buf[i - 1] != '.')
	{
		i--;
		if (buf[i] != '9')
			buf[i] += 1;
		else if (buf[i] == '9')
		{
			buf[i--] = '0';
			while (buf[i] == '9')
				buf[i--] = '0';
			if (buf[i] != '.')
				buf[i] += 1;
			else
				round_int_part(buf);
		}
		buf[last] = '\0';
		return (1);
	}
	return (0);
}

void		round_float(char *buf, int precision, char n)
{
	int i;
	int last;

	i = (int)ft_strchri(buf, '.') + precision + 1;
	buf[i + 1] = '\0';
	last = i;
	if (round_float_part(buf, i, last, n))
		return ;
	if (buf[i] > n && buf[i - 1] == '.')
		round_int_part(buf);
	buf[last] = '\0';
}
