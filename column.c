#include "column.h"
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
    column->title = title;
    column->data = NULL;
    column->size = 0;
    column->max_size = 0;
    return column;
}

int insert_value(COLUMN *col, void *value)
{
    //fflush(stdout);
    if (col->size == col->max_size)
    {
        col->data = (void **)realloc(col->data, (col->max_size + 1) * sizeof(void *));
        if (col->data == NULL)
        {
            return -1;
        }
        col->max_size++;
    }

    switch (col->column_type)
    {
    case INT:
        col->data[col->size] = (int *)malloc(sizeof(int));
        //assign value to the address of the data
        col->data[col->size] = value;
        break;
    case CHAR:
        col->data[col->size] = (char *)malloc(sizeof(char));
        col->data[col->size] = value;
        break;
    case FLOAT:
        col->data[col->size] = (float *)malloc(sizeof(float));
        col->data[col->size] = value;
        break;
    case DOUBLE:
        col->data[col->size] = (double *)malloc(sizeof(double));
        col->data[col->size] = value;
        break;
    case STRING:
        col->data[col->size] = (char *)malloc(strlen((char *)value) + 1);
        strcpy((char *)col->data[col->size], (char *)value);
        break;
    default:
        break;
    }
    col->size++;
    return 0;
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size)
{
    switch (col->column_type)
    {
    case INT:
        snprintf(str, size, "%d", *((int *)col->data[i]));
        break;
    case CHAR:
        snprintf(str, size, "%c", *((char *)col->data[i]));
        break;
    case FLOAT:
        snprintf(str, size, "%f", *((float *)col->data[i]));
        break;
    case DOUBLE:
        snprintf(str, size, "%lf", *((double *)col->data[i]));
        break;
    case STRING:
        snprintf(str, size, "%s", (char *)col->data[i]);
        break;
    default:
        break;
    }
}

void delete_column(COLUMN **col)
{
    free((*col)->title);
    free(&((*col)->size));
    free(&((*col)->max_size));
    free(&((*col)->column_type));
    free(&((*col)->data));
    free(col);
}

void display_col(COLUMN *col)
{
    printf("----------\nName : %s\nSize : %d\nMax size : %d\n----------\n", col->title, col->size, col->max_size);
}

/*l'expression doit avoir un type pointeur vers struct ou union mais elle a le type "COLUMN **" (aka "struct column **")
  l'expression doit avoir un type pointeur vers struct ou union mais elle a le type "COLUMN **" (aka "struct column **")
  l'expression doit avoir un type pointeur vers struct ou union mais elle a le type "COLUMN **" (aka "struct column **")
  */