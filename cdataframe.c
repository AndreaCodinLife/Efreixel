#include "cdataframe.h"
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void fill_cdataframe_with_inputs(CDATAFRAME* cdf) {
    if (!(cdf == NULL || cdf->head == NULL)) {
        LNODE* node = cdf->head;
        int size;
        while (node != NULL) {// cdf->tail

            printf("How many values do you want to store in this column ?\nnb values: ");
            scanf("%d", &size);
            COLUMN* column = node->data;
            for (int i = 0; i < size; i++) {       
                void* value = (void*) malloc(sizeof(column->column_type));
                
                switch (column->column_type)
                    {
                    case UINT:
                        printf("Enter a number:");
                        scanf("%u", (unsigned int*)value);
                        break;
                    case INT:
                        printf("Enter a number:");
                        scanf("%d", (int*)value);
                        break;
                    case CHAR:
                        printf("Enter a character:");
                        scanf(" %c", (char*)value);
                        break;
                    case FLOAT:
                        printf("Enter a floating number:");
                        scanf("%f", (float*)value);
                        break;
                    case DOUBLE:
                        printf("Enter a floating number:");
                        scanf("%lf", (double*)value);
                        break;
                    case STRING:
                        printf("Enter a word:");
                        scanf("%s", (char*)value);
                        break;
                    case STRUCTURE:
                        break;
                    default:
                        value = NULL;
                        break;
                    }
                insert_value(node->data, value);
            }
            node = node->next;
        }
    }
}

void display_cdataframe(CDATAFRAME* cdf) {
    LNODE* node = cdf->head;
    while(node != NULL) {
        print_col(node->data);
        node = node->next;
        printf("\n");
    }
    printf("-----------\n");
}

void display_cdataframe_with_rows_limit(CDATAFRAME* cdf, int nb_rows) {
    LNODE* node = cdf->head;
    for(int i=0; i < nb_rows && node != NULL; i++) {
        print_col(node->data);
        node = node->next;
        printf("\n");
    }
}

void display_cdataframe_with_col_limit(CDATAFRAME* cdf, int nb_col) {
    LNODE* node = cdf->head;
    while(node != NULL) {
        COLUMN* col = node->data;
        int size = col->size;
        col->size = nb_col;
        print_col(col);
        col->size = size;
        node = node->next;
        printf("\n");
    }
}

void delete_row(CDATAFRAME* cdf, int index) {
    LNODE* node = cdf->head;
    while (node != NULL) {
        COLUMN* col = node->data;
        int i;
        if (0 <= index < col->size) {
            for (i = index; i < col->size - 1; i++) {
                col->data[i] = col->data[i+1];
            }
            free(col->data[i]);
            col->data[i] = NULL;
            col->size--;
        } 
        node = node->next;
    }
}

LNODE* create_col(CDATAFRAME* cdf, char* title, ENUM_TYPE type, int index) {
    LNODE* node = cdf->head;
    int pos = 0;
    while (pos < index && node != NULL) {
        node = node->next;
        pos++;
    }
    COLUMN* col = create_column(type, title);
    LNODE* P = (LNODE*) malloc(sizeof(LNODE));
    P->data = col;
    P->next = node->next;
    node->next = P;
    return P;
}

void rename_col(CDATAFRAME* cdf, int index, char* newName) {
    LNODE* node = cdf->head;
    int pos = 0;
    while (pos < index && node != NULL) {
        node = node->next;
    }
    if (node != NULL) {
        COLUMN* col = node->data;
        col->title = newName;
    }
}

bool is_in_cdataframe(CDATAFRAME* cdf, void* value, ENUM_TYPE type) {
    LNODE* node = cdf->head;
    while (node != NULL) {
        COLUMN* col = node->data;
        if(col->column_type == type) {
            for (int i = 0; i < col->size; i++) {
                if (*(int*)col->data[i] == *(int*)value) {
                    return true;
                    break;
                }
            }
        }
        node = node->next;
    }
    return false;
}

void replace_value(CDATAFRAME* cdf, int rowNb, int colNb, void* value) {
    LNODE* node = cdf->head;
    int pos = 0;
    while(pos < rowNb && node != NULL) {
        pos++;
        node = node->next;
    }
    if (node != NULL) {
        COLUMN* col = node->data;
        if (colNb < col->size) {
            col->data[colNb] = value;
        }
    }
}

void display_column_names(CDATAFRAME* cdf) {
    LNODE* node = cdf->head;
    while (node != NULL) {
        COLUMN* col = node->data;
        printf("%s ", col->title);
        node = node->next;
    }
    printf("/n");
}