/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_format_parser.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:30:16 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:31:35 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_SPEC_FORMAT_PARSER_H
# define PRINTF_SPEC_FORMAT_PARSER_H

# include "ft_printf.h"
# include "color_util.h"
# include "printf_constants.h"
# include "size_parser.h"
# include "precision_parser.h"
# include "type_parser.h"
# include "width_parser.h"
# include "flags_parse.h"
# include "color_util.h"

int		get_spec_format_length(const char *format);

t_spec	*parse_spec_format(const char *spc_fmt);

void	fill_spec_from_vargs(t_spec *spec, va_list *vargs);

int		is_spec_format(const char *format);

#endif
