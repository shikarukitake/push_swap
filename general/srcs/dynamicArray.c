//
// Created by Sole Dagger on 12/02/2020.
//


#include "checker.h"

void        cpyIntArray(int *dest, int *src, int freeOrNot, int len)
{
    int i;

    i = 0;
    if (dest )
        while (i != len)
        {
            dest[i] = src[i];
            i++;
        }
    if (freeOrNot)
        free(src);
}

t_dynamicArr *initDArrFromInt(int *array, int len)
{
    t_dynamicArr    *new;
    int             i;

    new = NULL;
    if (len > 0)
    {
        i = 0;
        while (i != len)
        {
            addDArr(&new, array[i]);
            i++;
        }
    }
    return (new);
}

int        initDArr(t_dynamicArr **arr)
{
    int *swap;

    if (arr)
    {
        if (*arr)
        {
            swap = (*arr)->array;
            if (!((*arr)->array = (int*)malloc(sizeof(int) * (((*arr)->len * 2) + 2))))
                return (0);//protect
            cpyIntArray((*arr)->array, swap, 1, (*arr)->len);
            (*arr)->freeSpace = (*arr)->len;

        }
        else
        {
            (*arr) = (t_dynamicArr*)malloc(sizeof(t_dynamicArr));
            (*arr)->array = (int*)malloc(sizeof(int)*102); //protect
            if (!(*arr)->array)
                return (0);
            (*arr)->len = 0;
            (*arr)->freeSpace = 100;
        }
    }
    return (1);
}

int        addDArr(t_dynamicArr **arr, int value)
{
    if (arr)
    {
        if (!(*arr))
            if (!initDArr(arr))
                return (0);
        if (!(*arr)->freeSpace)
            if (!initDArr(arr))
                return (0);
        (*arr)->array[(*arr)->len] = value;
        (*arr)->len += 1;
        (*arr)->freeSpace -= 1;
    }
    return (1);
}

void        printDArr(t_dynamicArr *arr)
{
    int i;

    i = 0;
    while (i != arr->len)
        printf("%d ", arr->array[i++]);
    printf("\n");
}