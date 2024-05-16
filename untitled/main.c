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


    Create_Cdataframe_Column(cdtframe);
    unique_column_choice(cdtframe);
    Create_Cdataframe_Column(cdtframe);
    unique_column_choice(cdtframe);
    display_full_CDataframe(cdtframe);
    printf("%d \n", count_occurrences(mycol,5));
    return 0;

}

