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
    /*ENUM_TYPE* cdftype = {INT};*/
    COLUMN* col = create_column(CHAR, "test");
    char a[] = "a", b[] = "b", c[] = "c", d[] = "d", e[] = "e"; 
    void* val1 = &e;
    void* val2 = &a;
    insert_value(col, &a);
    insert_value(col, &b);
    insert_value(col, &c);
    insert_value(col, &d);
    print_col(col);
    print_col_by_index(col);
    printf("%d\n", search_value_in_column(col, val1));
    printf("%d\n", search_value_in_column(col, val2));
    /*
    CDATAFRAME* cdf = load_from_csv("export.csv", cdftype, 3);
    display_cdataframe_like_excel(cdf);*/
    //add_row(cdf);
    //display_cdataframe_like_excel(cdf);
    //display_number_rows(cdf);
    //display_number_col(cdf);

    /*int value = 1;
    void* val = &value;
    //display_number_cells_equal(cdf, val, INT);
    //display_number_cells_smaller(cdf, val, INT);
    //display_number_cells_greater(cdf, val, INT);

    //sort
    sort_cdataframe(cdf, 0, "DESC");





    fill_cdataframe_with_inputs(cdf);
    display_cdataframe(cdf);
    //delete_row(cdf, 1);
    //display_cdataframe(cdf);
    int value = 2;
    void* val = &value;
    if (is_in_cdataframe(cdf, val, INT)) {
        printf("The value %d is in the dataframe.\n", value);
    } else {
        printf("The Value %d is not in the dataframe.\n", value);
    }

    value = 6;
    val = &value;
    replace_value(cdf, 2, 1, val);
    display_cdataframe(cdf);

    display_column_names(cdf);

    delete_cdataframe(&cdf);
    if (cdf != NULL)
    {
        printf("Error deleting CDataframe\n");
        return -1;
    }
    printf("CDataframe deleted successfully\n");*/
    return 0;
}