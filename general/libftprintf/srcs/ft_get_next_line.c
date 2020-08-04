/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:03:26 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_line_maker(const int fd, char **help, char **line)
{
	size_t	len;
	char	*iter;

	len = 0;
	while (help[fd][len] != '\0' && help[fd][len] != '\n')
		len++;
	if (help[fd][len] == '\n')
	{
		*line = ft_strsub(help[fd], 0, len);
		iter = ft_strsub(help[fd], len + 1, ft_strlen(help[fd]) - len);
		free(help[fd]);
		help[fd] = ft_strdup(iter);
		free(iter);
	}
	else if (help[fd][len] == '\0')
	{
		*line = ft_strdup(help[fd]);
		ft_strdel(&help[fd]);
	}
	return (1);
}

int			ft_get_next_line(const int fd, char **line)
{
	static char	*help[1];
	char		buff[32 + 1];
	char		*iter;
	int			rdr;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((rdr = read(fd, buff, 32)) > 0)
	{
		buff[rdr] = '\0';
		if (help[fd] == NULL)
			help[fd] = ft_strnew(1);
		iter = ft_strjoin(help[fd], buff);
		free(help[fd]);
		help[fd] = iter;
		if (ft_strchr(help[fd], '\n'))
			break ;
	}
	if (rdr < 0)
		return (-1);
	if (rdr == 0 && (help[fd] == NULL || help[fd][0] == '\0'))
		return (0);
	return (ft_line_maker(fd, help, line));
}
