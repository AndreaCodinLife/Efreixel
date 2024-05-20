#include <stdio.h>
#include "column.c"
#include "list.c"
#include "cdataframe.c"
#include "sort.c"

#define N 5

int main()
{
    /*int running = 1, choice;
    char* col_names[] = {};
    CDATAFRAME* cdf = create_cdataframe(NULL, 0, col_names);
    char* col_name;
    while (running) {
        printf("Enter the command you want to use :\n");
        printf("0. quit\n");
        printf("2. import a dataframe from a csv file\n");
        printf("3. export a dataframe to a csv file\n");
        printf("4. display a dataframe\n");
        printf("5. add a row\n");
        printf("6. add a column\n");
        do {
            printf("your choice : ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 2);
        switch (choice) {
            case 0:
                running = 0;
                break;
            case 4:
                display_cdataframe_like_excel(cdf);
                break;
            case 6:
                printf("Enter the name of the column to create");
                scanf("%s", col_names);
                create_col(cdf, col_name, INT, 0);
                break;
            default:
                break;
        }
    }*/

    COLUMN* col = create_column(INT, "test");
    int a = 1, b = 2, c = 3, d = 4; 
    void* val = &a;
    insert_value(col, &a);
    insert_value(col, &b);
    insert_value(col, &c);
    insert_value(col, &d);
    print_col(col);
    print_col_by_index(col);
    printf("%d", search_value_in_column(col, val));
    return 0;
}