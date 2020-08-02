/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:35:10 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:39:50 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_SPECIFICATOR_H
# define PRINTF_SPECIFICATOR_H

# include "util.h"
# include "print_settings.h"
# include <stdlib.h>

# define MAX_FLAGS 255

typedef struct	s_width
{
	int			value;
	t_bool		is_asterisk;
}				t_width;

typedef struct	s_percision
{
	int			value;
	t_bool		is_asterisk;
	t_bool		is_dot;

}				t_precision;

typedef struct	s_size
{
	int			id;
	char		value[3];
}				t_size;

typedef struct	s_spec
{
	t_bool		flags[MAX_FLAGS];
	char		type;
	t_width		width;
	t_precision	precision;
	t_size		size;
}				t_spec;

t_spec			*init_spec();

#endif
