/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:57:56 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:58:28 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_parse.h"

int		is_flag(char c)
{
	return (ft_strchr(FT_PRINTF_FLAGS, c) != NULL);
}

int		parse_flags(const char *format, t_spec *spec)
{
	int i;

	i = 0;
	while (is_flag(format[i]))
		spec->flags[(int)format[i++]] = TRUE;
	return (i);
}
