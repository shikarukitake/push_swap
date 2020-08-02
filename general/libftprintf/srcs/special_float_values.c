/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_float_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:35:23 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 19:44:57 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "special_float_values.h"

int			is_inf(t_ldc ldc)
{
	return (ldc.parts.e == 32767u &&
			ldc.parts.m == 9223372036854775808ul &&
			ldc.parts.s == 0u);
}

int			is_ninf(t_ldc ldc)
{
	return (ldc.parts.e == 32767u &&
			ldc.parts.m == 9223372036854775808ul &&
			ldc.parts.s == 1u);
}

int			is_nan(t_ldc ldc)
{
	return (ldc.parts.e == 32767u &&
			(ldc.parts.m == 13835058057429647360ul || ldc.parts.m == 8u));
}

static int	copy(char *fbuf, char *value)
{
	ft_strcpy(fbuf, value);
	return (1);
}

int			is_reserved_value(t_ldc ldc, long double ld, char *fbuf)
{
	if (ld == 0 && ldc.parts.s == 1u)
		return (copy(fbuf, "-0.0"));
	else if (ld == 0 || ld == LDBL_MIN)
		return (copy(fbuf, "0.0"));
	else if (ld == -LDBL_MIN)
		return (copy(fbuf, "-0.0"));
	else if (is_inf(ldc))
		return (copy(fbuf, "inf"));
	else if (is_ninf(ldc))
		return (copy(fbuf, "-inf"));
	else if (is_nan(ldc))
		return (copy(fbuf, "nan"));
	return (0);
}
