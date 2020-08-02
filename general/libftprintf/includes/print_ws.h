/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:17:33 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:17:54 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PRINT_WS_H
# define PRINTF_PRINT_WS_H

# include <stdarg.h>
# include <wchar.h>

# include "ft_putwchar.h"
# include "specificator.h"

int		ft_print_ws(t_spec *spec, va_list *args);

#endif
