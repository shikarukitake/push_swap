/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:57:12 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			stack_is_sorted(t_stack *stacka)
{
	int previous;

	if (!stacka)
		return (FALSE);
	previous = stacka->value;
	stacka = stacka->previous;
	while (stacka)
	{
		if (stacka->value < previous)
			return (FALSE);
		previous = stacka->value;
		stacka = stacka->previous;
	}
	return (TRUE);
}

void		check_sorted(t_sts *sts)
{
	if (stack_is_sorted(*(sts->stacka)) && !*(sts->stackb))
	{
		if (sts->cflag)
			ft_printf(COLOR_GREEN);
		ft_printf("OK!\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	else
	{
		if (sts->cflag)
			ft_printf(COLOR_RED);
		ft_printf("KO!\n");
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
}

int			is_only_digits(char *s)
{
	int i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (FALSE);
	if (s[0] == '-')
	{
		if (ft_strlen(s) == 1)
			return (FALSE);
		i = 1;
	}
	while (s[i])
	{
		if (ft_isdigit(s[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_sts		*error_tf(char const *text, int init)
{
	static t_sts	*sts;

	if (init)
	{
		sts = get_sts();
		return (sts);
	}
	free_sts(sts);
	ft_error_t(text);
	return (NULL);
}
