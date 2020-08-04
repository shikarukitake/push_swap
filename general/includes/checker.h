/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:17:00 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/04 14:17:14 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN		"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_PINK		"\x1b[1;35m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET		"\x1b[0m"
# define FALSE	0
# define TRUE	1

typedef struct	s_stack
{
	struct s_stack	*previous;
	int				value;
	int				len;
}				t_stack;

typedef struct	s_dynamicarr
{
	int		*array;
	int		len;
	int		freespace;
}				t_dynamicarr;

/*
**  Struct for doing command ra or rra
*/

typedef struct	s_command
{
	int		count;
	char	*command;
}				t_command;

/*
** There is sorted array with chunk number
*/
typedef struct	s_chunks
{
	int	len;
	int	*array;
	int	*chunk;
	int	current_c;

}				t_chunks;

typedef struct	s_sts
{
	t_command		*comm;
	t_chunks		*chunks;
	t_stack			**stacka;
	t_stack			**stackb;
	t_dynamicarr	*darr;
	int				firstholdi;
	int				secondholdi;
	char			*commands;
	int				vflag;
	int				cflag;
	char			*curcomm;
}				t_sts;

/*
**  STACK
*/

void			push_stack(t_stack **stack, int value);
int				pop_stack(t_stack **stack);
void			swap(t_stack **stack);
void			rotate(t_stack **stack);
void			reverse_rotate(t_stack **stack);
void			print_stacks(t_stack *stack_a, t_stack *stack_b);
t_stack			*init_stack(t_stack *previous, int value);
void			free_stack(t_stack *stack);

/*
** Dynamic Array
*/

int				init_darr(t_dynamicarr **arr);
void			cpy_intarray(int *dest, int *src, int freeornot, int len);
int				add_darr(t_dynamicarr **arr, int value);
t_dynamicarr	*init_darrfromint(int *array, int len);

/*
** Service
*/

void			ft_error(void);
void			ft_error_t(char const *text);
t_sts			*error_tf(char const *text, int init);
int				stack_is_sorted(t_stack *stacka);
void			check_sorted(t_sts *sts);
int				is_only_digits(char *s);
char			**ft_strsplit(char const *s, char c);
size_t			ft_w_count(char const *s, char c);
int				*arr_from_stack(t_stack *stack, int sort_or_not);
void			free_sts(t_sts *sts);
int				ft_printf(const char *fmt, ...);
t_sts			*get_sts(void);

/*
** Reading
*/

void			read_args(int ac, char **av, t_sts *sts);
int				check_command(char *command);
void			reading_from_stdin(t_dynamicarr **darr);
int				check_dublicates(t_stack *stack);

/*
** Push Swap commands
*/

void			ft_sa(t_sts *sts);
void			ft_sb(t_sts *sts);
void			ft_ss(t_sts *sts);
void			ft_pa(t_sts *sts);
void			ft_pb(t_sts *sts);
void			ft_ra(t_sts *sts);
void			ft_rb(t_sts *sts);
void			ft_rr(t_sts *sts);
void			ft_rra(t_sts *sts);
void			ft_rrb(t_sts *sts);
void			ft_rrr(t_sts *sts);
void			init_ftable(void **func_table);
void			exec_commands(t_sts *sts);

#endif
