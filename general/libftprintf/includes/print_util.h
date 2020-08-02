/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:57:16 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:57:24 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_UTIL_H
# define PRINTF_PRINT_UTIL_H

# include "specificator.h"
# include "libft.h"
# include "spec_util.h"
# include "float_util.h"
# include "print_oct.h"

int		fill_precision_field(char *buf, t_spec *spec);

int		fill_w_field(int i, t_spec *spec, char sign, int prefix);

int		print_sign(char sign);

char	get_sign(char *digit, t_spec *spec);

#endif
