/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_part.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:01:42 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 18:01:50 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_GET_FLOAT_PART_H
# define PRINTF_GET_FLOAT_PART_H

# include <stdlib.h>

# include "printf_constants.h"
# include "libft.h"
# include "long_arithmetic.h"

void get_float_part(unsigned long m, unsigned exp, char *buf, int flag);

#endif
