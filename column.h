#ifndef COLUMN_H
#define COLUMN_H

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

struct column
{
    char *title;
    unsigned int size;     // logical size
    unsigned int max_size; // physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;


/**
 * Create a new column
 * @param1 : Column type
 * @param2 : Column title
 * @return : Pointer to the created column
 */
COLUMN *create_column(ENUM_TYPE type, char *title);

/**
  * @brief: Insert a new value into a column
  * @param1: Pointer to the column
  * @param2: Pointer to the value to insert
  * @return: 1 if the value is correctly inserted 0 otherwise
*/
int  insert_value(COLUMN *col, void *value);

/**
 * @brief: Convert a value into a string
 * @param1: Pointer to the column
 * @param2: Position of the value in the data array
 * @param3: The string in which the value will be written
 * @param4: Maximum size of the string
 */
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

void display_col(COLUMN*);

#endif