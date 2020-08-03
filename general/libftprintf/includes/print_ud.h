/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ud.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:15:02 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:15:09 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_UD_H
# define PRINTF_PRINT_UD_H

# include <stdarg.h>

# include "convert.h"
# include "specificator.h"
# include "specificator.h"
# include "printf_constants.h"
# include "get_digit.h"
# include "libft.h"
# include "print_f_buf.h"
# include "print_digit_buf.h"
# include "print_d_buf.h"

int		ft_print_u(t_spec *spec, va_list *args);

#endif
