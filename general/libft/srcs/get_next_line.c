/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:03:26 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/29 19:03:50 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int		line_make(const int fd, char **all, char **line)
{
	char	*temp;
	int		len;

	if (ft_strchr(all[fd], '\n'))
	{
		len = ft_strchrn(all[fd], '\n');
		*line = ft_strsub(all[fd], 0, len);
		temp = ft_strsub(all[fd], len + 1, ft_strlen(all[fd]) - len);
		free(all[fd]);
		all[fd] = ft_strdup(temp);
		free(temp);
	}
	else
	{
		*line = ft_strdup(all[fd]);
		ft_strdel(&all[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*all[OPEN_MAX];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (all[fd] == NULL)
			all[fd] = ft_strnew(1);
		if (!(all[fd] = ft_strjoin_free(all[fd], buff, 1)))
			return (-1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (all[fd] == NULL || all[fd][0] == '\0'))
		return (0);
	return (line_make(fd, all, line));
}
