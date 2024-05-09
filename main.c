#include <stdio.h>
#include "column.c"
#include "list.c"
#include "cdataframe.c"

#define N 5

int main()
{
    ENUM_TYPE cdftype[] = {INT, INT, INT};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 3);
    if (cdf == NULL)
    {
        printf("Error creating CDataframe\n");
        return -1;
    }
    printf("CDataframe created successfully\n");

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
    printf("CDataframe deleted successfully\n");

    /*ENUM_TYPE tab[10] = {1, "test"};*/
    return 0;
}