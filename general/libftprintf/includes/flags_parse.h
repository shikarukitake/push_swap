/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:33:10 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:33:17 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FLAGS_PARSE_H
# define PRINTF_FLAGS_PARSE_H

# include "specificator.h"
# include "libft.h"
# include "printf_constants.h"

int		parse_flags(const char *format, t_spec *spec);

#endif
