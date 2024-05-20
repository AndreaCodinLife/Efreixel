#include "column.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"
#include "list.h"
#include "cdataframe.h"


void sort(COLUMN* col, int sort_dir)
{
    if (col->valid_index == 0)
    {
        if (sort_dir == ASC)
        {
            quicksort(col, 0, col->size - 1);
        }
        else if (sort_dir == DESC)
        {
            // Reverse the array before sorting in descending order
            reverse_array(col->data, col->size);
            quicksort(col, 0, col->size - 1);
            // Reverse the array again to restore the original order
            reverse_array(col->data, col->size);
        }
    }
    else if (col->valid_index == -1)
    {
        if (sort_dir == ASC)
        {
            insertion_sort(col);
        }
        else if (sort_dir == DESC)
        {
            // Reverse the array before sorting in descending order
            reverse_array(col->data, col->size);
            insertion_sort(col);
            // Reverse the array again to restore the original order
            reverse_array(col->data, col->size);
        }
    }
    col->sort_dir = sort_dir;
}

void reverse_array(void** data, int size)
{
    void* temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = data[i];
        data[i] = data[size - i - 1];
        data[size - i - 1] = temp;
    }
}

void quicksort(COLUMN* col, int left, int right)
{
    if (left < right)
    {
        int pi = partition(col, left, right);
        quicksort(col, left, pi - 1);
        quicksort(col, pi + 1, right);
    }
}


int partition(COLUMN* col, int left, int right)
{
    void* pivot = col->data[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (col->column_type == INT)
        {
            if (*(int*)col->data[j] <= *(int*)pivot)
            {
                i++;
                void* temp = col->data[i];
                col->data[i] = col->data[j];
                col->data[j] = temp;
            }
        }
        else if (col->column_type == UINT)
        {
            if (*(unsigned int*)col->data[j] <= *(unsigned int*)pivot)
            {
                i++;
                void* temp = col->data[i];
                col->data[i] = col->data[j];
                col->data[j] = temp;
            }
        }
        else if (col->column_type == CHAR)
        {
            if (*(char*)col->data[j] <= *(char*)pivot)
            {
                i++;
                void* temp = col->data[i];
                col->data[i] = col->data[j];
                col->data[j] = temp;
            }
        }
        else if (col->column_type == FLOAT)
        {
            if (*(float*)col->data[j] <= *(float*)pivot)
            {
                i++;
                void* temp = col->data[i];
                col->data[i] = col->data[j];
                col->data[j] = temp;
            }
        }
        else if (col->column_type == DOUBLE)
        {
            if (*(double*)col->data[j] <= *(double*)pivot)
            {
                i++;
                void* temp = col->data[i];
                col->data[i] = col->data[j];
                col->data[j] = temp;
            }
        }
        else if (col->column_type == STRING)
        {
            if (strcmp((char*)col->data[j], (char*)pivot) <= 0)
            {
                i++;
                void* temp = col->data[i];
                col->data[i] = col->data[j];
                col->data[j] = temp;
            }
        }
    }
    void* temp = col->data[i + 1];
    col->data[i + 1] = col->data[right];
    col->data[right] = temp;
    return i + 1;
}

void insertion_sort(COLUMN* col)
{
    for (int i = 1; i < col->size; i++)
    {
        void* key = col->data[i];
        int j = i - 1;
        if (col->column_type == INT)
        {
            while (j >= 0 && *(int*)col->data[j] > *(int*)key)
            {
                col->data[j + 1] = col->data[j];
                j--;
            }
        }
        else if (col->column_type == UINT)
        {
            while (j >= 0 && *(unsigned int*)col->data[j] > *(unsigned int*)key)
            {
                col->data[j + 1] = col->data[j];
                j--;
            }
        }
        else if (col->column_type == CHAR)
        {
            while (j >= 0 && *(char*)col->data[j] > *(char*)key)
            {
                col->data[j + 1] = col->data[j];
                j--;
            }
        }
        else if (col->column_type == FLOAT)
        {
            while (j >= 0 && *(float*)col->data[j] > *(float*)key)
            {
                col->data[j + 1] = col->data[j];
                j--;
            }
        }
        else if (col->column_type == DOUBLE)
        {
            while (j >= 0 && *(double*)col->data[j] > *(double*)key)
            {
                col->data[j + 1] = col->data[j];
                j--;
            }
        }
        else if (col->column_type == STRING)
        {
            while (j >= 0 && strcmp((char*)col->data[j], (char*)key) > 0)
            {
                col->data[j + 1] = col->data[j];
                j--;
            }
        }
        col->data[j + 1] = key;
    }
}


void sort_cdataframe(CDATAFRAME* cdf, int col_index, char* sort_dir)
{
    // you can use get_cols_by_index(cdf, col_index); 
    //columns[col_index]; DOES NOT EXIST
    COLUMN* col = get_column_by_index(cdf, col_index);
    if (strcmp(sort_dir, "ASC") == 0)
    {
        sort(col, ASC);
        print_col_by_index(col);
    }
    else if (strcmp(sort_dir, "DESC") == 0)
    {
        sort(col, DESC);
        print_col_by_index(col);
    }
    
}


void print_col_by_index(COLUMN *col)
{
    for (int i = 0; i < col->size; i++)
    {
        if (col->column_type == INT)
        {
            printf("%d\n", *(int*)col->data[i]);
        }
        else if (col->column_type == UINT)
        {
            printf("%u\n", *(unsigned int*)col->data[i]);
        }
        else if (col->column_type == CHAR)
        {
            printf("%c\n", *(char*)col->data[i]);
        }
        else if (col->column_type == FLOAT)
        {
            printf("%f\n", *(float*)col->data[i]);
        }
        else if (col->column_type == DOUBLE)
        {
            printf("%lf\n", *(double*)col->data[i]);
        }
        else if (col->column_type == STRING)
        {
            printf("%s\n", (char*)col->data[i]);
        }
    }
}

void update_index(COLUMN *col)
{
    sort(col, col->sort_dir);
}