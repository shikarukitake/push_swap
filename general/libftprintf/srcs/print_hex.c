/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:45:11 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 18:47:33 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_hex.h"

int		put_hex_prefix(const char *buf, t_spec *spec, char *dest)
{
	if (spec->type == 'p')
	{
		put_or_copy(dest, HEX_SMALL_PREFIX);
		return (2);
	}
	if (spec->flags['#'] == TRUE && buf[0] != '0')
	{
		if (spec->type == 'x')
			put_or_copy(dest, HEX_SMALL_PREFIX);
		else if (spec->type == 'X')
			put_or_copy(dest, HEX_BIG_PREFIX);
		return (2);
	}
	return (0);
}

int		ft_print_x(t_spec *spec, va_list *args)
{
	char	buffer[MAX_HEX_BUF_SIZE];
	t_conv	conv;

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	conv = (t_conv){ 16, 'a'};
	get_general_ud(args, &conv, spec, buffer);
	return (print_d_buf(buffer, spec, put_hex_prefix));
}

int		ft_print_xx(t_spec *spec, va_list *args)
{
	char	buffer[MAX_HEX_BUF_SIZE];
	t_conv	conv;

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	conv = (t_conv){16, 'A'};
	get_general_ud(args, &conv, spec, buffer);
	return (print_d_buf(buffer, spec, put_hex_prefix));
}
