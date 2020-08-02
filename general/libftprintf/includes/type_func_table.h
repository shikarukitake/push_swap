/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_func_table.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:37:33 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:37:57 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_TYPE_FUNC_TABLE_H
# define PRINTF_TYPE_FUNC_TABLE_H

# include <stdarg.h>

# include "print_oct.h"
# include "print_hex.h"
# include "print_f_buf.h"
# include "print_other.h"
# include "print_ud.h"
# include "specificator.h"
# include "spec_format_parser.h"
# include "print_basic.h"
# include "print_float.h"
# include "print_char.h"
# include "printf_constants.h"

int		call_print_func(const char *fmt, va_list *args, int offset);

#endif
