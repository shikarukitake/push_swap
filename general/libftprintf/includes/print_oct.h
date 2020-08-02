/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:08:54 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:09:16 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_OCT_H
# define PRINTF_PRINT_OCT_H

# include <stdarg.h>
# include "specificator.h"
# include "get_digit.h"
# include "convert.h"
# include "print_f_buf.h"
# include "print_digit_buf.h"

int		ft_print_o(t_spec *spec, va_list *args);

int		is_oct_prefix(t_spec *spec);

#endif
