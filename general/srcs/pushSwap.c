//
// Created by Sole Dagger on 13/02/2020.
//

//
// Created by shika on 10.02.2020.
//
#include <includes/push_swap.h>
#include "push_swap.h"

void free_sts_stacks(const t_sts *sts);
void           init_chunks_comm(t_sts *sts, int how_many_chunks);

t_sts *get_sts(void);

char *get_string(t_stack *stackSwap);

void        change_chr(char *string, char f, char c)
{
    int i;

    i = 0;
    while (string[i])
    {
        if (string[i] == f)
            string[i] = c;
        i++;
    }
}

/*
 * Additional function to sort three elements
 */
char        *get_str_commands3(int *minMeanMax, int *swap)
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


char *sort_three(t_sts *sts, int flag)
{
    sts->commands = get_string(*(sts->stackA));
    if (!sts->commands)
        error_tf("sort_three_elements strdup malloc", FALSE);
    if (!(sts->dArr = get_darr_commands(sts->commands)))
        error_tf("sort_three_elements darr error", FALSE);
    exec_commands(sts->dArr, sts->stackA, NULL, 0);
    if (flag == 0)
        change_chr(sts->commands, ' ', '\n');
    return (sts->commands);
}

/*
 * Additional function to sort three items
 */
char *get_string(t_stack *stackSwap)
{
    int minMeanMax[3];
    int i;
    int swap[3];

    i = 0;
    while (i != 3)
    {
        minMeanMax[i] = stackSwap->value;
        stackSwap = stackSwap->previous;
        i++;
    }
    cpyIntArray(swap, minMeanMax, 0, 3);
    if (minMeanMax[0] > minMeanMax[2])
        ft_swap(&minMeanMax[0], &minMeanMax[2]);
    if (minMeanMax[0] > minMeanMax[1])
        ft_swap(&minMeanMax[0], &minMeanMax[1]);
    if (minMeanMax[1] > minMeanMax[2])
        ft_swap(&minMeanMax[1], &minMeanMax[2]);
    return (get_str_commands3(minMeanMax, swap));
}

void       *sort_two(t_sts *sts)
{
    printf("sa\n");
    free_sts(sts);
    exit(0);
}

/*
 * Function to check if value in stack
 */
int         exist_in_stack(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return TRUE;
        stack = stack->previous;
    }
    return FALSE;
}

/*
 * The function find next number for current value in stackA
 * The next number is the element before which you need to put a value
 */
int         find_next_stacka(t_sts *sts, int value)
{
    int index;
    t_stack *stack;
    int     i;

    stack = *(sts->stackA);

    index = binary_search(sts->chunks->array, sts->chunks->len, value) + 1;
    if (smaller_or_greater(stack, value))
        index = 0;
    while (index != sts->chunks->len)
    {
        if (exist_in_stack(stack, sts->chunks->array[index]) == TRUE)
            break;
        index++;
    }

    i = 0;
    while (stack)
    {
        if (stack->value == sts->chunks->array[index])
            return (i);
        i++;
        stack = stack->previous;
    }
    error_tf("Cant find the next number in find_next_stacka function", FALSE);
}

/*
 * The function find next number for current value in stackB
 * The next number is the element before which you need to put a value
 */
int         find_next_stackb(t_sts *sts, int value)
{
    int index;
    t_stack *stack;
    int     i;

    stack = *(sts->stackB);

    index = binary_search(sts->chunks->array, sts->chunks->len, value) - 1;
    if (smaller_or_greater(stack, value))
        index = sts->chunks->len - 1;
    while (index >= 0)
    {
        if (exist_in_stack(stack, sts->chunks->array[index]) == TRUE)
            break;
        index--;
    }

    i = 0;
    while (stack)
    {
        if (stack->value == sts->chunks->array[index])
            return (i);
        i++;
        stack = stack->previous;
    }
    error_tf("Cant find the next number in find_next_stacka function\n", FALSE);
}

t_command   *ra_or_rra(t_sts *sts, int value)
{
    int         lenOfStackA;
    t_command   *comm;
    int         i;

    i = 0;
    lenOfStackA = (*(sts->stackA))->len;
    if (!(comm = (t_command*)malloc(sizeof(t_command))))
        error_tf("ra_or_rra malloc ft_error", FALSE);

    /*
     * Change to another
     */
    i = find_next_stacka(sts, value);
    comm->command = i <= lenOfStackA - i ? "ra " : "rra ";
    comm->count = i <= lenOfStackA - i ? i : lenOfStackA - i;

    return comm;
}

t_command   *rb_or_rrb(t_sts *sts, int value)
{
    int         lenOfStackA;
    t_command   *comm;
    int         i;

    i = 0;

    if (!(comm = (t_command*)malloc(sizeof(t_command))))
        error_tf("rb_or_rrb malloc ft_error", FALSE);
    if ((*(sts->stackB)) == NULL)
    {
        comm->count = 0;
        return (comm);
    }
    lenOfStackA = (*(sts->stackB))->len;
    /*
     * Change to another
     */
    i = find_next_stackb(sts, value);
    comm->command = i <= lenOfStackA - i ? "rb " : "rrb ";
    comm->count = i <= lenOfStackA - i ? i : lenOfStackA - i;

    return comm;
}

char   *commands_from_tcomm(t_command *comm, char const *paOrPb)
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

void    do_r_or_rr(t_sts *sts, int value, char *paOrPb)
{
    t_command   *comm;
    char        *commas;

    if (!ft_strcmp(paOrPb, "pa "))
        comm = ra_or_rra(sts, value);
    else
        comm = rb_or_rrb(sts, value);
    commas = commands_from_tcomm(comm, paOrPb);
    free(comm);
    if (!(sts->dArr = get_darr_commands(commas)))
        error_tf("do_r_or_rr getdarrcommands error", FALSE);
    exec_commands(sts->dArr, sts->stackA, sts->stackB, 0);
    if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
        error_tf("do_r_or_rr ft_strjoin free error", FALSE);
}

/*
 * Returns 1 if value greater than all in given stack
 * 0 if not greater or smaller
 * -1 if smaller
 */
int         smaller_or_greater(t_stack *stack, int value)
{
    int min;
    int max;

    min = stack->value;
    max = stack->value;

    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        if (stack->value < min)
            min = stack->value;
        stack = stack->previous;
    }

    if (value > max)
        return (1);
    else if (value < min)
        return (-1);
    else
        return (0);
}

void        doIfSmallerOrGreater(t_sts *sts, int smallOrBig, int paOrPb)
{
    t_dynamicArr *dArr;
    char          *commands;


    if (smallOrBig == 1)
    {
        if (paOrPb == 1)
            commands = ft_strdup("pa ra ");
        else
            commands = ft_strdup("pb rb ");
        sts->commands = ft_strjoin_free(sts->commands, commands, 1);
        dArr = get_darr_commands(commands);
        exec_commands(dArr, sts->stackA, sts->stackB, 0); // remove flag
    }
    else
    {
        if (paOrPb == 1)
            commands = ft_strdup("pa ");
        else
            commands = ft_strdup("pb ");
        sts->commands = ft_strjoin_free(sts->commands, commands, 1);
        dArr = get_darr_commands(commands);
        exec_commands(dArr, sts->stackA, sts->stackB, 0); // remove flag
    }
    free(commands);

}

void        sort_end(t_sts *sts)
{
    int i;
    t_stack *stack;
    char        *commas;
    int         lenOfStackA;


    stack = *(sts->stackA);
    i = 0;
    lenOfStackA = sts->chunks->len;
    while (stack)
    {
        if (stack->value == sts->chunks->array[0])
            break;
        stack = stack->previous;
        i++;
    }

    sts->comm->command = i <= lenOfStackA - i ? "ra " : "rra ";
    sts->comm->count = i <= lenOfStackA - i ? i : lenOfStackA - i;
    commas = commands_from_tcomm(sts->comm, NULL);
    sts->dArr = get_darr_commands(commas);
    exec_commands(sts->dArr, sts->stackA, sts->stackB, 0);
    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
}

int         find_id_max_in_stack(t_stack *stack)
{
    int i;
    int max;
    int maxId;

    i = 0;
    max = stack->value;
    maxId = 0;
    while (stack)
    {
        if (stack->value > max)
        {
            max = stack->value;
            maxId = i;
        }
        i++;
        stack = stack->previous;
    }

    return (maxId);
}

void        sort_end_stackb(t_sts *sts)
{
    int         i;
    char        *commas;
    int         lenOfStack;

    i = find_id_max_in_stack(*(sts->stackB));
    lenOfStack = sts->chunks->len;
    if (i == 0)
        return ;
    sts->comm->command = i <= lenOfStack - i ? "rb " : "rrb ";
    sts->comm->count = i <= lenOfStack - i ? i : lenOfStack - i;
    commas = commands_from_tcomm(sts->comm, NULL);
    if (!(sts->dArr = get_darr_commands(commas)))
        error_tf("sort_end_stackb get_darr_commands malloc error", FALSE);
    exec_commands(sts->dArr, sts->stackA, sts->stackB, 0);
    if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
        error_tf("sort_end_stackb ft_strjoin_free malloc error", FALSE);
}

char        *sort_five(t_sts *sts)
{
    int             smallerOrGreat;

    /*
     * First commands always be "pb pb"
     */
    init_chunks_comm(sts, 1);
    sts->commands = (*(sts->stackA))->len == 4 ? ft_strdup("pb ") : ft_strdup("pb pb ");
    if (!sts->commands)
        error_tf("sort_five ft_strdup malloc error", FALSE);

    if (!(sts->dArr = get_darr_commands(sts->commands)))
        error_tf("sort_five darr error", FALSE);
    exec_commands(sts->dArr, sts->stackA, sts->stackB, 0);
    if (stack_is_sorted(*(sts->stackA)) == FALSE)
        if (!(sts->commands = ft_strjoin_free(sts->commands, sort_three(sts, 1), 0)))
            error_tf("sort_five ft_strjoin_free error", FALSE);
    while (*(sts->stackB))
    {
        /*
         * There is we check number from stack B. If he greater or smaller than all numbers in stackA
         * We do "doIfSmallerOrGreater"
         * Else we should insert number from stack B between some numbers in stackA
         */
        do_r_or_rr(sts, (*(sts->stackB))->value, "pa ");
    }
    if (stack_is_sorted(*(sts->stackA)) == FALSE)
        sort_end(sts);
    change_chr(sts->commands, ' ', '\n');
    return (sts->commands);
}

t_chunks    *init_chunks(int len)
{
    t_chunks *chunks;

    if (!(chunks = malloc(sizeof(t_chunks))))
        error_tf("init_chunks malloc", FALSE);
    if (!(chunks->array = malloc(sizeof(int) * (len + 1))))
        error_tf("init_chunks malloc", FALSE);
    if (!(chunks->chunk = malloc(sizeof(int) * (len + 1))))
        error_tf("init_chunks malloc", FALSE);
    chunks->current_c = 0;

    return chunks;
}

void        create_chunks_arr(t_chunks *chunks, int howManyChunks)
{
    int first;
    int other;
    int i;
    int chunkNumber;

    first = chunks->len % howManyChunks + chunks->len / howManyChunks;
    other = chunks->len / howManyChunks;
    i = 0;
    while (first)
    {
        chunks->chunk[i++] = 0;
        first--;
    }
    chunkNumber = 1;
    howManyChunks--;
    while (howManyChunks)
    {
        first = 0;
        while (first != other)
        {
            chunks->chunk[i] = chunkNumber;
            first++;
            i++;
        }
        chunkNumber++;
        howManyChunks--;
    }
}

t_chunks    *fill_chunks(t_stack *stack, int howManyChunks)
{
    t_chunks *chunks;
    int i;

    chunks = init_chunks(stack->len);

    i = 0;
    chunks->len = stack->len;
    while (i != chunks->len)
    {
        chunks->array[i] = stack->value;
        stack = stack->previous;
        i++;
    }
    ft_quicksort(chunks->array, 0, chunks->len - 1);
    create_chunks_arr(chunks, howManyChunks);
    return (chunks);
}

int         exists_in_chunk(t_stack *stack, t_chunks *chunks, int current_c)
{
    int i;

    while (stack)
    {
        i = 0;
        while (chunks->chunk[i] != current_c)
            i++;
        while (chunks->chunk[i] == current_c)
        {
            if (stack->value == chunks->array[i])
                return (TRUE);
            i++;
        }
        stack = stack->previous;
    }
    return FALSE;
}

void           init_chunks_comm(t_sts *sts, int how_many_chunks)
{
    if (how_many_chunks != FALSE)
        sts->chunks = fill_chunks(*(sts->stackA), how_many_chunks);
    if (!(sts->comm = (t_command*)malloc(sizeof(t_command))))
        error_tf("initSts malloc ft_error", FALSE);
}

int binary_search(int *array, int len, int value)
{
    int l;
    int r;
    int m;

    l = 0;
    r = len - 1;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if (array[m] == value)
            return (m);
        if (array[m] < value)
            l = m + 1;
        else
            r = m - 1;
    }

    return (-1);
}

int        value_in_chunk(t_chunks *chunks, int value)
{
    int index;

    index = binary_search(chunks->array, chunks->len, value);
    if (chunks->chunk[index] == chunks->current_c)
        return (index);
    else
        return (-1);
}

/*
 * Find numbers from current chunk
 * first hold - first number from top of the stack
 * second hold - first number from bottom of the stack
 * first hold
 */
void        find_holds(t_sts *sts)
{
    t_stack     *stack;
    int         i;
    int         j;

    j = 0;
    stack = *(sts->stackA);
    sts->firstHoldI = -1;
    while (stack)
    {
        if (value_in_chunk(sts->chunks, stack->value) != -1)
        {
            sts->firstHoldI = j;
            break;
        }
        stack = stack->previous;
        j++;
    }
    j = 0;
    i = -1;
    stack = *(sts->stackA);
    sts->secondHoldI = -1;
    while (stack)
    {
        if ((i = value_in_chunk(sts->chunks, stack->value)) != -1)
            sts->secondHoldI = j;
        stack = stack->previous;
        j++;
    }
}



void        find_comm(t_sts *sts, int lenOfStack)
{
    int ind;
    int i;
    int j;

    ind = sts->secondHoldI;
    j = ind <= lenOfStack - ind ? ind : lenOfStack - ind;
    ind = sts->firstHoldI;
    i = ind <= lenOfStack - ind ? ind : lenOfStack - ind;
    if (sts->firstHoldI == sts->secondHoldI)
    {
        sts->comm->command = ind <= lenOfStack - ind ? "ra " : "rra ";
        sts->comm->count = ind <= lenOfStack - ind ? ind : lenOfStack - ind;
        return ;
    }
    else if(i <= j)
        sts->comm->command = sts->firstHoldI <= lenOfStack - sts->firstHoldI ? "ra " : "rra ";
    else if(i > j)
        sts->comm->command = sts->secondHoldI <= lenOfStack - sts->secondHoldI ? "ra " : "rra ";
    sts->comm->count = i <= j ? i : j;
}

void        push_to_stackb(t_sts *sts)
{
    char *commas;

    find_holds(sts);
    if (sts->firstHoldI != 0 AND sts->secondHoldI != 0)
    {
        find_comm(sts, (*(sts->stackA))->len);
        commas = commands_from_tcomm(sts->comm, NULL);
        sts->dArr = get_darr_commands(commas);
        exec_commands(sts->dArr, sts->stackA, sts->stackB, 0);
        sts->commands = ft_strjoin_free(sts->commands, commas, 0);
    }
    do_r_or_rr(sts, (*(sts->stackA))->value, "pb ");
}


void        pushToStackA(t_sts *sts)
{
    char    *commas;

    sort_end_stackb(sts);
    sts->comm->command = "pa ";
    sts->comm->count = (*(sts->stackB))->len;
    commas = commands_from_tcomm(sts->comm, NULL);
    sts->dArr = get_darr_commands(commas);
    exec_commands(sts->dArr, sts->stackA, sts->stackB, 0);
    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
    sts->chunks->current_c++;
}

char *sort_all(int how_many_chunks, t_sts *sts)
{
    char        *commas;

    init_chunks_comm(sts, how_many_chunks);
    if (!(sts->commands = ft_strdup("")))
        error_tf("sort_all ft_strdup malloc error", FALSE);
    while (sts->chunks->current_c != how_many_chunks) {
        if (exists_in_chunk(*(sts->stackA), sts->chunks, sts->chunks->current_c) == FALSE)
            sts->chunks->current_c++;
        if (sts->chunks->current_c != how_many_chunks)
            push_to_stackb(sts);
    }
    sort_end_stackb(sts);
    sts->comm->command = "pa ";
    sts->comm->count = (*(sts->stackB))->len;
    commas = commands_from_tcomm(sts->comm, NULL);
    if (!(sts->dArr = get_darr_commands(commas)))
        error_tf("sort_all get_darr_commands malloc error", FALSE);
    exec_commands(sts->dArr, sts->stackA, sts->stackB, 0);
    if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
        error_tf("sort_all ft_strjoin_free malloc error", FALSE);
    change_chr(sts->commands, ' ', '\n');
    return sts->commands;
}

void        sort_stack(t_sts *sts)
{
    char    *commands;
    t_stack **stackA;
    t_stack **stackB;

    stackA = sts->stackA;
    stackB = sts->stackB;
    if ((*stackA)->len == 2)
        sort_two(sts);
    else if ((*stackA)->len == 3)
        commands = sort_three(sts, 0);
    else if ((*stackA)->len <= 5)
        commands = sort_five(sts);
    else if ((*stackA)->len <= 100)
        commands = sort_all(5, sts);
    else if ((*stackA)->len <= 500)
        commands = sort_all(11, sts);
    else
        commands = sort_all(30, sts);

    printf("%s", commands);
}

int         *arr_from_stack(t_stack *stack, int sortOrNot)
{
    int *array;
    int i;

    i = 0;
    if (!(array = malloc(sizeof(int) * stack->len)))
        error_tf("malloc arr_from_stack err!\n", FALSE);
    while (stack)
    {
        array[i] = stack->value;
        stack = stack->previous;
        i++;
    }
    if (sortOrNot)
        ft_quicksort(array, 0, i - 1);
    return (array);
}

int         check_dublicates(t_stack *stack)
{
    int *array;
    int i;
    int previous;

    i = 1;
    array = arr_from_stack(stack, TRUE);
    previous = array[0];
    while (i != stack->len)
    {
        if (array[i] == previous)
            return (TRUE);
        previous = array[i];
        i++;
    }
    free(array);
    return (FALSE);
}



int         main(int argc, char **argv)
{
    int             i;
    t_sts           *sts;
    t_stack         *stackA;
    t_stack         *stackB;

    stackA = NULL;
    stackB = NULL;
    sts = error_tf(NULL, TRUE);
//    sts->stackA = &stackA;
//    sts->stackB = &stackB;
    if (argc == 1)
        return (0);
    else
    {
        /*
         *  Filling stackA from program arguments
         */
        i = argc == 2 ? (int)ft_w_count(argv[1], ' ') -1 : argc - 1;
        argv = argc == 2 ? ft_strsplit(argv[1], ' ') : argv;
        argc = argc == 2 ? -1 : 0;
        sts->flag = FALSE;
        while (i != argc)
        {
            if (!ft_strcmp(argv[i], "-v"))
                sts->flag = TRUE;
            else if (isOnlyDigits(argv[i]) == FALSE)
                ft_error_t("There is non numeric param!");
            else
                push_stack(sts->stackA, ft_atoi(argv[i]));
            i--;
        }
    }

    if (check_dublicates(*(sts->stackA)))
        error_tf("There are dublicates\n", FALSE);
    if (!stack_is_sorted(*(sts->stackA)))
        sort_stack(sts);
    free_sts(sts);
    return (0);
}