/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:44:54 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *el;

	if (!(el = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		if (content == NULL)
		{
			el->content = NULL;
			el->content_size = 0;
		}
		else
		{
			if (!(el->content = (void *)malloc(content_size)))
				return (NULL);
			ft_memmove(el->content, content, content_size);
			el->content_size = content_size;
		}
		el->next = NULL;
		return (el);
	}
}
