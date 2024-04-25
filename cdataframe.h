#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"
#include "list.h"

// Define the CDATAFRAME structure
typedef struct {
    LIST *columns;
    // Any other necessary fields
} CDATAFRAME;

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
 * @param cdf A pointer to the pointer of the CDataframe to be deleted
 */
void delete_cdataframe(CDATAFRAME **cdf);

/**
 * @brief Delete a column from the CDataframe
 * @param cdf A pointer to the CDataframe
 * @param col_name The name of the column to be deleted
 */
void delete_column(CDATAFRAME *cdf, char *col_name);

/**
 * @brief Get the number of columns in the CDataframe
 * @param cdf A pointer to the CDataframe
 * @return The number of columns in the CDataframe
 */
int get_cdataframe_cols_size(CDATAFRAME *cdf);

// Prototypes for other CDataframe functions
// ...

#endif // CDATAFRAME_H
