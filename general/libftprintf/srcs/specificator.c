/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:27:15 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 19:27:52 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specificator.h"

t_spec	*init_spec(void)
{
	t_spec	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_spec));
	if (!new)
		return (NULL);
	new->type = -1;
	new->size.id = -1;
	new->width.value = -1;
	new->width.is_asterisk = FALSE;
	new->precision.value = -1;
	new->precision.is_asterisk = FALSE;
	new->precision.is_dot = FALSE;
	while (i < MAX_FLAGS)
		new->flags[i++] = FALSE;
	return (new);
}
