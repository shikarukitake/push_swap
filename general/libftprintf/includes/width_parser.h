/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:40:16 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_WIDTH_PARSER_H
# define PRINTF_WIDTH_PARSER_H

# include <stdlib.h>
# include "specificator.h"
# include "libft.h"

int		parse_width(const char *format, t_spec *spec);

#endif
