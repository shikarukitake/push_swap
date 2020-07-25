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


static t_list	*assign_save(t_list **save, int fd)
{
    t_list	*tmp;

    tmp = *save;
    while (tmp)
    {
        if ((int)(tmp->content_size) == fd)
            return (tmp);
        tmp = tmp->next;
    }
    tmp = ft_lstnew("\0", 0);
    ft_lstadd(save, tmp);
    return (*save);
}

static void		cleanup(t_list *ptr)
{
    char	*tmp;

    if ((tmp = ft_strchr(ptr->content, '\n')))
    {
        tmp = ft_strdup(tmp + 1);
        free(ptr->content);
        ptr->content = tmp;
    }
    else
        ft_strclr(ptr->content);
}

static char	*ft_strccpy(char *dst, const char *src, char c)
{
    int		i;

    i = -1;
    while (src[++i] && (src[i] != c))
        dst[i] = src[i];
    dst[i] = '\0';
    return (dst);
}

int				ft_get_next_line(const int fd, char **line)
{
    char			buf[BUFF_SIZE + 1];
    char			*tmp;
    int				check;
    static t_list	*save;
    t_list			*ptr;

    ERROR_CHECK(fd < 0 || line == NULL || read(fd, buf, 0) < 0);
    ptr = assign_save(&save, fd);
    while ((check = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[check] = '\0';
        ERROR_CHECK(!(tmp = ft_strjoin(ptr->content, buf)));
        free(ptr->content);
        ptr->content = tmp;
        BREAK_CHECK((ft_strchr(ptr->content, '\n')));
    }
    if (!check && !ft_strlen(ptr->content))
    {
        ft_strclr(*line);
        return (0);
    }
    ERROR_CHECK(!(*line = ft_strnew(ft_strlen(ptr->content))));
    *line = ft_strccpy(*line, ptr->content, '\n');
    cleanup(ptr);
    return (1);
}
