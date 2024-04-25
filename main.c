#include <stdio.h>
#include "column.c"
#include "list.c"
#include "cdataframe.c"

#define N 5

int main()
{
    ENUM_TYPE cdftype[] = {INT, CHAR, INT};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 3);
    if (cdf == NULL)
    {
        printf("Error creating CDataframe\n");
        return -1;
    }
    printf("CDataframe created successfully\n");
    delete_cdataframe(&cdf);
    if (cdf != NULL)
    {
        printf("Error deleting CDataframe\n");
        return -1;
    }
    printf("CDataframe deleted successfully\n");
    
    return 0;
}