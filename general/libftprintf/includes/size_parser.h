/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:32:01 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:32:08 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_SIZE_PARSER_H
# define PRINTF_SIZE_PARSER_H

# include "specificator.h"
# include "libft.h"
# include "printf_constants.h"

int		parse_size(const char *format, t_spec *spec);

#endif
