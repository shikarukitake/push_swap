/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:03:01 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:25:22 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_digit_buf.h"

int		check_is_prefix(char *digit, t_spec *spec, t_put_prefix pp)
{
	char	dest[4];
	int		is_prefix;

	ft_bzero(dest, 4);
	if (is_null_case(digit, spec))
	{
		ft_bzero(digit, MAX_HEX_BUF_SIZE);
		if (spec->type != 'p')
			return (0);
	}
	is_prefix = pp(digit, spec, dest);
	if (is_prefix)
		return (ft_strlen(dest));
	else
		return (0);
}

int		prepare_pbuf(char *digit, t_spec *spec, char *dig_buf, t_put_prefix p)
{
	int was_prefix;

	ft_bzero(dig_buf, MAX_HEX_BUF_SIZE);
	if (is_null_case(digit, spec))
	{
		ft_bzero(digit, MAX_HEX_BUF_SIZE);
		if (spec->type != 'p')
			return (0);
	}
	was_prefix = p(digit, spec, dig_buf);
	ft_strcat(dig_buf, digit);
	return (was_prefix);
}

int		fill_prec_and_print(char *digit, char *pdigit, t_spec *spec)
{
	int i;

	i = 0;
	i += fill_precision_field((spec->type == 'o' ? pdigit : digit), spec);
	i += print_buf(digit);
	return (i);
}

int		print_d_buf_left(t_d_pair *p, t_spec *spec, t_put_prefix pp, int is_p)
{
	int i;

	i = 0;
	if (is_p && spec->flags['0'] == TRUE)
	{
		if (get_fill_ch(ft_strlen(p->d), spec) == ' ')
		{
			i += fill_w_field((int)ft_strlen(p->d), spec, 0, is_p);
			i += pp(p->d, spec, NULL);
		}
		else
		{
			i += pp(p->d, spec, NULL);
			i += fill_w_field((int)ft_strlen(p->d), spec, 0, is_p);
		}
		i += fill_prec_and_print(p->d, p->pd, spec);
	}
	else
	{
		i += fill_w_field(ft_strlen(p->d), spec, 0, is_p);
		if (is_p)
			i += pp(p->d, spec, NULL);
		i += fill_prec_and_print(p->d, p->pd, spec);
	}
	return (i);
}

int		print_d_buf(char *digit, t_spec *spec, t_put_prefix pp)
{
	int			i;
	int			is_prefix;
	char		prefixd[MAX_HEX_BUF_SIZE];
	t_d_pair	pair;

	i = 0;
	is_prefix = check_is_prefix(digit, spec, pp);
	prepare_pbuf(digit, spec, prefixd, pp);
	if (spec->flags['-'] == TRUE)
	{
		if (is_prefix)
			i += pp(digit, spec, NULL);
		i += fill_precision_field((spec->type == 'o' ? prefixd : digit), spec);
		i += print_buf(digit);
		i += fill_w_field(i, spec, 0, 0);
	}
	else
	{
		pair.d = digit;
		pair.pd = prefixd;
		i += print_d_buf_left(&pair, spec, pp, is_prefix);
	}
	return (i);
}
