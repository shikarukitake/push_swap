//
// Created by positivedespair on 7/27/20.
//

#include "libft.h"

void        ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void        ft_errorText(char const *text)
{
    write(2, "Error: ", 7);
    write(2, text, ft_strlen(text));
    exit(1);
}