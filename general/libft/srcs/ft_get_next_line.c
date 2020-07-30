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
#define OPEN_MAX 1000 //delete

//static int		line_make(const int fd, char **all, char **line)
//{
//	char	*temp;
//	int		len;
//
//	if (ft_strchr(all[fd], '\n'))
//	{
//		len = ft_strchrn(all[fd], '\n');
//		*line = ft_strsub(all[fd], 0, len);
//		temp = ft_strsub(all[fd], len + 1, ft_strlen(all[fd]) - len);
//		free(all[fd]);
//		all[fd] = ft_strdup(temp);
//		free(temp);
//	}
//	else
//	{
//		*line = ft_strdup(all[fd]);
//		ft_strdel(&all[fd]);
//	}
//	return (1);
//}
//
//int				ft_get_next_line(const int fd, char **line)
//{
//	static char		*all[OPEN_MAX];
//	char			buff[BUFF_SIZE + 1];
//	int				ret;
//
//	if (fd < 0 || line == NULL)
//		return (-1);
//	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
//	{
//		buff[ret] = 0;
//		if (all[fd] == NULL)
//			all[fd] = ft_strnew(1);
//		if (!(all[fd] = ft_strjoin_free(all[fd], buff, 1)))
//			return (-1);
//	}
//	if (ret < 0)
//		return (-1);
//	if (ret == 0 && (all[fd] == NULL || all[fd][0] == '\0'))
//		return (0);
//	return (line_make(fd, all, line));
//}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:27:16 by lsedgeki          #+#    #+#             */
/*   Updated: 2019/12/11 15:53:24 by lsedgeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	ft_line_maker(const int fd, char **help, char **line)
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

int	ft_get_next_line(const int fd, char **line)
{
    static char	*help[256];
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
