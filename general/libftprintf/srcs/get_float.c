/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:21:01 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 18:24:54 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_float.h"

static int	is_double(t_spec *spec)
{
	return (spec->size.id == -1 ||
			spec->size.value[0] == 'l' ||
			spec->size.value[0] == 'h');
}

t_ld		get_general_float(va_list *va_args, t_spec *spec, char *buffer)
{
	t_ld	ld;

	ld.value = 0.0;
	ld.round = '4';
	if (is_double(spec))
		ld.value = (long double)va_arg(*va_args, double);
	else if (spec->size.value[0] == 'L')
		ld.value = va_arg(*va_args, long double);
	ft_ldtoa(&ld, buffer);
	return (ld);
}
