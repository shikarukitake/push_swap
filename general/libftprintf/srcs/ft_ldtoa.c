/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:42:08 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 18:20:45 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ldtoa.h"
#include "special_float_values.h"

static void	make_ld_buf(long double ld, char *buf, char *i_part, char *f_part)
{
	if (ld < 0)
		buf[0] = '-';
	ft_strcat(buf, i_part);
	ft_strcat(buf, ".");
	ft_strcat(buf, f_part);
	free(i_part);
	free(f_part);
}

int			make_int_part(char **int_part, t_ldc *ldc)
{
	if (ldc->parts.e >= EXP_SHIFT)
	{
		ldc->parts.e = ldc->parts.e - EXP_SHIFT;
		*int_part = ft_memalloc(MAX_F_BUF_SIZE);
		get_int_part(ldc->parts.m, ldc->parts.e, *int_part);
		return (1);
	}
	else
	{
		ldc->parts.e = EXP_SHIFT - ldc->parts.e;
		*int_part = ft_strdup("0");
		return (0);
	}
}

void		make_float_part(char **float_part, t_ldc *ldc, int lho)
{
	if (ldc->parts.e < 63u || lho == 0)
	{
		*float_part = ft_memalloc(MAX_F_BUF_SIZE);
		get_float_part(ldc->parts.m, ldc->parts.e, *float_part, lho);
	}
	else
		*float_part = ft_strdup("0");
}

void		ft_ldtoa(t_ld *ld, char *buffer)
{
	char	*int_part_buf;
	char	*float_part_buf;
	int		less_than_one;
	t_ldc	ldc;

	ldc = (t_ldc) {.ld = ld->value};
	if (is_reserved_value(ldc, ld->value, buffer))
		return ;
	less_than_one = make_int_part(&int_part_buf, &ldc);
	make_float_part(&float_part_buf, &ldc, less_than_one);
	make_ld_buf(ld->value, buffer, int_part_buf, float_part_buf);
}
