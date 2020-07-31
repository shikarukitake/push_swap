/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:49:40 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/16 04:11:50 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_tab(char c)
{
	return (c == '\n' || c == '\t' || c == ' '
			|| c == '\v' || c == '\f' || c == '\r');
}

static long int		make_int(const char *str, long long q, int i, int neg)
{
	while (str[i] >= '0' && (str[i] <= '9'))
	{
		q = q * 10 + (str[i] - '0');
		i++;
	}
	if (i >= 19)
		return (neg == -1 ? 0 : -1);
	if (q > 9223372036854775807)
		return (neg == -1 ? 0 : -1);
	else
		return (q * neg);
	return (q);
}

static void         errorsCheck(long long q, const char *str)
{
    int maxLen;

    if (q > 2147483647 OR q < -2147483648)
        ft_error_t("ft_atoi(int) overflow");
    maxLen = *str == '-' ? 11 : 10;
    if (ft_strlen(str) > maxLen)
        ft_error_t("ft_atoi(int) overflow");
}

int					ft_atoi(const char *str)
{
	long long	q;
	int			i;
	int			neg;

	q = 0;
	i = 0;
	while (check_tab(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = str[i] == '-' ? -1 : 1;
		i++;
		q = make_int(str, q, i, neg);
	}
	else
		q = make_int(str, q, i, 1);
    errorsCheck(q, str);
	return (q);
}
