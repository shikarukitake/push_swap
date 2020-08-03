/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:28:28 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 19:29:47 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_constants.h"
#include "specificator.h"
#include "libft.h"

int		parse_type(const char *format, t_spec *spec)
{
	char	*ptr;

	ptr = ft_strchr(FT_PRINTF_SPEC_TYPES, format[0]);
	if (!ptr)
	{
		if (format[0] == '%')
		{
			spec->type = '%';
			return (1);
		}
		spec->type = -1;
		return (0);
	}
	else
		spec->type = *ptr;
	return (1);
}
