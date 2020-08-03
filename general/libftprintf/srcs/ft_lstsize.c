/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 03:21:52 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/16 05:07:01 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_lstsize(t_list *begin_list)
{
	long int counter;

	counter = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		counter++;
	}
	return (counter);
}
