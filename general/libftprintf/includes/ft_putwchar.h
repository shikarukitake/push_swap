/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:41:46 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 21:42:01 by ayellin          ###   ########.fr       */
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
