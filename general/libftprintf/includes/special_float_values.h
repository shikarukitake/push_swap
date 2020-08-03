/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_float_values.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:56:11 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:56:14 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_SPECIAL_FLOAT_VALUES_H
# define PRINTF_SPECIAL_FLOAT_VALUES_H

# include "ft_ldtoa.h"

int		is_reserved_value(t_ldc ldc, long double ld, char *fbuf);

#endif
