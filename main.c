#include <stdio.h>
#include "column.c"
#include "list.c"
#include "cdataframe.c"

int main() {
    COLUMN* pt;
    pt = create_column(3, "test");
    insert_value(pt, (void*)3);
    display_col(pt);
    return 0;
}