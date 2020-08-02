/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:40:45 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:40:49 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa_base(int value, char *buffer, int base, char a)
{
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	buffer[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		buffer[i] = (n % base < 10) ? n % base + '0' : n % base + a - 10;
		n /= base;
	}
	(i == 0) ? buffer[i] = '-' : 0;
	return (buffer);
}
