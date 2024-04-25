#include <stdio.h>
#include "column.c"
#include "list.c"

#define N 5

int main()
{
    COLUMN *mycol = create_column(CHAR, "Column 1");
    char a = 'A', c = 'C', d = 'D';
    insert_value(mycol, &a);
    insert_value(mycol, (void*) NULL);
    insert_value(mycol, &c);
    print_col(mycol);
    return 0;
}