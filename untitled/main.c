#include <stdio.h>
#include "cdataframe.h"
#include <stdlib.h>
#include "column.h"

int main() {
    printf("Hello, World!\n");
    COLUMN *mycol = create_column("My column");
    CDATAFRAME* cdtframe=create_empty_CDataframe();
    printf("%s;%d;%d;%p \n",mycol->titre,mycol->tl,mycol->tp,mycol->tab);
    int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);
    column_menu(mycol);
    print_col(mycol);
    return 0;

}

