/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:57:19 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/04 16:09:55 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				check_command(char *command)
{
	if (!ft_strcmp(command, "sa"))
		return (0);
	else if (!ft_strcmp(command, "sb"))
		return (1);
	else if (!ft_strcmp(command, "ss"))
		return (2);
	else if (!ft_strcmp(command, "pa"))
		return (3);
	else if (!ft_strcmp(command, "pb"))
		return (4);
	else if (!ft_strcmp(command, "ra"))
		return (5);
	else if (!ft_strcmp(command, "rb"))
		return (6);
	else if (!ft_strcmp(command, "rr"))
		return (7);
	else if (!ft_strcmp(command, "rra"))
		return (8);
	else if (!ft_strcmp(command, "rrb"))
		return (9);
	else if (!ft_strcmp(command, "rrr"))
		return (10);
	else
		return (-1);
}

/*
** filling stack_a from program arguments
*/

static void		check_atoi(long long q, const char *str)
{
	size_t	max_len;

	if (q > 2147483647 || q < -2147483648)
		error_tf("ft_atoi(int) overflow", FALSE);
	while (*str == '\n' || *str == '\t' || *str == ' ' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	max_len = *str == '-' ? 11 : 10;
	if (ft_strlen(str) > max_len)
		error_tf("ft_atoi(int) overflow", FALSE);
}

static void		check_arg(char *const *av, t_sts *sts, int i)
{
	long number;

	if (!ft_strcmp(av[i], "-v"))
		sts->vflag = TRUE;
	else if (!ft_strcmp(av[i], "-c"))
		sts->cflag = TRUE;
	else if (is_only_digits(av[i]) == FALSE)
		error_tf("There is non numeric param!", FALSE);
	else
	{
		number = ft_atoi_l(av[i]);
		check_atoi(number, av[i]);
		push_stack(sts->stacka, number);
	}
}

void			read_args(int ac, char **av, t_sts *sts)
{
	int		i;

	if (ac == 2 && ft_strlen(av[1]) == 0)
		error_tf("Empty arg!", FALSE);
	i = ac == 2 ? (int)word_counter(av[1], ' ') - 1 : ac - 1;
	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	if (!av)
		error_tf("read_args malloc ft_strsplit", FALSE);
	ac = ac == 2 ? -1 : 0;
	sts->vflag = FALSE;
	sts->cflag = FALSE;
	while (i != ac)
	{
		check_arg(av, sts, i);
		i--;
	}
	if (ac == -1)
		to_free_dstr(av);
}

void			reading_from_stdin(t_dynamicarr **darr)
{
	char	*line;
	int		size;
	int		command;

	*darr = NULL;
	while ((size = ft_get_next_line(0, &line)) > 0)
	{
		if (!line)
			error_tf("reading_from_stdin gnl malloc error", FALSE);
		command = check_command(line);
		if (command == -1)
			ft_error();
		else
			add_darr(darr, command);
		free(line);
	}
}
