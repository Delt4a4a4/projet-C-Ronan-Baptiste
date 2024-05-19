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

    print_col(mycol);
    column_menu(mycol);
    print_col(mycol);
    printf("%d \n", count_occurrences(mycol,5));
    return 0;

}

