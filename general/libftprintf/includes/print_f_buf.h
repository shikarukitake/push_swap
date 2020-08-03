/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_buf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:04:55 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:05:42 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_F_BUF_H
# define PRINTF_PRINT_F_BUF_H

# include "specificator.h"
# include "ft_ldtoa.h"
# include "libft.h"
# include "printf_constants.h"
# include "specificator.h"
# include "print_digit_buf.h"
# include "print_str.h"
# include "float_util.h"
# include "exp_util.h"
# include "round_float.h"

int		print_f(char *f, t_spec *spec, t_ld *ld);
void	add_zeros(char *buf, t_spec *spec);
int		print_f_buf(char *f, t_spec *spec, char sign, int is_dot);

#endif
