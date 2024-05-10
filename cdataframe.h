#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"
#include "list.h"
#include <stdbool.h>

// Function prototypes

/**
 * @brief Create a new CDataframe
 * @param cdftype An array of ENUM_TYPE representing the types of columns
 * @param size The number of columns in the CDataframe
 * @return A pointer to the created CDataframe
 */
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

/**
* @brief Delete a CDataframe
* @param cdf Pointer to the CDataframe to delete 
*/
void delete_cdataframe(CDATAFRAME **cdf);

/**
* @brief Delete a column from a CDataframe
* @param cdf Pointer to the CDataframe from which we want to delete a column
* @param col_name Name of the column that we want to delete
*/
void delete_column(CDATAFRAME *cdf, char *col_name);

/**
 * @brief Number of columns
 * @param cdf Point to the CDataframe
 * @return Number of columns in the CDataframe
 */
int get_cdataframe_cols_size(CDATAFRAME *cdf);

/**
 * @brief fill a CDataframe with user input
 * @param cdf Point to the CDataframe
 */
void fill_cdataframe_with_inputs(CDATAFRAME* cdf);

/**
 * @brief Display the entire CDataframe
 * @param cdf Point to the CDataframe
 */
void display_cdataframe(CDATAFRAME* cdf);

/**
 * @brief Display a number of rows from the CDataframe
 * @param cdf Point to the CDataframe
 * @param nb_rows The number of rows to diplay
 */
void display_cdataframe_with_rows_limit(CDATAFRAME* cdf, int nb_rows);

/**
 * @brief Display a number of columns from the CDataframe
 * @param cdf Point to the CDataframe
 * @param nb_col The number of columns to diplay
 */
void display_cdataframe_with_col_limit(CDATAFRAME* cdf, int nb_col);

/**
 * @brief Delete a row from the CDataframe
 * @param cdf Point to the CDataframe
 * @param index The index of the row to delete
 */
void delete_row(CDATAFRAME* cdf, int index);

/**
 * @brief Create a column in a CDataframe
 * @param cdf Point to the CDataframe
 * @param title The name of the column to create
 * @param type The type of the values in the column
 * @param index The index of the column to create
 * @return A pointer to the node
 */
LNODE* create_col(CDATAFRAME* cdf, char* title, ENUM_TYPE type, int index);

/**
 * @brief Rename a column of a CDataframe
 * @param cdf Point to the CDataframe
 * @param index The index of the column to rename
 * @param newName The new name of the column
 */
void rename_col(CDATAFRAME* cdf, int index, char* newName);

/**
 * @brief Return true if a value is in the CDataframe
 * @param cdf Point to the CDataframe
 * @param value The value to search in the CDataframe
 * @param type The type of the value to search in the CDataframe
 * @return true if the value is in the CDataframe, false in the other case
 */
bool is_in_cdataframe(CDATAFRAME* cdf, void* value, ENUM_TYPE type);

/**
 * @brief Replace the value in a CDataframe cell using its row and column number
 * @param cdf Point to the CDataframe
 * @param rowNb The index of the column in which the value is located
 * @param colNb The index of the row in which the value is located
 * @param value The value that we want to insert in the CDataframe
 */
void replace_value(CDATAFRAME* cdf, int rowNb, int colNb, void* value);

/**
 * @brief Display the name of every columns of the CDataframe
 * @param cdf Point to the CDataframe
 */
void display_column_names(CDATAFRAME* cdf);

void display_cdataframe_like_excel(CDATAFRAME* cdf);

#endif