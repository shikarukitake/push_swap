/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:56:05 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_CHAR_H
# define PRINTF_PRINT_CHAR_H

# include <stdarg.h>

# include "specificator.h"
# include "printf_constants.h"
# include "ft_putwchar.h"
# include "print_str.h"

int		ft_print_c(t_spec *spec, va_list *args);

int		print_char(int c, t_spec *spec);

int		ft_print_cc(t_spec *spec, va_list *args);

#endif
