#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"
#include "list.h"

// Function prototypes

/**
 * @brief Create a new CDataframe
 * @param cdftype An array of ENUM_TYPE representing the types of columns
 * @param size The number of columns in the CDataframe
 * @return A pointer to the created CDataframe
 */
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

/**
* @brief: Column deletion
* param1: Pointer to the CDataframe to delete */
void delete_cdataframe(CDATAFRAME **cdf);

/**
 * @brief: Number of columns
 * @param1: Point to the CDataframe
 * @return: Number of columns in the CDataframe
 */
int get_cdataframe_cols_size(CDATAFRAME *cdf);

#endif