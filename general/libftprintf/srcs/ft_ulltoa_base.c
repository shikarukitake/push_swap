/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:42:31 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:43:50 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ulldiv	ull_div(t_ull value, int base)
{
	t_ulldiv r;

	r.qout = (value) / base;
	r.rem = (value) % base;
	return (r);
}

static char		ft_convert(t_ull *ll, int base, char a)
{
	t_ulldiv	r;
	char		ch;

	r = ull_div(*ll, base);
	*ll = r.qout;
	ch = (char)(r.rem + ((9L < r.rem) ? (a - 10L) : '0'));
	return (ch);
}

static int		ft_is_border(t_ull value, char *str)
{
	if (value == 0)
	{
		ft_strcpy(str, "0");
		return (1);
	}
	return (0);
}

char			*ft_ulltoa_base(t_ull ull, char *str, int base, char a)
{
	int i;

	i = 0;
	if (!str)
		str = ft_strnew(ULLONG_MAX_DIGITS);
	if (ft_is_border(ull, str))
		return (str);
	if (36 < base || 2 > base)
		base = 10;
	while (ull)
		str[i++] = ft_convert(&ull, base, a);
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
