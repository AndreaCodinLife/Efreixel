#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    ENUM_TYPE cdftype[] = {INT, CHAR, INT};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 3);
    return 0;
}

typedef enum
{
    INT,
    CHAR,
    FLOAT,
    DOUBLE
} ENUM_TYPE;

typedef struct lnode_
{
    void *data; // Pointer to a column
    struct lnode_ *prev;
    struct lnode_ *next;
} LNODE;

typedef struct list_
{
    LNODE *head;
    LNODE *tail;
} LIST;

typedef LIST CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size)
{
    CDATAFRAME *cdf = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    if (cdf == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    cdf->head = NULL;
    cdf->tail = NULL;
    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf)
{
    LNODE *current = (*cdf)->head;
    while (current != NULL)
    {
        LNODE *next = current->next;
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
        // Check if the column name matches
        // If it does, delete the column
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

void display_cdataframe(CDATAFRAME *cdf)
{
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Display the column data
        current = current->next;
    }
}

void add_row(CDATAFRAME *cdf, void **values)
{
    LNODE *current = cdf->head;
    int i = 0;
    while (current != NULL)
    {
        // Add the value to the column
        current = current->next;
        i++;
    }
}

void delete_row(CDATAFRAME *cdf, int row_index)
{
    LNODE *current = cdf->head;
    int i = 0;
    while (current != NULL)
    {
        // Delete the value from the column
        current = current->next;
        i++;
    }
}

void add_column(CDATAFRAME *cdf, ENUM_TYPE cdftype, char *col_name)
{
    LNODE *new_node = (LNODE *)malloc(sizeof(LNODE));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = NULL; // Initialize the column data
    new_node->prev = cdf->tail;
    new_node->next = NULL;
    if (cdf->tail != NULL)
    {
        cdf->tail->next = new_node;
    }
    cdf->tail = new_node;
    if (cdf->head == NULL)
    {
        cdf->head = new_node;
    }
}

void delete_column(CDATAFRAME *cdf, char *col_name)
{
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Check if the column name matches
        // If it does, delete the column
        current = current->next;
    }
}

void rename_column(CDATAFRAME *cdf, char *old_name, char *new_name)
{
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Check if the column name matches
        // If it does, rename the column
        current = current->next;
    }
}

bool search_value(CDATAFRAME *cdf, void *value)
{
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Search for the value in the column
        current = current->next;
    }
    return false;
}

void access_replace_value(CDATAFRAME *cdf, int row_index, int col_index, void *value)
{
    LNODE *current = cdf->head;
    int i = 0;
    while (current != NULL)
    {
        // Access/replace the value in the cell
        current = current->next;
        i++;
    }
}

void display_column_names(CDATAFRAME *cdf)
{
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Display the column name
        current = current->next;
    }
}

int count_rows(CDATAFRAME *cdf)
{
    int count = 0;
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Count the number of rows
        current = current->next;
    }
    return count;
}

int count_columns(CDATAFRAME *cdf)
{
    int count = 0;
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Count the number of columns
        current = current->next;
    }
    return count;
}

int count_cells_equal_to(CDATAFRAME *cdf, void *value)
{
    int count = 0;
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Count the number of cells equal to the value
        current = current->next;
    }
    return count;
}

int count_cells_greater_than(CDATAFRAME *cdf, void *value)
{
    int count = 0;
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Count the number of cells greater than the value
        current = current->next;
    }
    return count;
}

int count_cells_less_than(CDATAFRAME *cdf, void *value)
{
    int count = 0;
    LNODE *current = cdf->head;
    while (current != NULL)
    {
        // Count the number of cells less than the value
        current = current->next;
    }
    return count;
}

void display_part_rows(CDATAFRAME *cdf, int limit)
{
    LNODE *current = cdf->head;
    int i = 0;
    while (current != NULL && i < limit)
    {
        // Display the row data
        current = current->next;
        i++;
    }
}

void display_part_columns(CDATAFRAME *cdf, int limit)
{
    LNODE *current = cdf->head;
    int i = 0;
    while (current != NULL && i < limit)
    {
        // Display the column data
        current = current->next;
        i++;
    }
}

void display_number_of_rows(CDATAFRAME *cdf)
{
    int rows = count_rows(cdf);
    printf("Number of rows: %d\n", rows);
}

void display_number_of_columns(CDATAFRAME *cdf)
{
    int cols = count_columns(cdf);
    printf("Number of columns: %d\n", cols);
}

void display_number_of_cells_equal_to(CDATAFRAME *cdf, void *value)
{
    int count = count_cells_equal_to(cdf, value);
    printf("Number of cells equal to %d: %d\n", *(int *)value, count);
}

void display_number_of_cells_greater_than(CDATAFRAME *cdf, void *value)
{
    int count = count_cells_greater_than(cdf, value);
    printf("Number of cells greater than %d: %d\n", *(int *)value, count);
}

void display_number_of_cells_less_than(CDATAFRAME *cdf, void *value)
{
    int count = count_cells_less_than(cdf, value);
    printf("Number of cells less than %d: %d\n", *(int *)value, count);
}

void fill_cdataframe(CDATAFRAME *cdf)
{
    // Fill the CDataframe with user input
    // or hard fill the CDataframe
}

void load_cdataframe_from_csv(CDATAFRAME *cdf, char *filename)
{
    // Load data from a .csv file
}

void store_cdataframe_to_csv(CDATAFRAME *cdf, char *filename)
{
    // Store the contents of the CDataframe in a .csv file
}

void add_row_of_values(CDATAFRAME *cdf, void **values)
{
    // Add a row of values to the CDataframe
}

void delete_row_of_values(CDATAFRAME *cdf, int row_index)
{
    // Delete a row of values from the CDataframe
}

void add_column_to_cdataframe(CDATAFRAME *cdf, ENUM_TYPE cdftype, char *col_name)
{
    // Add a column to the CDataframe
}

void delete_column_from_cdataframe(CDATAFRAME *cdf, char *col_name)
{
    // Delete a column from the CDataframe
}

void rename_column_in_cdataframe(CDATAFRAME *cdf, char *old_name, char *new_name)
{
    // Rename the title of a column in the CDataframe
}

void check_existence_of_value_in_cdataframe(CDATAFRAME *cdf, void *value)
{
    // Check the existence of a value in the CDataframe
}

void display_column_names_in_cdataframe(CDATAFRAME *cdf)
{
    // Display column names in the CDataframe
}

void display_analysis_and_statistics(CDATAFRAME *cdf)
{
    // Display analysis and statistics of the CDataframe
}

void display_number_of_rows_in_cdataframe(CDATAFRAME *cdf)
{
    // Display the number of rows in the CDataframe
}

void display_number_of_columns_in_cdataframe(CDATAFRAME *cdf)
{
    // Display the number of columns in the CDataframe
}

void display_number_of_cells_equal_to_in_cdataframe(CDATAFRAME *cdf, void *value)
{
    // Display the number of cells equal to a value in the CDataframe
}

void display_number_of_cells_greater_than_in_cdataframe(CDATAFRAME *cdf, void *value)
{
    // Display the number of cells greater than a value in the CDataframe
}

void display_number_of_cells_less_than_in_cdataframe(CDATAFRAME *cdf, void *value)
{
    // Display the number of cells less than a value in the CDataframe
}
