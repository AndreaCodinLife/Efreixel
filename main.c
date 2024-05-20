#include <stdio.h>
#include "column.c"
#include "list.c"
#include "cdataframe.c"
#include "sort.c"

#define N 5

int main()
{
    char* col_names[] = {"test1", "test2", "test3"};
    ENUM_TYPE cdftype[] = {INT, CHAR, INT};
    CDATAFRAME* cdf = create_cdataframe(cdftype, 3, col_names);

    int running = 1, choice;
    char* col_name, filename;
    int index;
    int col_index;
    int sort_type;
    printf("Enter the command you want to use :\n");
    printf("0. quit\n");
    printf("1. fill the dataframe with inputs\n");
    printf("2. fill the cdataframe with random values\n");
    printf("3. import a dataframe from a csv file\n");
    printf("4. export a dataframe to a csv file\n");
    printf("5. display a dataframe\n");
    printf("6. add a row\n");
    printf("7. add a column\n");
    printf("8. remove a row\n");
    printf("9. remove a column\n");
    printf("10. sort a column\n");
    printf("11. display a column with index\n");
    while (running) {
        
        do {
            printf("your choice : ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 11);
        switch (choice) {
            case 0:
                running = 0;
                break;
            case 1:
                fill_cdataframe_with_inputs(cdf);
                break;
            case 2:
                fill_cdataframe(cdf);
                break;
            case 3:
                cdf = load_from_csv("export.csv", cdftype, 3);
                //display_cdataframe_like_excel(cdf);
            case 4:
                save_into_csv(cdf, "export.csv");
            case 5:
                display_cdataframe_like_excel(cdf);
                break;
            case 6:
                add_row(cdf);
                break;
            case 7:
                printf("Enter the name of the column to create: ");
                scanf("%s", col_name);
                printf("test");
                create_col(cdf, col_name, INT, 0);
                break;
            case 8:
                printf("Enter the index of the row to remove :");
                scanf("%d", &index);
                delete_row(cdf, index);
                break;
            case 9:
                printf("%d", get_cdataframe_cols_size(cdf));
                printf("Enter the name of the column to remove: ");
                scanf("%s", col_name);
                delete_column(cdf, col_name);
                printf("%d", get_cdataframe_cols_size(cdf));
                break;
            case 10:
                printf("Enter the index of the column to sort");
                scanf("%d", &col_index);
                printf("Enter the type of sort : ASC for ascending, DESC for descending");
                scanf("%s ", sort_type);
                sort_cdataframe(cdf, col_index, sort_type);
                break;
            case 11:
                printf("Enter the index of the column to sort");
                scanf("%s ", col_name);
                LNODE* node = cdf->head;
                int out = 0;
                while (node != NULL || !out) {
                    COLUMN* col = node->data;
                    if (col->title == col_name) {
                        print_col_by_index(col);
                        out = 1;
                    }
                }
                
                break;
            default:
                break;
        }
    }
    /*char* col_names[] = {"test1", "test2", "test3"};
    ENUM_TYPE cdftype[] = {INT, CHAR, INT};
    CDATAFRAME* cdf = create_cdataframe(cdftype, 3, col_names);
    fill_cdataframe(cdf);
    display_cdataframe_like_excel(cdf);
    //sort_cdataframe(cdf, 0, "DESC");
    LNODE* node = cdf->head;*/
    /*COLUMN* col = create_column(INT, "test1");
    int a = 1, b = 2, c = 3;
    insert_value(col, &a);
    print_col(col);
    insert_value(col, &b);
    print_col(col);
    insert_value(col, &c);
    print_col(col);*/
    //print_col_by_index(col);
    return 0;
}