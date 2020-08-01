//
// Created by Sole Dagger on 8/1/20.
//

#include "push_swap.h"

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

int         value_in_chunk(t_chunks *chunks, int value)
{
    int index;

    index = binary_search(chunks->array, chunks->len, value);
    if (chunks->chunk[index] == chunks->current_c)
        return (index);
    else
        return (-1);
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