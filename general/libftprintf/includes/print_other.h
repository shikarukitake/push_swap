/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:11:05 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:11:19 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_OTHER_H
# define PRINTF_PRINT_OTHER_H

# include "specificator.h"
# include <stdarg.h>
# include "libft.h"
# include "print_char.h"

int		ft_print_empty(t_spec *spec, va_list *args);

int		ft_print_percent(t_spec *spec, va_list *args);

int		ft_print_color(t_spec *spec, va_list *args);

#endif
