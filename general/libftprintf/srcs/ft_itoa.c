/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:58:59 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_pow_u(int i, int st)
{
	unsigned long		new;

	new = (unsigned long)i;
	if (st == 0)
		return (1);
	while (st-- > 1)
		new = new * (unsigned long)i;
	return (new);
}

static int				len(int n)
{
	int i;

	i = ((n == 0) ? 1 : 0);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char				*ft_dest(char *src, char **dest_pre)
{
	*dest_pre = ft_strdup(src);
	return (*dest_pre);
}

char					*ft_itoa(int n)
{
	char				*dest;
	unsigned long		i;
	int					len_n;
	int					sign;

	len_n = ((n < 0) ? len(n) + 1 : len(n));
	if (n == -2147483648)
		return (ft_dest("-2147483648", &dest));
	if (!(dest = malloc(sizeof(char) * (len_n + 1))))
		return (NULL);
	dest[len_n] = '\0';
	if (n == 0)
		dest[0] = '0';
	if (n < 0)
		dest[0] = '-';
	sign = ((n < 0) ? 1 : 0);
	n = ((n < 0) ? -n : n);
	i = ((sign == 1) ? ft_pow_u(10, len_n - 1) : ft_pow_u(10, len_n)) / 10;
	while (sign < len_n)
	{
		dest[sign++] = ((n / i) + '0');
		n = n % i;
		i = i / 10;
	}
	return (dest);
}
