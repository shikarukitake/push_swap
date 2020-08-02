/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:58:38 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 20:00:56 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ws.h"

size_t		ft_wstrlen(wchar_t *str)
{
	size_t l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void		ft_putwstr(wchar_t *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		i++;
	}
}

int			ft_print_ws(t_spec *spec, va_list *args)
{
	wchar_t	*tmp;
	int		i;

	i = 0;
	tmp = va_arg(*args, wchar_t *);
	if (!tmp)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (spec->precision.value == -1)
	{
		ft_putwstr(tmp);
		return (ft_wstrlen(tmp));
	}
	else
	{
		while (i < spec->precision.value)
		{
			ft_putwchar(tmp[i]);
			i++;
		}
		return (i);
	}
}
