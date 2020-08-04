/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:02:11 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FLOAT_UTIL_H
# define PRINTF_FLOAT_UTIL_H

# include "specificator.h"

int			get_float_precision(t_spec *spec);

char		get_float_fill_ch(t_spec *spec);

int			is_special_value(char *buf);

int			is_float_null_case(char *f, t_spec *spec);

#endif
