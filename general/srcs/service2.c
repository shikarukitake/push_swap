/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:01:50 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/04 14:17:14 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		free_sts_stacks(const t_sts *sts)
{
	if (sts->stacka)
		if (*(sts->stacka))
			free_stack(*(sts->stacka));
	if (sts->stackb)
		if (*(sts->stackb))
			free_stack(*(sts->stackb));
}

void		free_sts(t_sts *sts)
{
	if (sts->chunks)
	{
		if (sts->chunks->array)
			free(sts->chunks->array);
		if (sts->chunks->chunk)
			free(sts->chunks->chunk);
		free(sts->chunks);
	}
	if (sts->darr)
	{
		free(sts->darr->array);
		free(sts->darr);
	}
	if (sts->comm)
		free(sts->comm);
	if (sts->commands)
		free(sts->commands);
	free_sts_stacks(sts);
	if (sts->curcomm)
		free(sts->curcomm);
	free(sts);
}

t_sts		*get_sts(void)
{
	t_sts			*sts;
	static t_stack	*stacka;
	static t_stack	*stackb;

	sts = malloc(sizeof(t_sts));
	if (!sts)
		ft_error_t("init_sts_new malloc error");
	stacka = NULL;
	stackb = NULL;
	sts->stacka = &stacka;
	sts->stackb = &stackb;
	sts->darr = NULL;
	sts->commands = NULL;
	sts->comm = NULL;
	sts->chunks = NULL;
	sts->curcomm = NULL;
	return (sts);
}

int			check_dublicates(t_stack *stack)
{
	int *array;
	int i;
	int previous;

	i = 1;
	array = arr_from_stack(stack, TRUE);
	previous = array[0];
	while (i != stack->len)
	{
		if (array[i] == previous)
			return (TRUE);
		previous = array[i];
		i++;
	}
	free(array);
	return (FALSE);
}
