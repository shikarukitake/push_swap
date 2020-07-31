//
// Created by positivedespair on 7/27/20.
//

#include "libft.h"

void        ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void        ft_error_t(char const *text)
{
    write(2, "Error\n", 6);
    write(2, text, ft_strlen(text));
    write(2, "\n", 1);
    exit(1);
}
