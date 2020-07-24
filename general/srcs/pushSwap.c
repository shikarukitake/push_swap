//
// Created by Sole Dagger on 13/02/2020.
//

//
// Created by shika on 10.02.2020.
//
#include <includes/push_swap.h>
#include "push_swap.h"

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

t_dynamicArr    *getDArrCommands3(char *commands)
{
    int             n;
    char            *swap;
    t_dynamicArr    *dArr;
    char            *command;

    dArr = NULL;
    swap = ft_strdup(commands);
    while(ft_strcmp(commands, ""))
    {
        n = ft_strchrn(commands, ' ');
        command = ft_strsub(commands, 0, n);
        addDArr(&dArr, checkCommand(command));
        commands = ft_strsub(commands, n + 1, ft_strlen(commands));
        free(command);
    }
    free(swap);
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

t_command   *ra_or_rra(t_stack *stackA, int value)
{
    int         lenOfStackA;
    t_command   *comm;
    int         i;

    i = 0;
    lenOfStackA = stackA->len;
    if ((comm = (t_command*)malloc(sizeof(t_command))))
        errorText("ra_or_rra malloc error");

    /*
     * Change to another
     */
    while (stackA)
    {
        if (value < stackA->value)
            break;
        stackA = stackA->previous;
        i++;
    }
    comm->command = i <= lenOfStackA - i ? "ra " : "rra ";
    comm->commandRev = i <= lenOfStackA - i ? "rra " : "ra ";
    comm->count = i <= lenOfStackA - i ? i : lenOfStackA - i;

    return comm;
}

char   *commandsFromTComm(t_command *comm, char const *paOrPb)
{
    char    *commands;
    int     count;

    commands = ft_strnew(1);
    if (!ft_strcmp(comm->commandRev, "ra "))
        count = comm->count + 1;
    else
        count = comm->count;
    while (comm->count)
    {
        commands = ft_strjoin_free(commands, comm->command, 1); //maybe n should be 0
        comm->count--;
    }
    commands = ft_strjoin_free(commands, paOrPb, 1);
    while (comm->count != count)
    {
        commands = ft_strjoin_free(commands, comm->commandRev, 1); //maybe n should be 0
        comm->count++;
    }
    free(comm);
    return commands;
}

void    doRaOrRra(t_stack **stackA, t_stack **stackB, char **commands, char const paOrPb)
{
    t_dynamicArr *dArr;
    t_command   *comm;
    char        *commas;

    comm = ra_or_rra(*stackA, (*stackB)->value);
    commas = commandsFromTComm(comm, paOrPb);

    dArr = getDArrCommands3(commas);
    execCommands(dArr, stackA, stackB, 0);
    free(dArr->array);
    free(dArr);
    *commands = ft_strjoin_free(*commands, commas, 0);
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

void        doIfSmallerOrGreater(char **commands, t_stack **stackA, t_stack **stackB, int smallOrBig)
{
    t_dynamicArr *dArr;


    if (smallOrBig == 1)
    {
        *commands = ft_strjoin_free(*commands, "pa ra ", 1);
        dArr = getDArrCommands3("pa ra ");
        execCommands(dArr, stackA, stackB, 0); // remove flag
    }
    else
    {
        *commands = ft_strjoin_free(*commands, "pa ", 1);
        dArr = getDArrCommands3("pa ");
        execCommands(dArr, stackA, stackB, 0); // remove flag
    }
    free(dArr->array);
    free(dArr);
}



char        *sortFiveElements(t_stack **stackA, t_stack **stackB)
{
    char            *commands;
    t_dynamicArr    *dArr;
    t_command       *comm;
    int             smallerOrGreat;

    /*
     * First commands always be "pb pb"
     */
    commands = (*stackA)->len == 4 ? ft_strdup("pb ") : ft_strdup("pb pb ");

    dArr = getDArrCommands3(commands);
    execCommands(dArr, stackA, stackB, 0);
    if (stackIsSorted(*stackA) == FALSE)
        commands = ft_strjoin_free(commands, sortThreeElements(stackA, NULL, 1), 0);
    while (*stackB)
    {
        /*
         * There is we check number from stack B. If he greater or smaller than all numbers in stackA
         * We do "doIfSmallerOrGreater"
         * Else we should insert number from stack B between some numbers in stackA
         */
        if ((smallerOrGreat = smallerOrGreater(*stackA, (*stackB)->value)))
            doIfSmallerOrGreater(&commands, stackA, stackB, smallerOrGreat);
        else
            doRaOrRra(stackA, stackB, &commands);
    }
    changeChr(commands, ' ', '\n');
    return (commands);
}

char        *sortElements(t_stack **stackA, t_stack **stackB)
{

}

int partition (int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;

    pivot = arr[high];
    i = (low - 1);
    j = low;
    while (j <= high - 1)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            ft_swap(&arr[i], &arr[j]);
        }
        j++;
    }
    ft_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
    int pi;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

t_chunks    *init_chunks(int len)
{
    t_chunks *chunks;

    if (!(chunks = malloc(sizeof(t_chunks))))
        error();
    if (!(chunks->array = malloc(sizeof(int) * len)))
        error();
    if (!(chunks->chunk = malloc(sizeof(int) * len)))
        error();
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
    quickSort(chunks->array, 0, chunks->len - 1);
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
        errorText("sts (sortOneHundred) malloc error");
    else
    {
        sts->stackA = stackA;
        sts->stackB = stackB;
        if (howManyChunks != FALSE)
            sts->chunks = fill_chunks(*stackA, 5);
        if ((sts->comm = (t_command*)malloc(sizeof(t_command))))
            errorText("initSts malloc error");
        return sts;
    }
    return NULL;
}

int         findIndex(int *array, int len, int value)
{
    int i;

    i = len / 2;

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


    stack = *(sts->stackA);
    sts->firstHoldI = -1;
    while (stack)
    {
        if (sts->firstHoldI != -1)
            break;
        sts->firstHoldI = currentValueInChunk(sts->chunks, stack->value);
        stack = stack->previous;
    }

    i = -1;
    stack = *(sts->stackA);
    sts->secondHoldI = -1;
    while (stack)
    {
        if ((i = currentValueInChunk(sts->chunks, stack->value)) != -1)
            sts->secondHoldI = i;
        stack = stack->previous;
    }
}



void        findComm(t_sts *sts, int lenOfStack)
{
    int i;

    if (sts->firstHoldI == sts->secondHoldI)
    {
        i = sts->firstHoldI;
        sts->comm->command = i <= lenOfStack - i ? "ra " : "rra ";
        sts->comm->commandRev = i <= lenOfStack - i ? "rra " : "ra ";
        sts->comm->count = i <= lenOfStack - i ? i : lenOfStack - i;
    }
}

void        pushToStackB(t_sts *sts)
{
    t_dynamicArr *dArr;

    findHolds(sts);
    findComm(sts, (*(sts->stackA))->len);

//    execCommands(dArr, )
}

char        *sortOneHundred(t_stack **stackA, t_stack **stackB)
{
    t_sts       *sts;


    sts = initSts(stackA, stackB, 5);
    while (sts->chunks->current_c != 5)
    {
        if (existsInChunk(*stackA, sts->chunks, sts->chunks->current_c) == FALSE)
            sts->chunks->current_c++;
        pushToStackB(sts);

    }


    return sts->commands;
}

void        sortStack(t_stack **stackA, t_stack **stackB)
{
    char *commands;

    if ((*stackA)->len == 2)
        commands = sortTwoElements(stackA);
    else if ((*stackA)->len == 3)
        commands = sortThreeElements(stackA, NULL, 0);
    else if ((*stackA)->len <= 5)
        commands = sortFiveElements(stackA, stackB);
    else if ((*stackA)->len <= 100)
        commands = sortOneHundred(stackA, stackB);
    else
        errorText("Unknown sort case");

    printf("%s", commands);
    free(commands);

}

int         main(int argc, char **argv)
{
    t_stack         *stackA;
    t_stack         *stackB;
    int             i;
    int             flag;

    stackA = NULL;
    stackB = NULL;
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
        flag = 0;

        while (i != argc)
        {
            if (!ft_strcmp(argv[i], "-v"))
                flag = 1;
            else if (isOnlyDigits(argv[i]) == FALSE)
            {
                printf("Error\n");
                return (0);
            }
            else
                pushStack(&stackA, ft_atoi(argv[i]));
            i--;
        }
    }

    if (stackIsSorted(stackA) == FALSE)
        sortStack(&stackA, &stackB);
    return (0);
}