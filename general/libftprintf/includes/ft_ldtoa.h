/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:33:53 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_LDTOA_H
# define PRINTF_FT_LDTOA_H

# include <float.h>

# include "libft.h"
# include "printf_constants.h"
# include <stdlib.h>
# include "long_arithmetic.h"
# include "get_float_part.h"
# include "get_int_part.h"

# define EXP_SHIFT 16383u

typedef	union			u_ldc
{
	long double			ld;
	struct
	{
		unsigned long	m : 64;
		unsigned int	e : 15;
		unsigned int	s : 1;
	}					parts;
}						t_ldc;

typedef struct			s_ld
{
	long double			value;
	char				round;

}						t_ld;

void					ft_ldtoa(t_ld *ld, char *buffer);

#endif
