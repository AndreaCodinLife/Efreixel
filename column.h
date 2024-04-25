#ifndef COLUMN_H
#define COLUMN_H

#include <stddef.h>

// Define the ENUM_TYPE enumeration
enum enum_type
{
    NULLVAL = 1,
    UINT,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    STRING,
    STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

// Define the COL_TYPE union
union column_type
{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char *string_value;
    void *struct_value;
};
typedef union column_type COL_TYPE;

// Define the COLUMN structure
struct column
{
    char *title;
    unsigned int size;     // logical size
    unsigned int max_size; // physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;

// Function prototypes

/**
 * @brief Create a new column
 * @param type The type of the column (ENUM_TYPE)
 * @param title The title of the column
 * @return A pointer to the created column
 */
COLUMN *create_column(ENUM_TYPE type, char *title);

/**
 * @brief Insert a value into a column
 * @param col A pointer to the column
 * @param value A pointer to the value to be inserted
 * @return 1 if the value is correctly inserted, 0 otherwise
 */
int insert_value(COLUMN *col, void *value);

/**
 * @brief Free the memory allocated by a column
 * @param col A pointer to the pointer of the column to be deleted
 */
void delete_column(COLUMN **col);

/**
 * @brief: Convert a value into a string
 * @param1: Pointer to the column
 * @param2: Position of the value in the data array
 * @param3: The string in which the value will be written
 * @param4: Maximum size of the string
 */
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

/**
 * @brief: Display the content of a column
 * @param: Pointer to the column to display
 */
void print_col(COLUMN *col);



int count_occurrences(COLUMN *col, void *value);
void *get_value(COLUMN *col, unsigned long long int i);
int count_greater(COLUMN *col, void *value);
int count_less(COLUMN *col, void *value);
int count_equal(COLUMN *col, void *value);

#endif // COLUMN_H
