/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:40:33 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:41:23 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_basic.h"

int		ft_print_d(t_spec *spec, va_list *args)
{
	char	buffer[MAX_LL_BUFF_SIZE];
	t_conv	conv;

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	conv = (t_conv){10, 'a'};
	get_general_d(args, &conv, spec, buffer);
	return (print_sd_buf(buffer, spec));
}

int		ft_print_p(t_spec *spec, va_list *args)
{
	char	buffer[MAX_P_BUFF_SIZE];
	t_conv	conv;

	ft_bzero(buffer, MAX_P_BUFF_SIZE);
	conv = (t_conv){16, 'a'};
	get_general_ptr(args, &conv, spec, buffer);
	spec->flags['#'] = TRUE;
	return (print_d_buf(buffer, spec, put_hex_prefix));
}

int		ft_print_dd(t_spec *spec, va_list *args)
{
	char	buffer[MAX_LL_BUFF_SIZE];
	t_conv	conv;

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	spec->size.value[0] = 'l';
	conv = (t_conv){10, 'a'};
	get_general_ud(args, &conv, spec, buffer);
	return (print_sd_buf(buffer, spec));
}
