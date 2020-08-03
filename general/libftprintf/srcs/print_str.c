/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:48:29 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:47:28 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_str.h"

char		get_str_fill_ch(t_spec *spec)
{
	if ((spec->type == 's' || spec->type == 'c') &&
			spec->flags['0'] == TRUE &&
			spec->flags['-'] == FALSE)
		return ('0');
	else
		return (' ');
}

int			fill_str_field(const char *str, t_spec *spec)
{
	int		count;
	int		i;
	char	ch;

	ch = get_str_fill_ch(spec);
	if (spec->precision.value == -1)
		i = (spec->precision.is_dot == TRUE ? 0 : (int)ft_strlen(str));
	else
	{
		i = ft_min(spec->precision.value, (int)ft_strlen(str));
		if (ft_strlen(str) == 0)
			i = 0;
	}
	count = i;
	while (i < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	return (i - count);
}

int			print_str(char *str, t_spec *spec)
{
	int		i;
	int		j;
	char	null_str[7];

	i = 0;
	j = 0;
	ft_strcpy(null_str, NULL_STR);
	if (!str)
		str = null_str;
	if (spec->flags['-'] == FALSE)
		i += fill_str_field(str, spec);
	if (spec->precision.value == -1 && spec->precision.is_dot == FALSE)
		i += print_buf(str);
	else
	{
		while (j < spec->precision.value && j < (int)ft_strlen(str))
		{
			ft_putchar(str[j++]);
			i++;
		}
	}
	if (spec->flags['-'] == TRUE)
		i += fill_str_field(str, spec);
	return (i);
}

int			ft_print_s(t_spec *spec, va_list *args)
{
	char *tmp;

	if (spec->size.id == -1)
	{
		tmp = va_arg(*args, char *);
		return (print_str(tmp, spec));
	}
	else if (spec->size.value[0] == 'l')
		return (ft_print_ws(spec, args));
	return (0);
}
