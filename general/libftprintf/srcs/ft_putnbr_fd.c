/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:06:49 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_pow_u(int i, int st)
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

static void				ft_intprint(int n, int fd)
{
	unsigned long	i;
	int				len_n;

	len_n = len(n);
	i = ft_pow_u(10, len(n)) / 10;
	while (len_n-- > 0)
	{
		ft_putchar_fd(((n / i) + '0'), fd);
		n = n % i;
		i = i / 10;
	}
}

void					ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			ft_putchar_fd('-', fd);
			ft_intprint(n * (-1), fd);
		}
	else
		ft_intprint(n, fd);
}
