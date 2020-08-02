/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:10:53 by dan               #+#    #+#             */
/*   Updated: 2019/09/16 16:24:15 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char	const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (FT_NULL);
	new = ft_strnew(len);
	if (!new)
		return (FT_NULL);
	ft_strncpy(new, s + start, len);
	return (new);
}
