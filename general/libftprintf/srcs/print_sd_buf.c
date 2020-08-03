/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sd_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:51:11 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:28:51 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_sd_buf.h"

char	prepare_sd_buf(char *digit, t_spec *spec)
{
	if (is_null_case(digit, spec))
		ft_bzero(digit, MAX_HEX_BUF_SIZE);
	if (is_need_wh(digit, spec))
	{
		ft_putchar(' ');
		spec->width.value--;
	}
	return (get_sign(digit, spec));
}

int		print_sd_buf_left(char *digit, t_spec *spec, char sign)
{
	int i;

	i = 0;
	if (get_fill_ch((int)ft_strlen(digit) + (sign > 0), spec) == ' ')
	{
		i += fill_w_field(ft_strlen(digit), spec, sign, 0);
		i += print_sign(sign);
	}
	else
	{
		i += print_sign(sign);
		i += fill_w_field(ft_strlen(digit), spec, sign, 0);
	}
	i += fill_precision_field(digit, spec);
	i += print_buf(digit);
	return (i);
}

int		print_sd_buf(char *digit, t_spec *spec)
{
	int		i;
	char	sign;

	i = 0;
	sign = prepare_sd_buf(digit, spec);
	if (spec->flags['-'] == TRUE)
	{
		i += print_sign(sign);
		i += fill_precision_field(digit, spec);
		i += print_buf(digit);
		i += fill_w_field(i, spec, 0, 0);
	}
	else
		i += print_sd_buf_left(digit, spec, sign);
	return ((is_need_wh(digit, spec) && (sign <= 0)) ? i + 1 : i);
}
