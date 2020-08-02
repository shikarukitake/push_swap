/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:44:39 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:44:47 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define FT_ERROR_EXIT 1

#define FT_STDERR 2

void		ft_exit(void *mem, const char *msg)
{
	if (msg)
		ft_putstr_fd(msg, FT_STDERR);
	if (mem)
		free(mem);
	exit(FT_ERROR_EXIT);
}
