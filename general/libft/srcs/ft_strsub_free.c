//
// Created by positivedespair on 7/25/20.
//
#include "libft.h"

//char	*ft_strsub_free(char const *s,
//                   unsigned int start, size_t len, short freeOrNot)
//{
//    char			*dest;
//    unsigned int	i;
//
//    if (!s)
//        return (NULL);
//    if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
//        return (NULL);
//    dest[len] = '\0';
//    i = 0;
//    while (len-- > 0)
//    {
//        dest[i] = s[start];
//        i++;
//        start++;
//    }
//    if (freeOrNot)
//        free((void*)s);
//    return (dest);
//}

char	*ft_strsub_free(char const *s,
                        unsigned int start, size_t len, short freeOrNot)
{
    char	*result;
    size_t	i;

    i = 0;
    if (!s || start + len > ft_strlen(s))
        return (NULL);
    if ((result = ft_strnew(len)))
    {
        while (len)
        {
            result[i++] = s[start++];
            len--;
        }
        result[i] = '\0';
    }
    if (freeOrNot)
        free((void*)s);
    return (result);
}