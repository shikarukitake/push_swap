//
// Created by shika on 10.02.2020.
//

//#include "../libft/includes/libft.h"

#include <unistd.h>

void ft_swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
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

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

int main(int argc, char **argv)
{
    int *hello;

    hello = malloc(sizeof(int) * 10);

    int j = 10;
    for (int i = 0; i < 10; i++)
    {
        hello[i] = j;
        j--;
    }
    quickSort(hello, 0, 9);
    printArray(hello, 10);
}
