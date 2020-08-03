/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:42:05 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:42:14 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_e_buf.h"

int		float_shift_left_one(char *e)
{
	int		begin;
	int		i;

	begin = (e[0] == '-' ? 2 : 1);
	e[begin - 1] = e[begin + 1];
	i = begin + 1;
	while (e[i + 1])
	{
		e[i] = e[i + 1];
		i++;
	}
	return (0);
}

int		str_shift_left(char *buf, int from, int to)
{
	int		i;
	char	temp;

	i = from;
	while (i != to)
	{
		temp = buf[i - 1];
		buf[i - 1] = buf[i];
		buf[i] = temp;
		i--;
	}
	return (0);
}

int		float_shift_left_n(char *e, int exp)
{
	int	begin;
	int	i;

	exp = -exp;
	begin = (e[0] == '-' ? 2 : 1);
	e[begin - 1] = e[begin + (exp)];
	i = begin + (exp);
	while (e[i + 1])
	{
		e[i - exp + 1] = e[i + 1];
		e++;
	}
	return (0);
}

int		place_dot(char *e, int exp)
{
	int		begin;

	if (exp == 0)
		return (0);
	begin = (e[0] == '-' ? 2 : 1);
	if (exp > 0)
		str_shift_left(e, (int)ft_strchri(e, '.'), begin);
	else if (exp == -1)
		float_shift_left_one(e);
	else
		float_shift_left_n(e, exp);
	return (0);
}

int		print_e_buf(char *e, t_spec *spec, char a, t_ld *ld)
{
	int		exp;
	int		i;
	char	tmp[2];

	i = 0;
	exp = get_exp(e);
	place_dot(e, exp);
	round_float(e, get_float_precision(spec), ld->round);
	exp = check_carry(e, exp);
	add_zeros(e, spec);
	modify_g_buf(e, spec);
	tmp[0] = a;
	tmp[1] = '\0';
	ft_strcat(e, tmp);
	add_exp(exp, e);
	i += print_f_buf(e, spec, get_sign(e, spec), (e[ft_strlen(e) - 1] == '.'));
	return (i);
}
