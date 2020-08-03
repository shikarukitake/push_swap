/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:21:49 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:44:06 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static t_lldiv	ll_div(long long value, int base)
{
	t_lldiv r;

	r.qout = (value) / base;
	r.rem = (value) % base;
	return (r);
}

static char		ft_convert(long long *ll, int base, char a)
{
	t_lldiv		r;
	char		ch;

	r = ll_div(*ll, base);
	*ll = r.qout;
	ch = (char)(r.rem + ((9L < r.rem) ? (a - 10L) : '0'));
	return (ch);
}

static int		ft_is_border(long long *value, int *is_neg, char *str)
{
	if (*value == 0)
	{
		ft_strcpy(str, "0");
		return (1);
	}
	if (*value < 0)
	{
		*is_neg = 1;
		if (*value == FT_LONG_LONG_MIN)
		{
			ft_strcpy(str, FT_LONG_LONG_MIN_STR);
			return (1);
		}
		*value = -(*value);
	}
	return (0);
}

char			*ft_lltoa_base(long long ll, char *str, int base, char a)
{
	int is_neg;
	int i;

	is_neg = 0;
	i = 0;
	if (!str)
		str = ft_strnew(ULLONG_MAX_DIGITS);
	if (36 < base || 2 > base)
		base = 10;
	if (ft_is_border(&ll, &is_neg, str))
		return (str);
	while (ll)
		str[i++] = ft_convert(&ll, base, a);
	if (is_neg)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
