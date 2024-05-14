#include <stdio.h>
#include "cdataframe.h"
#include <stdlib.h>
#include "column.h"
#include "cdataframeLS.h"

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
    modify_value(mycol,4,1);
    print_col(mycol);
    insert_value_in_col(mycol,12,2);
    print_col(mycol);
    delete_value(mycol,2);
    print_col(mycol);
    fill_column(mycol);
    print_col(mycol);
    fill_and_replace_column(mycol);
    print_col(mycol);
    column_menu(mycol);
    unique_column_choice(cdtframe);
    printf("bonjour \n");
    print_col((cdtframe->tab)[0]);
    printf("test aaaa\n");
    print_col((cdtframe->tab)[1]);



    /**cdtframe->height=mycol->tl;
    cdtframe->width=3;
    (cdtframe->tab)[0]=mycol;
    (cdtframe->tab)[1]=mycol;
    (cdtframe->tab)[2]=mycol;
    printf("%d \n",((cdtframe->tab)[0]->tab)[1]);*/

    /**
    fill_CDataframe(cdtframe);
    printf("%d \n",cdtframe->width);
    (cdtframe->tab)[7]=mycol;
    cdtframe->width=8;
    printf("%d \n",cdtframe->width);
    display_full_CDataframe(cdtframe);
    display_partial_columns(cdtframe,3);
    printf("\n");
    display_partial_rows(cdtframe,5);
     */
    return 0;

}

