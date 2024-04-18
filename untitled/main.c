#include <stdio.h>
#include "CDataFrame.h"
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");
    COLUMN *mycol = create_column("My column");
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
    return 0;

}

