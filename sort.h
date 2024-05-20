#ifndef SORT_H
#define SORT_H
#include "column.h"


#define ASC 0
#define DESC 1

void sort(COLUMN* col, int sort_dir);
void quicksort(COLUMN* col, int left, int right);
int partition(COLUMN* col, int left, int right);
void insertion_sort(COLUMN* col);
void sort_cdataframe(CDATAFRAME* cdf, int col_index, char* sort_dir);
void print_col_by_index(COLUMN *col);

#endif // SORT_H
