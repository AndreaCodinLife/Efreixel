#include "cdataframe.h"
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new CDataframe
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    CDATAFRAME *cdf = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    if (cdf == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    cdf->head = NULL;
    cdf->tail = NULL;
    for (int i = 0; i < size; i++) {
        COLUMN *col = create_column(cdftype[i], "Column");
        if (col == NULL) {
            // Handle memory allocation failure
            return NULL;
        }
        LNODE *lnode = (LNODE *)malloc(sizeof(LNODE));
        if (lnode == NULL) {
            // Handle memory allocation failure
            return NULL;
        }
        lnode->data = col;
        lnode->prev = NULL;
        lnode->next = NULL;
        if (cdf->head == NULL) {
            cdf->head = lnode;
            cdf->tail = lnode;
        } else {
            cdf->tail->next = lnode;
            lnode->prev = cdf->tail;
            cdf->tail = lnode;
        }
    }    
    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf) {
    LNODE *current = (*cdf)->head;
    while (current != NULL) {
        LNODE *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(*cdf);
    *cdf = NULL;
}
void delete_column(CDATAFRAME *cdf, char *col_name) {
    LNODE *current = cdf->head;
    while (current != NULL) {
        if (strcmp(((COLUMN*)current->data)->title, col_name) == 0) {
            free(current->data);
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                cdf->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                cdf->tail = current->prev;
            }
            free(current);
            break;
        }
        current = current->next;
    }
}

int get_cdataframe_cols_size(CDATAFRAME *cdf) {
    int count = 0;
    LNODE *current = cdf->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}