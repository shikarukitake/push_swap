//
// Created by Sole Dagger on 8/1/20.
//

#include "push_swap.h"

/*
 * Additional function to sort three elements
 */
char            *get_str_commands3(int *minMeanMax, int *swap)
{

    if (swap[0] == minMeanMax[2])
    {
        if (swap[1] == minMeanMax[1])
            return ft_strdup("ra sa ");
        return ft_strdup("ra ");
    }
    else if (swap[2] == minMeanMax[0])
        return ft_strdup("rra ");
    if (swap[1] == minMeanMax[2])
        return ft_strdup("sa ra ");
    return ft_strdup("sa ");
}

/*
 * Transform str commands into dArr where command have int value
 */
t_dynamicArr    *get_darr_commands(char *commandz)
{
    int             n;
    char            *commands;
    t_dynamicArr    *dArr;
    char            *command;

    dArr = NULL;
    if (!(commands = ft_strdup(commandz)))
        return (NULL);
    while(commands AND ft_strcmp(commands, ""))
    {
        n = ft_strchrn(commands, ' ');
        if (!(command = ft_strsub_free(commands, 0, n, 0)))
            return (NULL);//protect
        if (!addDArr(&dArr, checkCommand(command)))
            return (NULL);
        if (!(commands = ft_strsub_free(commands, n + 1, ft_strlen(commands) - (n + 1), 1)))
            return (NULL);//protect
        free(command);
    }
    free(commands);
    return (dArr);
}

char            *commands_from_tcomm(t_command *comm, char const *paOrPb)
{
    char    *commands;
    int     count;

    count = comm->count;
    commands = ft_strnew(1);

    while (count)
    {
        if (!(commands = ft_strjoin_free(commands, comm->command, 1)))
            error_tf("commands_from_tcomm ft_strjoin_free error", FALSE);//protect
        count--;
    }
    if (paOrPb != NULL)
        if (!(commands = ft_strjoin_free(commands, paOrPb, 1)))
            error_tf("commands_from_tcomm ft_strjoin_free error", FALSE);;//protect

    return commands;
}