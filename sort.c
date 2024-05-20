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
        quicksort(col, 0, col->size - 1);
    }
    else if (col->valid_index == -1)
    {
        insertion_sort(col);
    }
    col->sort_dir = sort_dir;
}

/*
 * @brief: Sort a column using the quicksort algorithm
 * @param1: Pointer to the column to sort
 * @param2: Left index of the column
 * @param3: Right index of the column
 */
void quicksort(COLUMN* col, int left, int right)
{
    if (left < right)
    {
        int pi = partition(col, left, right);
        quicksort(col, left, pi - 1);
        quicksort(col, pi + 1, right);
    }
}

/*
 * @brief: Partition the column
 * @param1: Pointer to the column to partition
 * @param2: Left index of the column
 * @param3: Right index of the column
 * @return: The pivot index
 */
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

/*
 * @brief: Sort a column using the insertion sort algorithm
 * @param1: Pointer to the column to sort
 */
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

/*
 * @brief: Sort a CDataframe according to a given column
 * @param1: Pointer to the CDataframe to sort
 * @param2: Index of the column to sort
 * @param3: Sort type (ASC or DESC)
*/
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

/**
 * @brief: Display the content of a sorted column
 * @param1: Pointer to a column
 */
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
