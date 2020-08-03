/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:42:23 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:42:57 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_DIGIT_H
# define PRINTF_GET_DIGIT_H

# include <stdarg.h>
# include "specificator.h"
# include "convert.h"
# include "libft.h"
# include "printf_constants.h"

void	get_general_d(va_list *vargs, t_conv *conv, t_spec *spec, char *buf);

void	get_general_ud(va_list *vargs, t_conv *conv, t_spec *spec, char *buf);

void	get_general_ptr(va_list *vargs, t_conv *conv, t_spec *spec, char *buf);

#endif
