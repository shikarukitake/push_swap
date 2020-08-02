/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:42:15 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:42:18 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_uitoa_base(unsigned int value, char *buffer, int base, char a)
{
	unsigned long	n;
	int				i;

	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	buffer[i] = '\0';
	n = value;
	while (i--)
	{
		buffer[i] = (n % base < 10) ? n % base + '0' : n % base + a - 10;
		n /= base;
	}
	return (buffer);
}
