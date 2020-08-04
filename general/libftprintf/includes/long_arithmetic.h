/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:59:56 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LONG_ARITHMETIC_H
# define PRINTF_LONG_ARITHMETIC_H

void	multiply_by_2(char *buf, int size, unsigned n);

void	long_sum(char *to_sum, char *result, int n, int direct);

void	divide_by_2(char *divided, int n);

void	rev_divide_by_2(char *divided, int n);

#endif
