/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:33:42 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ud.h"

int		ft_print_u(t_spec *spec, va_list *args)
{
	char	buffer[MAX_LL_BUFF_SIZE];
	t_conv	conv;

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	conv = (t_conv){10, 'a'};
	get_general_ud(args, &conv, spec, buffer);
	return (print_d_buf(buffer, spec, put_sign_prefix));
}
