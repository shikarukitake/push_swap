/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:41:46 by ayellin           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PUTWCHAR_H
# define PRINTF_FT_PUTWCHAR_H

# include <wchar.h>
# include "libft.h"
# include <stddef.h>
# include <unistd.h>

void	ft_putwchar(wchar_t wch);

int		ft_wchlen(wchar_t wch);

#endif
