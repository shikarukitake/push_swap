/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:41:22 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/16 05:06:47 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pb(t_list **begin_list,
		void const *content, size_t content_size)
{
	t_list *temporary;

	if (begin_list && *begin_list)
	{
		temporary = *begin_list;
		while (temporary->next)
			temporary = temporary->next;
		temporary->next = ft_lstnew(content, content_size);
	}
	else
		*begin_list = ft_lstnew(content, content_size);
}
