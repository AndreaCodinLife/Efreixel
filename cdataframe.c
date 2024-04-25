#include "cdataframe.h"
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new CDataframe
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    // Implement function to create a new CDataframe
    // with the specified column types
    // and initialize the doubly-linked list
}

// Function to delete a CDataframe
void delete_cdataframe(CDATAFRAME **cdf) {
    // Implement function to delete the CDataframe
    // by freeing all columns and the list itself
}

// Function to delete a column from the CDataframe
void delete_column(CDATAFRAME *cdf, char *col_name) {
    // Implement function to delete a column
    // from the CDataframe by column name
}

// Function to get the number of columns in the CDataframe
int get_cdataframe_cols_size(CDATAFRAME *cdf) {
    // Implement function to count the number of columns
    // in the CDataframe
}

// Other functions for filling, displaying, and
// performing operations on the CDataframe
// ...

// Helper functions for manipulating the doubly-linked list
// ...