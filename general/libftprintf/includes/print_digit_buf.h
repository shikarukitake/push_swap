/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_buf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:59:53 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_DIGIT_BUF_H
# define PRINTF_PRINT_DIGIT_BUF_H

# include "specificator.h"
# include "printf_constants.h"
# include "libft.h"
# include "print_d_buf.h"
# include "spec_util.h"
# include "print_util.h"

typedef int	(*t_put_prefix) (const char *, t_spec *, char *dest);

typedef struct	s_d_pair
{
	char *d;
	char *pd;
}				t_d_pair;

int				print_d_buf(char *digit, t_spec *spec, t_put_prefix pp);

#endif
