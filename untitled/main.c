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
    cdtframe->height=1;
    cdtframe->width=1;
    (cdtframe->tab)[0]=mycol;
    printf("%d \n",((cdtframe->tab)[0]->tab)[1]);
    display_full_CDataframe(cdtframe);
    /**
    CDATAFRAME* cdtframe=create_empty_CDataframe();
    fill_CDataframe(cdtframe); /*problème ici
    display_full_CDataframe(cdtframe); */
    return 0;

}

