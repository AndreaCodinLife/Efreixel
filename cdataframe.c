#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size, char** col_names)
{
    CDATAFRAME *cdf = (CDATAFRAME *)safe_malloc(sizeof(CDATAFRAME));
    if (cdf == NULL)
    {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        return NULL;
    }
    cdf->head = NULL;
    cdf->tail = NULL;
    for (int i = 0; i < size; i++)
    {
        // ask the user for the name of the column if col_names is not provided
        char col_name[100];
        if (col_names != NULL)
        {
            strcpy(col_name, col_names[i]);
        }
        else
        {
            printf("Enter the name of the column %d: ", i + 1);
            scanf("%s ", col_name);
        }
        printf("Enter the name of the columns\n");
        COLUMN *col = create_column(cdftype[i], col_name);
        printf("Enter the name of the columns\n");
        if (col == NULL)
        {
            // Handle memory allocation failure
            printf("Memory allocation failed\n");
            return NULL;
        }
        LNODE *lnode = (LNODE *)safe_malloc(sizeof(LNODE));
        if (lnode == NULL)
        {
            // Handle memory allocation failure
            printf("Memory allocation failed\n");
            return NULL;
        }
        lnode->data = col;
        lnode->prev = NULL;
        lnode->next = NULL;
        if (cdf->head == NULL)
        {
            cdf->head = lnode;
            cdf->tail = lnode;
        }
        else
        {
            cdf->tail->next = lnode;
            lnode->prev = cdf->tail;
            cdf->tail = lnode;
        }
    }
    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf)
{
    LNODE *current = (*cdf)->head;
    while (current != NULL)
    {
        LNODE *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(*cdf);
    *cdf = NULL;
}

void delete_column(CDATAFRAME *cdf, char *col_name)
{
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        if (strcmp(((COLUMN *)current->data)->title, col_name) == 0)
        {
            free(current->data);
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                cdf->head = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            else
            {
                cdf->tail = current->prev;
            }
            free(current);
            break;
        }
        current = current->next;
    }
}

int get_cdataframe_cols_size(CDATAFRAME *cdf)
{
    int count = 0;
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void fill_cdataframe(CDATAFRAME* cdf) {
    if (!(cdf == NULL || cdf->head == NULL)) {
        LNODE* node = cdf->head;
        int size;
        do {
            printf("How many values do you want to store in this column ?\nnb values: ");
            scanf("%d", &size);
        } while (size < 1);
        while (node != NULL) {// cdf->tail
            COLUMN* column = node->data;
            for (int i = 0; i < size; i++) {       
                void* value = (void*) safe_malloc(sizeof(column->column_type));
                
                switch (column->column_type)
                    {
                    case UINT:
                        *(unsigned int *)value = rand() % 100;
                        break;
                    case INT:
                        *(int *)value = rand() % 10000000;
                        break;
                    case CHAR:
                        *(char *)value = 'a' + rand() % 26;
                        break;
                    case FLOAT:
                        *(float *)value = (float)(rand() % 100) / 10;
                        break;
                    case DOUBLE:
                        *(double *)value = (double)(rand() % 100) / 10;
                        break;
                    case STRING:
                        break;
                    case STRUCTURE:
                        break;
                    default:
                        value = NULL;
                        break;
                    }
                insert_value(node->data, value);
            }
            node = node->next;
        }
    }

}

void fill_cdataframe_with_inputs(CDATAFRAME* cdf) {
    if (!(cdf == NULL || cdf->head == NULL)) {
        LNODE* node = cdf->head;
        int size;
        while (node != NULL)
        { // cdf->tail

            printf("How many values do you want to store in this column ?\nnb values: ");
            scanf("%d", &size);
            COLUMN *column = node->data;
            for (int i = 0; i < size; i++)
            {
                void *value = (void *)safe_malloc(sizeof(column->column_type));

                switch (column->column_type)
                {
                case UINT:
                    printf("Enter a number:");
                    scanf("%u", (unsigned int *)value);
                    break;
                case INT:
                    printf("Enter a number:");
                    scanf("%d", (int *)value);
                    break;
                case CHAR:
                    printf("Enter a character:");
                    scanf(" %c", (char *)value);
                    break;
                case FLOAT:
                    printf("Enter a floating number:");
                    scanf("%f", (float *)value);
                    break;
                case DOUBLE:
                    printf("Enter a floating number:");
                    scanf("%lf", (double *)value);
                    break;
                case STRING:
                    printf("Enter a word:");
                    scanf("%s", (char *)value);
                    break;
                case STRUCTURE:
                    break;
                default:
                    value = NULL;
                    break;
                }
                insert_value(node->data, value);
            }
            node = node->next;
        }
    }
}

void display_cdataframe(CDATAFRAME *cdf)
{
    LNODE *node = cdf->head;
    while (node != NULL)
    {
        print_col(node->data);
        node = node->next;
        printf("\n");
    }
    printf("-----------\n");
}

void display_cdataframe_like_excel(CDATAFRAME *cdf)
{

    LNODE *node = cdf->head;
    int nb_rows = 0;
    int nb_cols = get_cdataframe_cols_size(cdf);
    // array of longest values in each column
    int *longest_values = (int *)safe_malloc(nb_cols * sizeof(int));
    // get the number of rows and the number of columns
    while (node != NULL)
    {
        COLUMN *col = node->data;
        if (col->size > nb_rows)
        {
            nb_rows = col->size;
        }
        node = node->next;
    }
    // create the matrix
    char ***matrix = (char ***)safe_malloc(nb_rows * sizeof(char **));
    for (int i = 0; i < nb_rows; i++)
    {
        matrix[i] = (char **)safe_malloc(nb_cols * sizeof(char *));
        for (int j = 0; j < nb_cols; j++)
        {
            matrix[i][j] = (char *)safe_malloc(100 * sizeof(char));
            strcpy(matrix[i][j], "");
        }
    }
    node = cdf->head;
    int i = 0;
    // fill the matrix with the values of the cdataframe
    while (node != NULL)
    {
        COLUMN *col = node->data;
        for (int j = 0; j < col->size; j++)
        {
            switch (col->column_type)
            {
            case UINT:
                sprintf(matrix[j][i], "%u", *(unsigned int *)col->data[j]);
                break;
            case INT:
                sprintf(matrix[j][i], "%d", *(int *)col->data[j]);
                break;
            case CHAR:
                sprintf(matrix[j][i], "%c", *(char *)col->data[j]);
                break;
            case FLOAT:
                sprintf(matrix[j][i], "%f", *(float *)col->data[j]);
                break;
            case DOUBLE:
                sprintf(matrix[j][i], "%lf", *(double *)col->data[j]);
                break;
            case STRING:
                strcpy(matrix[j][i], (char *)col->data[j]);
                break;
            case STRUCTURE:
                break;
            default:
                strcpy(matrix[j][i], "");
                break;
            }
        }
        i++;
        node = node->next;
    }
    // get the max length of the values in each column of the matrix
    for (int i = 0; i < nb_rows; i++)
    {
        for (int j = 0; j < nb_cols; j++)
        {
            int len = sizeof(matrix[i][j]);
            if (len > longest_values[j])
            {
                longest_values[j] = len;
            }
        }
    }
    // print the top line of the matrix with the column names
    LNODE *nodec = cdf->head;
    int j = 0;
    while (nodec != NULL)
    {
        int len = strlen(((COLUMN *)nodec->data)->title);
        int diff = longest_values[j] - len;
        //if column name is longer than the value in the column then change the longest value to the length of the column name
        if (diff < 0)
        {
            longest_values[j] = len;
        }
        int left = diff / 2;
        int right = diff - left;
        printf("|");
        for (int k = 0; k < left; k++)
        {
            printf(" ");
        }
        printf("%s", ((COLUMN *)nodec->data)->title);
        nodec = nodec->next;
        for (int k = 0; k < right; k++)
        {
            printf(" ");
        }
        j++;
    }
    printf("|\n");
    //add a line ----------------
    for (int j = 0; j < nb_cols; j++)
    {
        for (int k = 0; k < longest_values[j]; k++)
        {
            printf("-");
        }
    }
    printf("\n");

    // print the matrix
    for (int i = 0; i < nb_rows; i++)
    {
        for (int j = 0; j < nb_cols; j++)
        {
            int len = strlen(matrix[i][j]);
            int diff = longest_values[j] - len;
            int left = diff / 2;
            int right = diff - left;
            printf("|");
            for (int k = 0; k < left; k++)
            {
                printf(" ");
            }
            printf("%s", matrix[i][j]);
            for (int k = 0; k < right; k++)
            {
                printf(" ");
            }
        }
        printf("|\n");
    }

    // free the matrix
    for (int i = 0; i < nb_rows; i++)
    {
        for (int j = 0; j < nb_cols; j++)
        {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

void display_cdataframe_with_rows_limit(CDATAFRAME *cdf, int nb_rows)
{
    LNODE *node = cdf->head;
    for (int i = 0; i < nb_rows && node != NULL; i++)
    {
        print_col(node->data);
        node = node->next;
        printf("\n");
    }
}

void display_cdataframe_with_col_limit(CDATAFRAME *cdf, int nb_col)
{
    LNODE *node = cdf->head;
    while (node != NULL)
    {
        COLUMN *col = node->data;
        int size = col->size;
        col->size = nb_col;
        print_col(col);
        col->size = size;
        node = node->next;
        printf("\n");
    }
}

void add_row(CDATAFRAME* cdf) {
    LNODE* node = cdf->head;
    while (node != NULL) {
        COLUMN* column = node->data;
        void* value = (void*) safe_malloc(sizeof(column->column_type));
        switch (column->column_type)
            {
            case UINT:
                printf("Enter a number:");
                scanf("%u", (unsigned int*)value);
                break;
            case INT:
                printf("Enter a number:");
                scanf("%d", (int*)value);
                break;
            case CHAR:
                printf("Enter a character:");
                scanf(" %c", (char*)value);
                break;
            case FLOAT:
                printf("Enter a floating number:");
                scanf("%f", (float*)value);
                break;
            case DOUBLE:
                printf("Enter a floating number:");
                scanf("%lf", (double*)value);
                break;
            case STRING:
                printf("Enter a word:");
                scanf("%s", (char*)value);
                break;
            case STRUCTURE:
                break;
            default:
                value = NULL;
                break;
        }
        insert_value(node->data, value);
        free(value);
        node = node->next;
    }
}

void delete_row(CDATAFRAME* cdf, int index) {
    LNODE* node = cdf->head;
    while (node != NULL) {
        COLUMN* col = node->data;
        int i;
        if (0 <= index < col->size)
        {
            for (i = index; i < col->size - 1; i++)
            {
                col->data[i] = col->data[i + 1];
            }
            col->data[i] = NULL;
            col->size--;
        }
        node = node->next;
    }
}

LNODE *create_col(CDATAFRAME *cdf, char *title, ENUM_TYPE type, int index)
{   
    printf("Memory start\n");
    LNODE *node = cdf->head;
    int pos = 0;
    while (pos < index && node != NULL)
    {
        node = node->next;
        pos++;
    }
    COLUMN *col = create_column(type, title);
    LNODE *P = (LNODE *)safe_malloc(sizeof(LNODE));
    if (P == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    } else {
        printf("Memory allocation success\n");
        }
    P->data = col;
    P->next = node->next;
    node->next = P;
    return P;
}

void rename_col(CDATAFRAME *cdf, int index, char *newName)
{
    LNODE *node = cdf->head;
    int pos = 0;
    while (pos < index && node != NULL)
    {
        node = node->next;
    }
    if (node != NULL)
    {
        COLUMN *col = node->data;
        col->title = newName;
        display_column_names(cdf);
    }
}

bool is_in_cdataframe(CDATAFRAME *cdf, void *value, ENUM_TYPE type)
{
    LNODE *node = cdf->head;
    while (node != NULL)
    {
        COLUMN *col = node->data;
        if (col->column_type == type)
        {
            for (int i = 0; i < col->size; i++)
            {
                if (*(int *)col->data[i] == *(int *)value)
                {
                    return true;
                    break;
                }
            }
        }
        node = node->next;
    }
    return false;
}

void replace_value(CDATAFRAME *cdf, int rowNb, int colNb, void *value)
{
    LNODE *node = cdf->head;
    int pos = 0;
    while (pos < rowNb && node != NULL)
    {
        pos++;
        node = node->next;
    }
    if (node != NULL)
    {
        COLUMN *col = node->data;
        if (colNb < col->size)
        {
            col->data[colNb] = value;
        }
    }
}

void display_column_names(CDATAFRAME *cdf){
    LNODE *node = cdf->head;
    while (node != NULL)
    {
        printf("|%s", ((COLUMN *)node->data)->title);
        node = node->next;
    }
    printf("\n");
}

void display_number_rows(CDATAFRAME* cdf) {
    LNODE* node = cdf->head;
    COLUMN* column = node->data;
    int count = column->size;
    printf("There are %d rows in this CDataframe\n", count);
}

void display_number_col(CDATAFRAME* cdf) {
    LNODE* node = cdf->head;
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    printf("There are %d columns in this CDataframe\n", count);
}

void display_number_cells_equal(CDATAFRAME* cdf, void* x, ENUM_TYPE type) {
    LNODE* node = cdf->head;
    int count = 0;
    while(node != NULL) {
        COLUMN* column = node->data;
        if (column->column_type == type) {
            for(int i = 0; i < column->size; i++) {
                int* pt = &(column->data[i]->int_value);
                if (*pt == *(int*)x) {
                    count++;
                }
            }
        }
        node = node->next;
    }
    printf("There are %d cells equal to the value given\n", count);
}

void display_number_cells_smaller(CDATAFRAME* cdf, void* x, ENUM_TYPE type) {
    LNODE* node = cdf->head;
    int count = 0;
    while(node != NULL) {
        COLUMN* column = node->data;
        if (column->column_type == type) {
            for(int i = 0; i < column->size; i++) {
                int* pt = &(column->data[i]->int_value);
                if (*pt < *(int*)x) {
                    count++;
                }
            }
        }
        node = node->next;
    }
    printf("There are %d cells smaller than the value given\n", count);
}

void display_number_cells_greater(CDATAFRAME* cdf, void* x, ENUM_TYPE type) {
    LNODE* node = cdf->head;
    int count = 0;
    while(node != NULL) {
        COLUMN* column = node->data;
        if (column->column_type == type) {
            for(int i = 0; i < column->size; i++) {
                int* pt = &(column->data[i]->int_value);
                if (*pt > *(int*)x) {
                    count++;
                }
            }
        }
        node = node->next;
    }
    printf("There are %d cells greater than the value given\n", count);
}

CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size) {
    // Open the CSV file
    // Create the array of column names
    char *col_names[size];
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return NULL;
    }
    //get the first line of the file to get the column names
    char line1[1024];
    fgets(line1, 1024, file);
    char *token1 = strtok(line1, ",");
    int i = 0;
    while (token1 != NULL) {
        col_names[i] = (char *)safe_malloc(strlen(token1) * sizeof(char));
        strcpy(col_names[i], token1);
        token1 = strtok(NULL, ",");
        i++;
    }
    // Create a new CDATAFRAME
    CDATAFRAME *cdf = create_cdataframe(dftype, size, col_names);
    if (cdf == NULL) {
        return NULL;
    }
    // Read each line from the CSV file and add it to the CDATAFRAME with the values in the appropriate column
    char line[1024];
    while (fgets(line, 1024, file)) {
        char *token = strtok(line, ",");
        int i = 0;
        LNODE *node = cdf->head;
        while (token != NULL && node != NULL) {
            COLUMN *col = node->data;
            void *value = (void *)safe_malloc(sizeof(col->column_type));
            switch (col->column_type) {
                case UINT:
                    sscanf(token, "%u", (unsigned int *)value);
                    break;
                case INT:
                    sscanf(token, "%d", (int *)value);
                    break;
                case CHAR:
                    sscanf(token, "%c", (char *)value);
                    break;
                case FLOAT:
                    sscanf(token, "%f", (float *)value);
                    break;
                case DOUBLE:
                    sscanf(token, "%lf", (double *)value);
                    break;
                case STRING:
                    strcpy((char *)value, token);
                    break;
                case STRUCTURE:
                    break;
                default:
                    value = NULL;
                    break;
            }
            insert_value(col, value);
            token = strtok(NULL, ",");
            node = node->next;
            i++;
        }
    }
    fclose(file);
    return cdf;
}

void save_into_csv(CDATAFRAME *cdf, char *file_name) {
    // Open the CSV file
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        return;
    }
    // Write the column names to the CSV file
    LNODE *node = cdf->head;
    while (node != NULL) {
        COLUMN *col = node->data;
        fprintf(file, "%s,", col->title);
        node = node->next;
    }
    fprintf(file, "\n");
    // Write the values to the CSV file
    int nb_rows = 0;
    node = cdf->head;
    while (node != NULL) {
        COLUMN *col = node->data;
        if (col->size > nb_rows) {
            nb_rows = col->size;
        }
        node = node->next;
    }
    for (int i = 0; i < nb_rows; i++) {
        node = cdf->head;
        while (node != NULL) {
            COLUMN *col = node->data;
            if (i < col->size) {
                switch (col->column_type) {
                    case UINT:
                        fprintf(file, "%u,", *(unsigned int *)col->data[i]);
                        break;
                    case INT:
                        fprintf(file, "%d,", *(int *)col->data[i]);
                        break;
                    case CHAR:
                        fprintf(file, "%c,", *(char *)col->data[i]);
                        break;
                    case FLOAT:
                        fprintf(file, "%f,", *(float *)col->data[i]);
                        break;
                    case DOUBLE:
                        fprintf(file, "%lf,", *(double *)col->data[i]);
                        break;
                    case STRING:
                        fprintf(file, "%s,", (char *)col->data[i]);
                        break;
                    case STRUCTURE:
                        break;
                    default:
                        break;
                }
            } else {
                fprintf(file, ",");
            }
            node = node->next;
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

COLUMN* get_column_by_index(CDATAFRAME* cdf, int index) {
    LNODE* node = cdf->head;
    int i = 0;
    while (node != NULL && i < index) {
        node = node->next;
        i++;
    }
    if (node != NULL) {
        return node->data;
    }
    return NULL;
}