#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


COLUMN *create_column(ENUM_TYPE type, char *title)
{
    COLUMN *column = (COLUMN *)malloc(sizeof(COLUMN));
    if (column == NULL)
    {
        return NULL;
    }
    column->column_type = type;
    column->title = (char *)malloc(strlen(title) + 1);
    strcpy(column->title, title);
    column->data = NULL;
    column->size = 0;
    column->max_size = 0;
    column->index = NULL;
    column->valid_index = 0;
    column->sort_dir = 0;
    return column;
}

int insert_value(COLUMN *col, void *value)
{
    // fflush(stdout);
    if (col->size == col->max_size)
    {
        col->data = realloc(col->data, (col->max_size + 1) * sizeof(void *));
        if (col->data == NULL)
        {
            return -1;
        }
        col->max_size++;
    }

    switch (col->column_type)
    {
    case UINT:
        col->data[col->size] = (void *)malloc(sizeof(unsigned int));
        // assign value to the address of the data
        col->data[col->size] = value;
        break;
    case INT:
        col->data[col->size] = (void *)malloc(sizeof(int));
        // assign value to the address of the data
        col->data[col->size] = value;
        break;
    case CHAR:
        col->data[col->size] = (void *)malloc(sizeof(char));
        col->data[col->size] = value;
        break;
    case FLOAT:
        col->data[col->size] = (void *)malloc(sizeof(float));
        col->data[col->size] = value;
        break;
    case DOUBLE:
        col->data[col->size] = (void *)malloc(sizeof(double));
        col->data[col->size] = value;
        break;
    case STRING:
        col->data[col->size] = (void *)malloc(strlen((char *)value) + 1);
        strcpy((char *)col->data[col->size], (char *)value);
        break;
    case STRUCTURE:
        col->data[col->size] = (void *)malloc(sizeof(void *));
        col->data[col->size] = value;
        break;
    default:
        col->data[col->size] = (void *)malloc(sizeof(void *));
        col->data[col->size] = value;
        break;
    }
    col->size++;
    return 0;
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size)
{
    switch (col->column_type)
    {
    case UINT:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%u", *((unsigned int *)col->data[i]));
        break;
    case INT:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%d", *((int *)col->data[i]));
        break;
    case CHAR:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%c", *((char *)col->data[i]));
        break;
    case FLOAT:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%f", *((float *)col->data[i]));
        break;
    case DOUBLE:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%lf", *((double *)col->data[i]));
        break;
    case STRING:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%s", (char *)col->data[i]);
        break;
    case STRUCTURE:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%p", col->data[i]);
        break;
    default:
        if (col->data[i] == NULL)
            snprintf(str, size, "%s", "NULL");
        else
            snprintf(str, size, "%p", col->data[i]);
        break;
    }
}

void delete_column_h(COLUMN **col)
{
    free((*col)->title);
    free(&((*col)->size));
    free(&((*col)->max_size));
    free(&((*col)->column_type));
    free(&((*col)->data));
    free(col);
}

void print_col(COLUMN *col)
{
    char str[100];
    for (unsigned long long int i = 0; i < col->size; i++)
    {
        convert_value(col, i, str, 100);
        printf("[%llu] %s\n", i, str);
    }
}

int count_occurrences(COLUMN *col, void *value)
{
    int count = 0;
    for (unsigned long long int i = 0; i < col->size; i++)
    {
        if (col->column_type == UINT && *((unsigned int *)col->data[i]) == *((unsigned int *)value))
        {
            count++;
        }
        else if (col->column_type == INT && *((int *)col->data[i]) == *((int *)value))
        {
            count++;
        }
        else if (col->column_type == CHAR && *((char *)col->data[i]) == *((char *)value))
        {
            count++;
        }
        else if (col->column_type == FLOAT && *((float *)col->data[i]) == *((float *)value))
        {
            count++;
        }
        else if (col->column_type == DOUBLE && *((double *)col->data[i]) == *((double *)value))
        {
            count++;
        }
        else if (col->column_type == STRING && strcmp((char *)col->data[i], (char *)value) == 0)
        {
            count++;
        }
        else if (col->column_type == STRUCTURE && col->data[i] == value)
        {
            count++;
        }
        else 
        {
            count++;
        }
    }
    return count;
}

void *get_value(COLUMN *col, unsigned long long int i)
{
    return col->data[i];
}

int count_greater(COLUMN *col, void *value)
{
    int count = 0;
    for (unsigned long long int i = 0; i < col->size; i++)
    {
        if (col->column_type == UINT && *((unsigned int *)col->data[i]) > *((unsigned int *)value))
        {
            count++;
        }
        else if (col->column_type == INT && *((int *)col->data[i]) > *((int *)value))
        {
            count++;
        }
        else if (col->column_type == CHAR && *((char *)col->data[i]) > *((char *)value))
        {
            count++;
        }
        else if (col->column_type == FLOAT && *((float *)col->data[i]) > *((float *)value))
        {
            count++;
        }
        else if (col->column_type == DOUBLE && *((double *)col->data[i]) > *((double *)value))
        {
            count++;
        }
    }
    return count;
}

int count_less(COLUMN *col, void *value)
{
    int count = 0;
    for (unsigned long long int i = 0; i < col->size; i++)
    {
        if (col->column_type == UINT && *((unsigned int *)col->data[i]) < *((unsigned int *)value))
        {
            count++;
        }
        else if (col->column_type == INT && *((int *)col->data[i]) < *((int *)value))
        {
            count++;
        }
        else if (col->column_type == CHAR && *((char *)col->data[i]) < *((char *)value))
        {
            count++;
        }
        else if (col->column_type == FLOAT && *((float *)col->data[i]) < *((float *)value))
        {
            count++;
        }
        else if (col->column_type == DOUBLE && *((double *)col->data[i]) < *((double *)value))
        {
            count++;
        }
    }
    return count;
}

int count_equal(COLUMN *col, void *value)
{
    int count = 0;
    for (unsigned long long int i = 0; i < col->size; i++)
    {
        if (col->column_type == UINT && *((unsigned int *)col->data[i]) == *((unsigned int *)value))
        {
            count++;
        }
        else if (col->column_type == INT && *((int *)col->data[i]) == *((int *)value))
        {
            count++;
        }
        else if (col->column_type == CHAR && *((char *)col->data[i]) == *((char *)value))
        {
            count++;
        }
        else if (col->column_type == FLOAT && *((float *)col->data[i]) == *((float *)value))
        {
            count++;
        }
        else if (col->column_type == DOUBLE && *((double *)col->data[i]) == *((double *)value))
        {
            count++;
        }
        else if (col->column_type == STRING && strcmp((char *)col->data[i], (char *)value) == 0)
        {
            count++;
        }
        else if (col->column_type == STRUCTURE && col->data[i] == value)
        {
            count++;
        }
        else
        {
            count++;
        }
    }
    return count;
}