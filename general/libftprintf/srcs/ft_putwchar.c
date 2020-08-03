/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:52:03 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:52:27 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putwchar.h"

#define PREFIX1  128
#define PREFIX2  192
#define PREFIX3  224
#define PREFIX4  240

static void	ft_put_oct4(wchar_t wchar)
{
	unsigned char buf[4];

	buf[0] = (wchar >> 18u) + PREFIX4;
	buf[1] = ((wchar >> 12u) & 63) + PREFIX1;
	buf[2] = ((wchar >> 6u) & 63) + PREFIX1;
	buf[3] = (wchar & 63u) + PREFIX1;
	write(1, buf, 4);
}

static void	ft_put_oct3(wchar_t wchar)
{
	unsigned char buf[3];

	buf[0] = (wchar >> 12u) + PREFIX3;
	buf[1] = ((wchar >> 6u) & 63) + PREFIX1;
	buf[2] = (wchar & 63u) + PREFIX1;
	write(1, buf, 3);
}

static void	ft_put_oct2(wchar_t wchar)
{
	unsigned char buf[2];

	buf[0] = (wchar >> 6u) + PREFIX2;
	buf[1] = (wchar & 63u) + PREFIX1;
	write(1, buf, 2);
}

int			ft_wchlen(wchar_t wch)
{
	if (wch <= 127)
		return (1);
	else if (wch > 127 && wch <= 2047)
		return (2);
	else if (wch > 2047 && wch < 65535)
		return (3);
	else if (wch > 65535 && wch < 1114111)
		return (4);
	return (0);
}

void		ft_putwchar(wchar_t wch)
{
	if (wch <= 127)
		ft_putchar(wch);
	else if (wch >= 128 && wch <= 2047)
		ft_put_oct2(wch);
	else if (wch >= 2049 && wch <= 65535)
		ft_put_oct3(wch);
	else if (wch >= 65536 && wch <= 1114111)
		ft_put_oct4(wch);
}
