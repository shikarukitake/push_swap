/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:16:47 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_EXP_UTIL_H
# define PRINTF_EXP_UTIL_H
# include "libft.h"
# include "print_e_buf.h"

void	add_exp(int exp, char *e);

int		get_exp(char *e);

int		first_digit(char ch);

int		check_carry(char *e, int exp);

void	modify_g_buf(char *g, t_spec *spec);

#endif
