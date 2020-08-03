/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:56:32 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:56:42 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_SPEC_UTIL_H
# define PRINTF_SPEC_UTIL_H

# include "specificator.h"
# include "libft.h"

char	get_fill_ch(int len, t_spec *spec);

int		get_diff(int buf_len, t_spec *spec);

int		is_null_case(const char *digit, t_spec *spec);

#endif
