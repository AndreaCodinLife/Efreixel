#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

void delete_cdataframe(CDATAFRAME **cdf);

void delete_column(CDATAFRAME *cdf, char *col_name);

int get_cdataframe_cols_size(CDATAFRAME *cdf);

void display_cdataframe(CDATAFRAME *cdf);

void add_row(CDATAFRAME *cdf, void **values);

void delete_row(CDATAFRAME *cdf, int row_index);

void add_column(CDATAFRAME *cdf, ENUM_TYPE cdftype, char *col_name);

void delete_column(CDATAFRAME *cdf, char *col_name);

void rename_column(CDATAFRAME *cdf, char *old_name, char *new_name);

bool search_value(CDATAFRAME *cdf, void *value);

void access_replace_value(CDATAFRAME *cdf, int row_index, int col_index, void *value);

void display_column_names(CDATAFRAME *cdf);

int count_rows(CDATAFRAME *cdf);

int count_columns(CDATAFRAME *cdf);

int count_cells_equal_to(CDATAFRAME *cdf, void *value);

int count_cells_greater_than(CDATAFRAME *cdf, void *value);

int count_cells_less_than(CDATAFRAME *cdf, void *value);

void display_part_rows(CDATAFRAME *cdf, int limit);

void display_part_columns(CDATAFRAME *cdf, int limit);

void display_number_of_rows(CDATAFRAME *cdf);

void display_number_of_columns(CDATAFRAME *cdf);

void display_number_of_cells_equal_to(CDATAFRAME *cdf, void *value);

void display_number_of_cells_greater_than(CDATAFRAME *cdf, void *value);

void display_number_of_cells_less_than(CDATAFRAME *cdf, void *value);


void fill_cdataframe(CDATAFRAME *cdf);

void load_cdataframe_from_csv(CDATAFRAME *cdf, char *filename);

void store_cdataframe_to_csv(CDATAFRAME *cdf, char *filename);

void add_row_of_values(CDATAFRAME *cdf, void **values);

void delete_row_of_values(CDATAFRAME *cdf, int row_index);

void add_column_to_cdataframe(CDATAFRAME *cdf, ENUM_TYPE cdftype, char *col_name);

void delete_column_from_cdataframe(CDATAFRAME *cdf, char *col_name);

void rename_column_in_cdataframe(CDATAFRAME *cdf, char *old_name, char *new_name);

void check_existence_of_value_in_cdataframe(CDATAFRAME *cdf, void *value);

void display_column_names_in_cdataframe(CDATAFRAME *cdf);

void display_analysis_and_statistics(CDATAFRAME *cdf);

void display_number_of_rows_in_cdataframe(CDATAFRAME *cdf);

void display_number_of_columns_in_cdataframe(CDATAFRAME *cdf);

void display_number_of_cells_equal_to_in_cdataframe(CDATAFRAME *cdf, void *value);

void display_number_of_cells_greater_than_in_cdataframe(CDATAFRAME *cdf, void *value);

void display_number_of_cells_less_than_in_cdataframe(CDATAFRAME *cdf, void *value);