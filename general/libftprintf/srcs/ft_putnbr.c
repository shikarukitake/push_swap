/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:55:51 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_pow_unsigned(int i, int st)
{
	unsigned long		new;

	new = i;
	if (st == 0)
		return (1);
	while (st-- > 1)
		new = new * i;
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

static void				ft_intprint(int n)
{
	unsigned long	i;
	int				len_n;

	len_n = len(n);
	i = ft_pow_unsigned(10, len(n)) / 10;
	while (len_n-- > 0)
	{
		ft_putchar(((n / i) + '0'));
		n = n % i;
		i = i / 10;
	}
}

void					ft_putnbr(int n)
{
	if (n < 0)
		if (n == -2147483648)
			ft_putstr("-2147483648");
		else
		{
			ft_putchar('-');
			ft_intprint(n * (-1));
		}
	else
		ft_intprint(n);
}
