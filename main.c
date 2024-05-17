#include <stdio.h>
#include "column.c"
#include "list.c"
#include "cdataframe.c"

#define N 5

int main()
{
    ENUM_TYPE cdftype[] = {INT, CHAR, INT};
    /*CDATAFRAME *cdf = create_cdataframe(cdftype, 3, NULL);
    if (cdf == NULL)
    {
        printf("Error creating CDataframe\n");
        return -1;
    }
    printf("CDataframe created successfully\n");*/

    CDATAFRAME* cdf = load_from_csv("export.csv", cdftype, 3);
    display_cdataframe_like_excel(cdf);
    add_row(cdf);
    display_cdataframe_like_excel(cdf);
    display_number_rows(cdf);
    display_number_col(cdf);

    int value = 1;
    void* val = &value;
    display_number_cells_equal(cdf, val, INT);
    display_number_cells_smaller(cdf, val, INT);
    display_number_cells_greater(cdf, val, INT);

    /*fill_cdataframe_with_inputs(cdf);
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

    display_column_names(cdf);*/

    delete_cdataframe(&cdf);
    if (cdf != NULL)
    {
        printf("Error deleting CDataframe\n");
        return -1;
    }
    printf("CDataframe deleted successfully\n");

    /*ENUM_TYPE tab[10] = {1, "test"};*/
    return 0;
}