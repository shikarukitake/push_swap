/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_buf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:16:26 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:16:34 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_HEX_BUF_H
# define PRINTF_PRINT_HEX_BUF_H

# include "specificator.h"
# include "libft.h"
# include "printf_constants.h"
# include "print_f_buf.h"

int		put_hex_prefix(const char *buf, t_spec *spec, char *dest);

#endif
