#include "column.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"
#include "list.h"
#include "cdataframe.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int compare(void *a, void *b)
{
    if (a == NULL && b == NULL)
    {
        return 0;
    }
    if (a == NULL)
    {
        return -1;
    }
    if (b == NULL)
    {
        return 1;
    }
    return strcmp(a, b);
}

void insertion_sort(int *index, void **data, int size, int sort_dir)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && (sort_dir == ASC ? compare(data[index[j - 1]], data[index[j]]) > 0 : compare(data[index[j - 1]], data[index[j]]) < 0))
        {
            swap(&index[j], &index[j - 1]);
            j--;
        }
    }
}

void sort(COLUMN *col, int sort_dir)
{
    if (col->valid_index == 0)
    {
        quick_sort(col->index, col->data, 0, col->size - 1, sort_dir);
    }
    else if (col->valid_index == -1)
    {
        insertion_sort(col->index, col->data, col->size, sort_dir);
    }
    col->valid_index = 1;
    col->sort_dir = sort_dir;
}

void quick_sort(int *index, void **data, int low, int high, int sort_dir)
{
    if (low < high)
    {
        int pi = partition(index, data, low, high, sort_dir);
        quick_sort(index, data, low, pi - 1, sort_dir);
        quick_sort(index, data, pi + 1, high, sort_dir);
    }
}

int partition(int *index, void **data, int low, int high, int sort_dir)
{
    void *pivot = data[index[high]];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (sort_dir == ASC)
        {
            if (compare(data[index[j]], pivot) <= 0)
            {
                i++;
                swap(&index[i], &index[j]);
            }
        }
        else
        {
            if (compare(data[index[j]], pivot) >= 0)
            {
                i++;
                swap(&index[i], &index[j]);
            }
        }
    }
    swap(&index[i + 1], &index[high]);
    return i + 1;
}

void print_col_by_index(COLUMN *col)
{
    for (int i = 0; i < col->size; i++)
    {
        char str[100];
        convert_value(col, i, str, 100);
        printf("%s\n", str);
    }
}

sort_cdataframe(CDATAFRAME *cdf, int col, char *order)
{
}