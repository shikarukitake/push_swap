/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_buf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:06:27 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:06:39 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_D_BUF_H
# define PRINTF_PRINT_D_BUF_H

# include "specificator.h"
# include "libft.h"

int		put_sign_prefix(const char *buf, t_spec *spec, char *dest);

int		is_need_wh(const char *buf, t_spec *spec);

#endif
