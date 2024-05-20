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
    while (running) {
        printf("Enter the command you want to use :\n");
        printf("0. quit\n");
        printf("1. create a new dataframe\n");
        printf("2. import a dataframe from a csv file\n");
        printf("3. export a dataframe to a csv file\n");
        printf("4. display a dataframe\n");
        printf("5. add a row\n");
        printf("6. add a column\n");
        printf("7. remove a row\n");
        printf("8. remove a column\n");
        printf("9. sort a column\n");
        do {
            printf("your choice : ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 9);
        switch (choice) {
            case 0:
                running = 0;
                break;
            case 1:
                fill_cdataframe_with_inputs(cdf);
                break;
            case 2:
                cdf = load_from_csv("export.csv", cdftype, 3);
                //display_cdataframe_like_excel(cdf);
            case 3:
                save_into_csv(cdf, "export.csv");
            case 4:
                display_cdataframe_like_excel(cdf);
                break;
            case 5:
                add_row(cdf);
                break;
            case 6:
                printf("Enter the name of the column to create: ");
                scanf("%s ", col_name);
                printf("%s", col_name);
                create_col(cdf, col_name, INT, 0);
                break;
            case 7:
                printf("Enter the index of the row to remove :");
                scanf("%d", &index);
                delete_row(cdf, index);
                break;
            case 8:
                printf("Enter the name of the column to remove: ");
                scanf("%s", col_name);
                delete_column(cdf, col_name);
                break;
            case 9:
                printf("Enter the index of the column to sort");
                scanf("%d", &col_index);
                printf("Enter the type of sort : ASC for ascending, DESC for descending");
                scanf("%d", &sort_type);
                sort_cdataframe(cdf, col_index, sort_type);
                break;
            default:
                break;
        }
    }
    return 0;
}