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

/*
** filling stack_a from program arguments
*/

void	read_args(int argc, char **argv, t_sts *sts)
{
	int i;

	i = argc == 2 ? (int)ft_w_count(argv[1], ' ') - 1 : argc - 1;
	argv = argc == 2 ? ft_strsplit(argv[1], ' ') : argv;
	argc = argc == 2 ? -1 : 0;
	sts->flag = FALSE;
	while (i != argc)
	{
		if (!ft_strcmp(argv[i], "-v"))
			sts->flag = TRUE;
		else if (isOnlyDigits(argv[i]) == FALSE)
			error_tf("There is non numeric param!", FALSE);
		else
			push_stack(sts->stackA, ft_atoi(argv[i]));
		i--;
	}
}

void        reading_from_stdin(t_dynamicArr    **dArr)
{
    char *line;
    int size;
    int command;

    *dArr = NULL;
    while ((size = ft_get_next_line(0, &line)) > 0)
    {
    	if (!line)
    		error_tf("reading_from_stdin gnl malloc error", FALSE);
        command = checkCommand(line);
        if (command == -1)
            ft_error();
        else
            addDArr(dArr, command);
        free(line);
    }

}