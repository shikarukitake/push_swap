/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:46:40 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:48:20 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_digit.h"

void	get_general_d(va_list *vargs, t_conv *conv, t_spec *spec, char *buf)
{
	if (spec->size.id == -1)
		ft_itoa_base(va_arg(*vargs, int), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		ft_lltoa_base(va_arg(*vargs, long long), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'l')
		ft_lltoa_base(va_arg(*vargs, long), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'h' && spec->size.value[1] == 'h')
		ft_itoa_base((char)va_arg(*vargs, int), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'h')
		ft_itoa_base((short)va_arg(*vargs, int), buf, conv->base, conv->a);
}

void	get_general_ud(va_list *vargs, t_conv *conv, t_spec *spec, char *buf)
{
	if (spec->size.id == -1)
		ft_uitoa_base(va_arg(*vargs, t_ui), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'l' && spec->size.value[1] == 'l')
		ft_ulltoa_base(va_arg(*vargs, t_ull), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'l')
		ft_ulltoa_base(va_arg(*vargs, t_ul), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'h' && spec->size.value[1] == 'h')
		ft_uitoa_base((t_uc)va_arg(*vargs, int), buf, conv->base, conv->a);
	else if (spec->size.value[0] == 'h')
		ft_uitoa_base((t_us)va_arg(*vargs, int), buf, conv->base, conv->a);
}

void	get_general_ptr(va_list *vargs, t_conv *conv, t_spec *spec, char *buf)
{
	((void)spec);
	ft_ulltoa_base((size_t)va_arg(*vargs, size_t*), buf, conv->base, conv->a);
}
