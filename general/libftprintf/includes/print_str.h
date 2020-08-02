/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:15:39 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:47:40 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_STR_H
# define PRINTF_PRINT_STR_H

# include "specificator.h"
# include <stdarg.h>
# include "print_ws.h"
# include "print_f_buf.h"
# include "print_digit_buf.h"
# include "libft.h"

int		ft_print_s(t_spec *spec, va_list *args);

int		print_str(char *str, t_spec *spec);

#endif
