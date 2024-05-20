#ifndef SORT_H
#define SORT_H
#include "column.h"
#include "cdataframe.h"


#define ASC 0
#define DESC 1

/**
* @brief : Sort a column
* @param 1: Pointer to the column to sort
* @param 2: Sort direction (ASC or DESC)
 */
void sort(COLUMN* col, int sort_dir);

/**
 * @brief: Sort a column using the quicksort algorithm
 * @param 1: Pointer to the column to sort
 * @param 2: Left index of the column
 * @param 3: Right index of the column
 */
void quicksort(COLUMN* col, int left, int right);
/**
 * @brief: Partition the column
 * @param 1: Pointer to the column to partition
 * @param 2: Left index of the column
 * @param 3: Right index of the column
 * @return: The pivot index
 */
int partition(COLUMN* col, int left, int right);
/**
 * @brief: Sort a column using the insertion sort algorithm
 * @param 1: Pointer to the column to sort
 */
void insertion_sort(COLUMN* col);
/**
 * @brief: Sort a CDataframe according to a given column
 * @param 1: Pointer to the CDataframe to sort
 * @param 2: Index of the column to sort
 * @param 3: Sort type (ASC or DESC)
*/
void sort_cdataframe(CDATAFRAME* cdf, int col_index, char* sort_dir);
/**
 * @brief: Display the content of a sorted column
 * @param 1: Pointer to a column
 */
void print_col_by_index(COLUMN *col);

/**
 * @brief: Reverse the order of an array
 * @param 1: Pointer to the array
 * @param 2: Size of the array
 */
void reverse_array(void** data, int size);

/**
 * @brief: Update the index
 * @param1: Pointer to the column
 */
void update_index(COLUMN *col);

#endif // SORT_H
