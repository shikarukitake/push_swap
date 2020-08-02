/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:45:40 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 15:47:16 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_float.h"

int		ft_print_f(t_spec *spec, va_list *args)
{
	char	*buffer;
	int		count;
	t_ld	ld;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	ld = get_general_float(args, spec, buffer);
	count = print_f(buffer, spec, &ld);
	free(buffer);
	return (count);
}

int		ft_print_e(t_spec *spec, va_list *args)
{
	char	*buffer;
	int		count;
	t_ld	ld;

	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	ld = get_general_float(args, spec, buffer);
	ld.round = '5';
	count = print_e_buf(buffer, spec, spec->type, &ld);
	free(buffer);
	return (count);
}

int		ft_print_g(t_spec *spec, va_list *args)
{
	char	*buffer;
	int		count;
	t_ld	ld;
	int		p;
	int		x;

	p = (spec->precision.value == 0 ? 1 : get_float_precision(spec));
	buffer = ft_memalloc(MAX_LD_BUF_SIZE + 10);
	ld = get_general_float(args, spec, buffer);
	x = get_exp(buffer);
	if (p > x && x >= -4)
	{
		spec->precision.value = p - (x + 1);
		count = print_f(buffer, spec, &ld);
	}
	else
	{
		ld.round = '5';
		spec->precision.value = p - 1;
		count = print_e_buf(buffer, spec, spec->type == 'g' ? 'e' : 'E', &ld);
	}
	free(buffer);
	return (count);
}
