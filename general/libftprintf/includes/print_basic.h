/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:50:30 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:59:26 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_BASIC_H
# define PRINTF_PRINT_BASIC_H

# include <stdarg.h>
# include <wchar.h>

# include "libft.h"
# include "printf_constants.h"
# include "print_f_buf.h"
# include "specificator.h"
# include "print_hex_buf.h"
# include "print_digit_buf.h"
# include "print_d_buf.h"
# include "print_sd_buf.h"
# include "convert.h"
# include "get_digit.h"

int		ft_print_d(t_spec *spec, va_list *args);

int		ft_print_p(t_spec *spec, va_list *args);

int		ft_print_dd(t_spec *spec, va_list *args);

#endif
