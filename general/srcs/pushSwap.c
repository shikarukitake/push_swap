//
// Created by Sole Dagger on 13/02/2020.
//

//
// Created by shika on 10.02.2020.
//
#include <includes/push_swap.h>
#include "push_swap.h"

void free_sts_stacks(const t_sts *sts);

t_sts *get_sts(void);

void        changeChr(char *string, char f, char c)
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

char        *getStrCommands3(int *minMeanMax, int *swap)
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

t_dynamicArr    *getDArrCommands3(char *commandz)
{
    int             n;
    char            *commands;
    t_dynamicArr    *dArr;
    char            *command;

    dArr = NULL;
    commands = ft_strdup(commandz);
    while(commands AND ft_strcmp(commands, ""))
    {
        n = ft_strchrn(commands, ' ');
        command = ft_strsub_free(commands, 0, n, 0);
        addDArr(&dArr, checkCommand(command));
        commands = ft_strsub_free(commands, n + 1, ft_strlen(commands) - (n + 1), 1);
        free(command);
    }
    free(commands);
    return (dArr);
}

char        *sortThreeElements(t_stack **stackA, char *some, int flag)
{
    int minMeanMax[3];
    int i;
    int swap[3];
    t_stack *stackSwap;
    t_dynamicArr *dArr;

    stackSwap = *stackA;
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
    some = getStrCommands3(minMeanMax, swap);
    dArr = getDArrCommands3(some);
    execCommands(dArr, stackA, NULL, 0);
    if (flag == 0)
        changeChr(some, ' ', '\n');
    return some; //change to ft_printf

}

char        *sortTwoElements(t_stack **stackA)
{
    return (ft_strdup("sa\n"));
}

int         existInStack(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return TRUE;
        stack = stack->previous;
    }
    return FALSE;
}

int         findNext(t_sts *sts, int value)
{
    int index;
    t_stack *stack;
    int     i;

    stack = *(sts->stackA);

    index = binarySearch(sts->chunks->array, sts->chunks->len, value) + 1;
    if (smallerOrGreater(stack, value))
        index = 0;
    while (index != sts->chunks->len)
    {
        if (existInStack(stack, sts->chunks->array[index]) == TRUE)
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
    ft_error_t("Cant find the next number in findNext function\n");
}

int         findNextStackB(t_sts *sts, int value)
{
    int index;
    t_stack *stack;
    int     i;

    stack = *(sts->stackB);

    index = binarySearch(sts->chunks->array, sts->chunks->len, value) - 1;
    if (smallerOrGreater(stack, value))
        index = sts->chunks->len - 1;
    while (index >= 0)
    {
        if (existInStack(stack, sts->chunks->array[index]) == TRUE)
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
    ft_error_t("Cant find the next number in findNext function\n");
}

t_command   *ra_or_rra(t_sts *sts, int value)
{
    int         lenOfStackA;
    t_command   *comm;
    int         i;

    i = 0;
    lenOfStackA = (*(sts->stackA))->len;
    if (!(comm = (t_command*)malloc(sizeof(t_command))))
        ft_error_t("ra_or_rra malloc ft_error");

    /*
     * Change to another
     */
    i = findNext(sts, value);
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
        ft_error_t("rb_or_rrb malloc ft_error\n");
    if ((*(sts->stackB)) == NULL)
    {
        comm->count = 0;
        return (comm);
    }
    lenOfStackA = (*(sts->stackB))->len;
    /*
     * Change to another
     */
    i = findNextStackB(sts, value);
    comm->command = i <= lenOfStackA - i ? "rb " : "rrb ";
    comm->count = i <= lenOfStackA - i ? i : lenOfStackA - i;

    return comm;
}

char   *commandsFromTComm(t_command *comm, char const *paOrPb)
{
    char    *commands;
    int     count;

    count = comm->count;
    commands = ft_strnew(1);

    while (count)
    {
        commands = ft_strjoin_free(commands, comm->command, 1); //maybe n should be 0
        count--;
    }
    if (paOrPb != NULL)
        commands = ft_strjoin_free(commands, paOrPb, 1);

    return commands;
}

void    doRaOrRra(t_sts *sts, int value, char *paOrPb)
{
    t_dynamicArr *dArr;
    t_command   *comm;
    char        *commas;

    if (!ft_strcmp(paOrPb, "pa "))
        comm = ra_or_rra(sts, value);
    else
        comm = rb_or_rrb(sts, value);
    commas = commandsFromTComm(comm, paOrPb);
    free(comm);
    sts->dArr = getDArrCommands3(commas);
    execCommands(sts->dArr, sts->stackA, sts->stackB, 0);
//    free(sts->dArr->array);
//    free(sts->dArr);
    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
}

/*
 * Returns 1 if value greater than all in given stack
 * 0 if not greater or smaller
 * -1 if smaller
 */
int         smallerOrGreater(t_stack *stack, int value)
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
        dArr = getDArrCommands3(commands);
        execCommands(dArr, sts->stackA, sts->stackB, 0); // remove flag
    }
    else
    {
        if (paOrPb == 1)
            commands = ft_strdup("pa ");
        else
            commands = ft_strdup("pb ");
        sts->commands = ft_strjoin_free(sts->commands, commands, 1);
        dArr = getDArrCommands3(commands);
        execCommands(dArr, sts->stackA, sts->stackB, 0); // remove flag
    }
    free(commands);

}

void        sortInEnd(t_sts *sts)
{
    int i;
    t_stack *stack;
    char        *commas;
    int         lenOfStackA;

//    stack = stackAorStackB == 1 ? *(sts->stackA) : *(sts->stackB);
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

    if (!(sts->comm = (t_command*)malloc(sizeof(t_command))))
        ft_error_t("sortInEnd malloc ft_error\n");
    sts->comm->command = i <= lenOfStackA - i ? "ra " : "rra ";
    sts->comm->count = i <= lenOfStackA - i ? i : lenOfStackA - i;


    commas = commandsFromTComm(sts->comm, NULL);
    sts->dArr = getDArrCommands3(commas);
    execCommands(sts->dArr, sts->stackA, sts->stackB, 0);
    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
}

//void        sortInEndStackB(t_sts *sts)
//{
//    int i;
//    t_stack *stack;
//    char        *commas;
//    int         lenOfStack;
//
//    stack = *(sts->stackB);
//    i = 0;
//    lenOfStack = sts->chunks->len;
//    while (stack)
//    {
//        if (stack->value == sts->chunks->array[sts->chunks->len - 1])
//            break;
//        stack = stack->previous;
//        i++;
//    }
//    if (i == 0)
//        return ;
//    if (!(sts->comm = (t_command*)malloc(sizeof(t_command))))
//        ft_error_t("sortInEnd malloc ft_error\n");
//    sts->comm->command = i <= lenOfStack - i ? "rb " : "rrb ";
//    sts->comm->count = i <= lenOfStack - i ? i : lenOfStack - i;
//
//
//    commas = commandsFromTComm(sts->comm, NULL);
//    sts->dArr = getDArrCommands3(commas);
//    execCommands(sts->dArr, sts->stackA, sts->stackB, 0);
//    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
//}

int         findMaxInStack(t_stack *stack)
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

void        sortInEndStackB(t_sts *sts)
{
    int         i;
//    t_stack     *stack;
    char        *commas;
    int         lenOfStack;

//    stack = *(sts->stackB);
    i = findMaxInStack(*(sts->stackB));
    lenOfStack = sts->chunks->len;
//    while (stack)
//    {
//        if (stack->value == sts->chunks->array[sts->chunks->len - 1])
//            break;
//        stack = stack->previous;
//        i++;
//    }

    if (i == 0)
        return ;
    if (!(sts->comm = (t_command*)malloc(sizeof(t_command))))
        ft_error_t("sortInEnd malloc ft_error\n");
    sts->comm->command = i <= lenOfStack - i ? "rb " : "rrb ";
    sts->comm->count = i <= lenOfStack - i ? i : lenOfStack - i;


    commas = commandsFromTComm(sts->comm, NULL);
    sts->dArr = getDArrCommands3(commas);
    execCommands(sts->dArr, sts->stackA, sts->stackB, 0);
    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
}

char        *sortFiveElements(t_stack **stackA, t_stack **stackB)
{
    t_sts           *sts;
    int             smallerOrGreat;

    /*
     * First commands always be "pb pb"
     */
    sts = initSts(stackA, stackB, 1);
    sts->commands = (*stackA)->len == 4 ? ft_strdup("pb ") : ft_strdup("pb pb ");

    sts->dArr = getDArrCommands3(sts->commands);
    execCommands(sts->dArr, stackA, stackB, 0);
    if (stackIsSorted(*stackA) == FALSE)
        sts->commands = ft_strjoin_free(sts->commands, sortThreeElements(sts->stackA, NULL, 1), 0);
    while (*(sts->stackB))
    {
        /*
         * There is we check number from stack B. If he greater or smaller than all numbers in stackA
         * We do "doIfSmallerOrGreater"
         * Else we should insert number from stack B between some numbers in stackA
         */
//        if ((smallerOrGreat = smallerOrGreater(*(sts->stackA), (*(sts->stackB))->value)))
//            doIfSmallerOrGreater(sts, smallerOrGreat, 1);
//        else
        doRaOrRra(sts, (*(sts->stackB))->value, "pa ");
    }
    if (stackIsSorted(*(sts->stackA)) == FALSE)
        sortInEnd(sts);
    changeChr(sts->commands, ' ', '\n');
    return (sts->commands);
}

t_chunks    *init_chunks(int len)
{
    t_chunks *chunks;

    if (!(chunks = malloc(sizeof(t_chunks))))
        ft_error();
    if (!(chunks->array = malloc(sizeof(int) * len)))
        ft_error();
    if (!(chunks->chunk = malloc(sizeof(int) * len)))
        ft_error();
    chunks->current_c = 0;

    return chunks;
}

void        createChunksArray(t_chunks *chunks, int howManyChunks)
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
    while (stack)
    {
        chunks->array[i] = stack->value;
        stack = stack->previous;
        i++;
    }
    ft_quicksort(chunks->array, 0, chunks->len - 1);
    createChunksArray(chunks, howManyChunks);
    return (chunks);
}

int         existsInChunk(t_stack *stack, t_chunks *chunks, int current_c)
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

t_sts        *initSts(t_stack **stackA, t_stack **stackB, int howManyChunks)
{
    t_sts       *sts;

    if (!(sts = malloc(sizeof(t_sts))))
        ft_error_t("sts (sortOneHundred) malloc ft_error");
    else
    {
        sts->stackA = stackA;
        sts->stackB = stackB;
        if (howManyChunks != FALSE)
            sts->chunks = fill_chunks(*stackA, howManyChunks);
        if (!(sts->comm = (t_command*)malloc(sizeof(t_command))))
            ft_error_t("initSts malloc ft_error");
        return sts;
    }
    return NULL;
}

int binarySearch(int *array, int len, int value)
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

int        currentValueInChunk(t_chunks *chunks, int value)
{
    int index;

    index = binarySearch(chunks->array, chunks->len, value);
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
void        findHolds(t_sts *sts)
{
    t_stack     *stack;
    int         i;
    int         j;

    j = 0;
    stack = *(sts->stackA);
    sts->firstHoldI = -1;
    while (stack)
    {
        if (currentValueInChunk(sts->chunks, stack->value) != -1)
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
        if ((i = currentValueInChunk(sts->chunks, stack->value)) != -1)
            sts->secondHoldI = j;
        stack = stack->previous;
        j++;
    }
}



void        findComm(t_sts *sts, int lenOfStack)
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

void        pushToStackB(t_sts *sts)
{
    char *commas;

    findHolds(sts);
    if (sts->firstHoldI != 0 AND sts->secondHoldI != 0)
    {
        findComm(sts, (*(sts->stackA))->len);
        commas = commandsFromTComm(sts->comm, NULL);
        sts->dArr = getDArrCommands3(commas);
        execCommands(sts->dArr, sts->stackA, sts->stackB, 0);
        sts->commands = ft_strjoin_free(sts->commands, commas, 0);
    }
    doRaOrRra(sts, (*(sts->stackA))->value, "pb ");
}


void        pushToStackA(t_sts *sts)
{
    char    *commas;

    sortInEndStackB(sts);
    sts->comm->command = "pa ";
    sts->comm->count = (*(sts->stackB))->len;
    commas = commandsFromTComm(sts->comm, NULL);
    sts->dArr = getDArrCommands3(commas);
    execCommands(sts->dArr, sts->stackA, sts->stackB, 0);
    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
    sts->chunks->current_c++;
}

char        *sortOneHundred(t_stack **stackA, t_stack **stackB, int howManyChunks)
{
    t_sts       *sts;
    char        *commas;

    sts = initSts(stackA, stackB, howManyChunks);
    sts->commands = ft_strdup("");
    while (sts->chunks->current_c != howManyChunks)
    {
        if (existsInChunk(*stackA, sts->chunks, sts->chunks->current_c) == FALSE)
            sts->chunks->current_c++;
//            pushToStackA(sts);
        if (sts->chunks->current_c != howManyChunks)
            pushToStackB(sts);
    }
    sortInEndStackB(sts);
    if (!(sts->comm = (t_command*)malloc(sizeof(t_command))))
        ft_error_t("sortOneHundred malloc ft_error\n");
    sts->comm->command = "pa ";
    sts->comm->count = (*(sts->stackB))->len;
    commas = commandsFromTComm(sts->comm, NULL);
    sts->dArr = getDArrCommands3(commas);
    execCommands(sts->dArr, sts->stackA, sts->stackB, 0);
    sts->commands = ft_strjoin_free(sts->commands, commas, 0);
    changeChr(sts->commands, ' ', '\n');
    return sts->commands;
}

void        sortStack(t_sts *sts)
{
    char    *commands;
    t_stack **stackA;
    t_stack **stackB;

    stackA = sts->stackA;
    stackB = sts->stackB;
    if ((*stackA)->len == 2)
        commands = sortTwoElements(stackA);
    else if ((*stackA)->len == 3)
        commands = sortThreeElements(stackA, NULL, 0);
    else if ((*stackA)->len <= 5)
        commands = sortFiveElements(stackA, stackB);
    else if ((*stackA)->len <= 100)
        commands = sortOneHundred(stackA, stackB, 5);
    else if ((*stackA)->len <= 500)
        commands = sortOneHundred(stackA, stackB, 11);
    else
        ft_error_t("Unknown sort case");

    printf("%s", commands);
    free(commands);

}

int         *fillArrayFromStack(t_stack *stack, int sortOrNot)
{
    int *array;
    int i;

    i = 0;
    if (!(array = malloc(sizeof(int) * stack->len)))
        ft_error_t("malloc fillArrayFromStack err!\n");
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

int         checkDublicates(t_stack *stack)
{
    int *array;
    int i;
    int previous;

    i = 1;
    array = fillArrayFromStack(stack, TRUE);
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

void        free_sts(t_sts *sts)
{
    free_sts_stacks(sts);
    if (sts->chunks)
    {
        if (sts->chunks->array)
            free(sts->chunks->array);
        if (sts->chunks->chunk)
            free(sts->chunks->chunk);
        free(sts->chunks);
    }
    if (sts->comm)
        free(sts->comm);
    if (sts->commands)
        free(sts->commands);
    if (sts->dArr)
    {
        if (sts->dArr->array)
            free(sts->dArr->array);
        free(sts->dArr);
    }
    if (sts)
        free(sts);
}

void free_sts_stacks(const t_sts *sts)
{
    if (sts->stackA)
        if (*(sts->stackA))
            free(*(sts->stackA));
    if (sts->stackB)
        if (*(sts->stackB))
            free(*(sts->stackB));
}

t_sts *error_tf(char const *text, char init)
{
    static t_sts *sts;

    if (init) {
        sts = get_sts();
        return (sts);
    }
    free_sts(sts);
    ft_error_t(text);
    return (NULL);
}

t_sts *get_sts(void)
{
    t_sts *sts;

    sts = malloc(sizeof(t_sts));
    if (!sts)
        ft_error_t("init_sts_new malloc error");
    sts->stackA = NULL;
    sts->dArr = NULL;
    sts->commands = NULL;
    sts->comm = NULL;
    sts->stackB = NULL;
    sts->chunks = NULL;
    return (sts);
}

int         main(int argc, char **argv)
{
    int             i;
    int             flag;
    t_stack         *stackA;
    t_stack         *stackB;
    t_sts           *sts;

    sts = error_tf(NULL, TRUE);
    stackA = NULL;
    stackB = NULL;
    sts->stackA = &stackA;
    sts->stackB = &stackB;
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
                pushStack(sts->stackA, ft_atoi(argv[i]));
            i--;
        }
    }

    if (checkDublicates(*(sts->stackA)))
        ft_error_t("There are dublicates\n");
    if (!stackIsSorted(*(sts->stackA)))
        sortStack(sts);
    free_sts(sts);
    return (0);
}