/**
* Projet_C_Ronan_Baptiste
* Baptiste BERTRAND / Ronan MYCHALSKI
* Contient les fonctions qui permettent de lancer le projet.
*/
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
    printf("Le nombre d'occurences est %d\n", count_occurrences_in_cdataframe(cdtframe,7));
    print_height(cdtframe);
    print_cdataframe_column_name(cdtframe);
    print_width(cdtframe);
    fill_CDataframe(cdtframe);
    display_full_CDataframe(cdtframe);
    printf("Le nombre d'occurences est %d \n", count_occurrences_in_cdataframe(cdtframe,7));
    printf("Le nombre d'occurences est %d \n", count_occurrences_in_cdataframe(cdtframe,7));
    print_height(cdtframe);
    rename_cdataframe_column(cdtframe);
    print_width(cdtframe);
    append_row_in_cdataframe(cdtframe);
    display_full_CDataframe(cdtframe);
    delete_row_from_CDataframe(cdtframe,5);
    display_full_CDataframe(cdtframe);
    print_cdataframe_column_name(cdtframe);
    print_full_cdataframe_titles(cdtframe);
    delete_column_from_CDataframe(cdtframe,5);
    display_full_CDataframe(cdtframe);
    printf("Le nombre d'occurences est %d \n", count_occurrences_in_cdataframe(cdtframe,7));
    unique_column_choice(cdtframe);
    print_height(cdtframe);
    print_width(cdtframe);
    printf("Le nombre d'occurences est %d \n", count_occurrences_in_cdataframe(cdtframe,1));
    print_col(mycol);
    column_menu(mycol);
    print_col(mycol);
    printf("%d",mycol->tl);
    printf("%d \n", count_occurrences(mycol,5));
    return 0;

}

