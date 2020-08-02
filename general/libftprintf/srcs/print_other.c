/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:29:13 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:30:02 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_other.h"

int		ft_print_empty(t_spec *spec, va_list *args)
{
	((void)spec);
	((void)args);
	return (0);
}

char	get_percent_fill_ch(t_spec *spec)
{
	if (spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
		return ('0');
	else
		return (' ');
}

int		ft_print_percent(t_spec *spec, va_list *args)
{
	int		i;

	i = 0;
	(void)(args);
	if (spec->flags['-'] == TRUE)
	{
		ft_putchar('%');
		i++;
		while (i < spec->width.value)
		{
			ft_putchar(get_percent_fill_ch(spec));
			i++;
		}
	}
	else
	{
		while (i < spec->width.value - 1)
		{
			ft_putchar(get_percent_fill_ch(spec));
			i++;
		}
		ft_putchar('%');
		i++;
	}
	return (i);
}

int		ft_print_color(t_spec *spec, va_list *args)
{
	((void)spec);
	((void)args);
	return (6);
}
