//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

int         checkCommand(char *command)
{
    if (!ft_strcmp(command, "sa"))
        return (0);
    else if (!ft_strcmp(command, "sb"))
        return (1);
    else if (!ft_strcmp(command, "ss"))
        return (2);
    else if (!ft_strcmp(command, "pa"))
        return (3);
    else if (!ft_strcmp(command, "pb"))
        return (4);
    else if (!ft_strcmp(command, "ra"))
        return (5);
    else if (!ft_strcmp(command, "rb"))
        return (6);
    else if (!ft_strcmp(command, "rr"))
        return (7);
    else if (!ft_strcmp(command, "rra"))
        return (8);
    else if (!ft_strcmp(command, "rrb"))
        return (9);
    else if (!ft_strcmp(command, "rrr"))
        return (10);
    else
        return (-1);
}



void        readingFromSTDIN(t_dynamicArr    **dArr)
{
//    char			buff[BUFF_SIZE + 1];
//    char            *all;
//    int             ret;
//    int             command;
//
//    all = ft_strnew(1);
//    while ((ret = read(0, buff, BUFF_SIZE)) > 0)
//    {
//        buff[ret] = 0;
//        //Needing to be freed!
//        command = checkCommand(ft_strsub(buff, 0, ft_strchrn(buff, '\n')));
//        if (command == -1)
//            error();
//        else
//            addDArr(dArr, command);
//        if (!(all = ft_strjoin_free(all, buff, 1)))
//            exit(1);
//        printf("%d", ret);
//    }
    char *line;
    int size;
    int command;

    *dArr = NULL;
    while ((size = ft_get_next_line(0, &line)) > 0)
    {
        command = checkCommand(line);
        if (command == -1)
            error();
        else
            addDArr(dArr, command);
        free(line);
    }

}