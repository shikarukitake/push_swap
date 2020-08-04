/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:13:45 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;
	t_list *swap;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	if (lst)
	{
		new = f(lst);
		start = new;
		while (lst->next)
		{
			swap = lst->next;
			free(lst->content);
			free(lst);
			lst = swap;
			new->next = f(lst);
			new = new->next;
		}
		new->next = NULL;
		return (start);
	}
	return (NULL);
}
