/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:07:06 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:07:35 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_FLOAT_H
# define PRINTF_PRINT_FLOAT_H

# include "specificator.h"
# include "stdarg.h"
# include "get_float.h"
# include "print_f_buf.h"
# include "print_float.h"
# include "ft_ldtoa.h"
# include "printf_constants.h"
# include "libft.h"
# include "print_e_buf.h"

int		ft_print_f(t_spec *spec, va_list *args);

int		ft_print_e(t_spec *spec, va_list *args);

int		ft_print_g(t_spec *spec, va_list *args);

#endif
