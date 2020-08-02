/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:08:04 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:08:28 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_HEX_H
# define PRINTF_PRINT_HEX_H

# include "specificator.h"
# include <stdarg.h>
# include "printf_constants.h"
# include "print_hex_buf.h"
# include "libft.h"
# include "print_digit_buf.h"
# include "convert.h"
# include "get_digit.h"

int		ft_print_x(t_spec *spec, va_list *args);

int		ft_print_xx(t_spec *spec, va_list *args);

#endif
