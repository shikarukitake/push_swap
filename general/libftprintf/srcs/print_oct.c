/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:41:32 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:41:52 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_oct.h"

int		is_oct_prefix(t_spec *spec)
{
	return (spec->type == 'o' && spec->flags['#'] == TRUE);
}

int		put_oct_prefix(const char *buf, t_spec *spec, char *dest)
{
	if (spec->flags['#'] == TRUE && buf[0] != '0')
	{
		if (spec->type == 'o')
		{
			if (dest)
				ft_strcpy(dest, OCT_PREFIX);
			else
				ft_putstr(OCT_PREFIX);
		}
		return (1);
	}
	return (0);
}

int		ft_print_o(t_spec *spec, va_list *args)
{
	char	buffer[MAX_LL_BUFF_SIZE];
	t_conv	conv;

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	conv = (t_conv){8, 'a'};
	get_general_ud(args, &conv, spec, buffer);
	return (print_d_buf(buffer, spec, put_oct_prefix));
}
