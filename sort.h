#ifndef SORT_H
#define SORT_H
#include "column.h"


#define ASC 0
#define DESC 1
/**
* @brief: Sort a column according to a given order 
* @param1: Pointer to the column to sort 
* @param2: Sort type (ASC or DESC) 
*/
void sort(COLUMN* col, int sort_dir);

/**
* @brief: Display the content of a sorted column 
* @param1: Pointer to a column 
*/
void print_col_by_index(COLUMN *col);

void swap(int* a, int* b);

void quick_sort(int* index, void** data, int low, int high, int sort_dir);

int partition(int* index, void** data, int low, int high, int sort_dir);

void insertion_sort(int* index, void** data, int size, int sort_dir);


#endif // SORT_H