//
// Created by positivedespair on 7/25/20.
//

#include "libft.h"

static int     ft_partition (int *arr, int low, int high)
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

void            ft_quicksort(int *arr, int low, int high)
{
    int pi;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        pi = ft_partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        ft_quicksort(arr, low, pi - 1);
        ft_quicksort(arr, pi + 1, high);
    }
}
