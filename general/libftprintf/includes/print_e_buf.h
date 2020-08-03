/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e_buf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:04:24 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:04:31 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_E_BUF_H
# define PRINTF_PRINT_E_BUF_H

# include "specificator.h"
# include "ft_ldtoa.h"
# include "libft.h"
# include "printf_constants.h"
# include "specificator.h"
# include "print_digit_buf.h"
# include "print_str.h"
# include "print_f_buf.h"
# include "exp_util.h"

int		print_e_buf(char *e, t_spec *spec, char a, t_ld *ld);

int		place_dot(char *e, int exp);

#endif
