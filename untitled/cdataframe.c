//
// Created by Baptiste BERTRAND on 17/04/2024.
//
/**
* Projet_C_Ronan_Baptiste
* Baptiste BERTRAND / Ronan MYCHALSKI
* Contient les fonctions en lien avec le cdataframe.
*/
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"

/**
* @brief: Create an empty CDataframe.
* @return: Pointer to the created CDataframe.
*/
CDATAFRAME* create_empty_CDataframe(){
    CDATAFRAME* cdtframe=malloc(sizeof(CDATAFRAME));
    cdtframe->tab=malloc(sizeof(COLUMN*)*256);
    cdtframe->width=0;
    cdtframe->height=0;
    return cdtframe;
}

/**
* @brief: Fill the CDataframe from user inputs or hard-coded values.
* @param1: Pointer to the CDataframe to be filled.
* @return: modification of CDataframe no need to return something
*/
void fill_CDataframe(CDATAFRAME* cdtframe){
    cdtframe->width=8;
    cdtframe->height=8;
    for (int i=0 ; i<cdtframe->width ; i++){
        (cdtframe->tab)[i]=create_column("untilted");
        for (int j=0 ; j < cdtframe->height ; j++){
            insert_value((cdtframe->tab)[i], 1);
        }
    }
}



/**
* @brief: Display the entire CDataframe.
* @param1: Pointer to the CDataframe to be displayed.
* @return: modification of CDataframe no need to return something
*/
void display_full_CDataframe(CDATAFRAME* cdtframe){
    for (int i=0 ; i<cdtframe->width ; i++){
        printf("     [%d]     ",i);
    }
    printf("\n");
    for (int i=0 ; i<cdtframe->height ; i++){
        printf("[%d]",i);
        for (int j=0 ; j < cdtframe->width ; j++){
            if ((cdtframe->tab)[j]->tl > i) {
                printf("      %d      ", ((cdtframe->tab)[j]->tab)[i]);
            }
            else{
                printf("            ");
            }
        }
        printf("\n");
    }
}


/**
* @brief: Display a portion of the rows of the CDataframe according to a limit provided by the user.
* @param1: Pointer to the CDataframe.
* @param2: Limit provided by the user (number of rows to display).
* @return: modification of CDataframe no need to return something
*/
void display_partial_rows(CDATAFRAME* cdtframe, int limit){
    if (limit > cdtframe->height) {
        limit= cdtframe->height;
    }
    for (int i=0 ; i< limit ; i++){
        for (int j=0 ; j < cdtframe->width ; j++){
            printf(" %d ",(cdtframe->tab)[j]->tab[i]);
        }
        printf("\n");
    }
}

/**
* @brief: Display a portion of the columns of the CDataframe according to a limit provided by the user.
* @param1: Pointer to the CDataframe.
* @param2: Limit provided by the user (number of columns to display).
* @return: modification of CDataframe no need to return something
*/
void display_partial_columns(CDATAFRAME* cdtframe, int limit){
    if (limit > cdtframe->width) {
        limit= cdtframe->width;
    }
    for (int i=0 ; i< cdtframe->height ; i++){
        for (int j=0 ; j < limit ; j++){
            printf(" %d ",(cdtframe->tab)[j]->tab[i]);
        }
        printf("\n");
    }
}

/**
 * fonction présentant de nombreux disfonctionnements
* @brief: Allows you to choose a column to modify using its index
* @param1: Pointer to the CDataframe.
* @return: modification of CDataframe no need to return something
*/
void unique_column_choice(CDATAFRAME* cdtframe){
    int n=-1;
    int test=0;
    while(n<0){
        printf("Quel est l'indice de la colonne que vous voulez modifier ? \n");
        scanf(" %d",&n);
    }
    if(n>cdtframe->width){
        printf("Cette colonne n'existe pas, voulez-vous creer une colonne %d ? \n 1) Oui \n 2) Non",cdtframe->width);
        scanf(" %d",&test);
        if(test==1){
            Create_Cdataframe_Column(cdtframe);
            n=cdtframe->width;
        }
        else{
            return;
        }
    }
    column_menu((cdtframe->tab)[n]);
    if((cdtframe->tab)[cdtframe->width]->tl>cdtframe->height){
        cdtframe->height=(cdtframe->tab)[cdtframe->width]->tl;
    }
}

/**
* @brief: Allows you to create an empty column in the Cdataframe
* @param1: Pointer to the CDataframe.
* @return: modification of CDataframe no need to return something
*/
void Create_Cdataframe_Column(CDATAFRAME* cdtframe){
    COLUMN** p=NULL;
    char name[100];
    printf("Saisir le nom de votre nouvelle colonne \n");
    scanf(" %s",name);
    cdtframe->tab = (COLUMN**) realloc(cdtframe->tab,sizeof(COLUMN)*((cdtframe->width)+1));
    (cdtframe->tab)[cdtframe->width]= create_column(name);
    (cdtframe->width)++;
    printf("%d \n",cdtframe->width);
    printf("%s \n", (cdtframe->tab)[cdtframe->width-1]->titre);
}

/**
* @brief: Allows you to delete few columns in the Cdataframe thanks to indexes
* @param1: Pointer to the CDataframe.
* @return: modification of CDataframe no need to return something
*/
void delete_multiple_columns(CDATAFRAME* cdtframe){
    if (cdtframe->width==0){
        printf("Erreur, le cdataframe est vide \n");
        return;
    }
    int first_column=-1;
    int last_column=-1;
    int value=0;
    while(first_column<0 || first_column>cdtframe->width){
        printf("A partir de quelle colonne voulez-vous supprimer des colonnes ? \n");
        scanf(" %d",&first_column);
    }
    while(last_column<first_column || last_column>cdtframe->width){
        printf("Jusqu'a quelle ligne voulez-vous supprimer des cellules (non inclue) ? \n");
        scanf(" %d",&last_column);
    }
    for(int i=first_column; i<last_column ; i++){
        delete_column_from_CDataframe(cdtframe,first_column);
    }
}

/**
* @brief: Allows you to delete one column in the Cdataframe thanks to indexes
* @param1: Pointer to the CDataframe.
* @param2 :Value for the position of the column
* @return: modification of CDataframe no need to return something
*/
void delete_column_from_CDataframe(CDATAFRAME* cdtframe, int pos){
    if (cdtframe->width==0){
        printf("Erreur, le cdataframe est vide \n");
        return;
    }
    if(pos>=cdtframe->width){
        printf("La colonne que vous tentez de supprimer n'existe pas \n");
        return;
    }
    delete_column(&(cdtframe->tab)[pos]);
    for (int i=pos ; i<(cdtframe->width)-1 ; i++ ){
        (cdtframe->tab)[i]=(cdtframe->tab)[i+1];
    }
    (cdtframe->width)--;
}

/**
* @brief: Allows you to delete one in the Cdataframe thanks to indexes
* @param1: Pointer to the CDataframe.
* @param2 :Value for the position of the row
* @return: modification of CDataframe no need to return something
*/
void delete_row_from_CDataframe(CDATAFRAME* cdtframe, int index){
    if(index>=cdtframe->height){
        printf("La ligne que vous tentez de supprimer n'existe pas");
        return;
    }
    for(int i=0 ; i<cdtframe->width ; i++){
        delete_value((cdtframe->tab)[i], index);
    }
    (cdtframe->height)--;
}

/**
* @brief: allows you to count the number of occurrences of a value in the Cdataframe
* @param1: Pointer to the CDataframe.
* @param2 :Value we are searching
* @return: number of occurences
*/
int count_occurrences_in_cdataframe(CDATAFRAME* cdtframe, int x){
    int somme=0;
    for(int i=0 ; i<cdtframe->width ; i++){
        somme+= count_occurrences((cdtframe->tab)[i],x);
    }
    return somme;
}

/**
* @brief: allows you to count the number of values greater than x in Cdataframe
* @param1: Pointer to the CDataframe.
* @param2 :Value we use to compare
* @return: number of value greater than x in Cdataframe
*/
int count_greater_in_cdataframe(CDATAFRAME* cdtframe, int x){
    int somme=0;
    for(int i=0 ; i<cdtframe->width ; i++){
        somme+= count_greater((cdtframe->tab)[i],x);
    }
    return somme;
}

/**
* @brief: allows you to count the number of values lower than x in Cdataframe
* @param1: Pointer to the CDataframe.
* @param2 :Value we use to compare
* @return: number of value lower than x in Cdataframe
*/
int count_lower_in_cdataframe(CDATAFRAME* cdtframe, int x){
    int somme=0;
    for(int i=0 ; i<cdtframe->width ; i++){
        somme+= count_lower((cdtframe->tab)[i],x);
    }
    return somme;
}

/**
* @brief: allows you to print the width of column
* @param1: Pointer to the CDataframe.
* @return: printing the value so no need to return something
*/
void print_width(CDATAFRAME* cdtframe){
    printf("Votre cdataframe contient %d colonnes \n",cdtframe->width);
}

/**
* @brief: allows you to print the height of column
* @param1: Pointer to the CDataframe.
* @return: printing the value so no need to return something
*/
void print_height(CDATAFRAME* cdtframe){
    printf("Votre cdataframe contient %d lignes\n", cdtframe->height);
}

/**
* @brief: allows you to add a row in Cdataframe
* @param1: Pointer to the CDataframe.
* @return: modification of CDataframe no need to return something
*/
void append_row_in_cdataframe(CDATAFRAME* cdtframe){
    int row=-1;
    int val;
    while(row<0 || row>cdtframe->height){
        printf("Quelle ligne voulez-vous inserer ? (ligne max : %d) \n",cdtframe->height);
        scanf(" %d",&row);
    }

    for (int i=0 ; i<cdtframe->width ; i++){
        printf("Saisir la valeur en [%d ; %d] \n", row, i);
        scanf(" %d",&val);
        insert_value_in_col((cdtframe->tab)[i],val,row);
    }
    (cdtframe->height)++;
}

/**
* @brief: allows you to rename a column in Cdataframe
* @param1: Pointer to the CDataframe.
* @return: modification of CDataframe no need to return something
*/
void rename_cdataframe_column(CDATAFRAME* cdtframe){
    char title[100];
    int column=-1;
    if(cdtframe->width==0){
        printf("Cdataframe vide \n");
        return;
    }
    while(column<0 || column>=cdtframe->width){
        printf("Quelle colonne voulez-vous renommer ? (colonne max : %d) \n",cdtframe->width-1);
        scanf(" %d",&column);
    }
    rename_column((cdtframe->tab)[column]);
}

/**
* @brief: allows you to print the name of a column in Cdataframe
* @param1: Pointer to the CDataframe.
* @return: printing the value so no need to return something
*/
void print_cdataframe_column_name(CDATAFRAME* cdtframe){
    int column=-1;
    if(cdtframe->width==0){
        printf("Cdataframe vide \n");
        return;
    }
    while(column<0 || column>=cdtframe->width){
        printf("Voulez-vous afficher le nom de quelle colonne ? (colonne max : %d) \n",cdtframe->width-1);
        scanf(" %d",&column);
    }
    printf("Le nom de la colonne %d est %s \n",column,(cdtframe->tab)[column]->titre);
}

/**
* @brief: allows you to print the name of all columns in Cdataframe
* @param1: Pointer to the CDataframe.
* @return: printing the value so no need to return something
*/
void print_full_cdataframe_titles(CDATAFRAME* cdtframe){
    printf("Les noms des colonnes du cdataframe sont :");
    for (int i=0 ; i<cdtframe->width ; i++){
        printf(" [%d] %s \n",i,(cdtframe->tab)[i]->titre);
    }
}

/**
* @brief: allows you to choose which modification/add to make in the Dataframe
* @param1: Pointer to the CDataframe.
* @return: modification of CDataframe no need to return something
*/
void cdataframe_menu(CDATAFRAME* cdtframe) {
    int choice = -1;
    while (choice != 6) {
        printf("\nMenu principal du CDATAFRAME : \n");
        printf("Que voulez-vous faire ? \n"
               " 1) Modifier/Ajouter une unique colonne (fonction inachevee) \n"
               " 2) Remplir le CDATAFRAME en dur \n"
               " 3) Modifier les lignes/colonnes du CDATAFRAME \n"
               " 4) Acceder aux fonctions d'affichage du CDATAFRAME \n"
               " 5) Acceder aux fonctions d'analyse et statistiques du CDATAFRAME \n"
               " 6) Sortir/Retourner en arriere \n");
        scanf(" %d", &choice);
        switch (choice) {
            case 1 : {
                unique_column_choice(cdtframe);
                break;
            }
            case 2 : {
                fill_CDataframe(cdtframe);
                break;
            }
            case 3 : {
                modif_cdataframe_menu(cdtframe);
                break;
            }
            case 4 : {
                display_cdataframe_menu(cdtframe);
                break;
            }
            case 5 : {
                additionnal_cdataframe_functions_menu(cdtframe);
                break;
            }
        }
    }
}

/**
* @brief: allows you to choose which Dataframe information to print
* @param1: Pointer to the CDataframe.
* @return: printing the value so no need to return something
*/
void display_cdataframe_menu(CDATAFRAME *cdtframe) {
        int choice = -1;
        while (choice != 6) {
            printf("\nMenu d'affichage du CDATAFRAME : \n");
            printf("Que voulez-vous faire ? \n"
                   " 1) Afficher le CDATAFRAME en entier \n"
                   " 2) Afficher jusqu'a une certaine ligne du CDATAFRAME \n"
                   " 3) Afficher jusqu'a une certaine colonne du CDATAFRAME \n"
                   " 4) Afficher le nom d'une colonne \n"
                   " 5) Afficher le nom de l'ensemble des colonnes \n"
                   " 6) Sortir/Retourner en arriere \n");
            scanf(" %d", &choice);
            switch (choice) {
                case 1 : {
                    display_full_CDataframe(cdtframe);
                    break;
                }
                case 2 : {
                    int row = -1;
                    while (row < 0 || row >= cdtframe->height) {
                        printf("Jusqu'a quelle ligne voulez-vous afficher ? (ligne max : %d) \n", cdtframe->height - 1);
                        scanf(" %d", &row);
                    }
                    display_partial_rows(cdtframe, row);
                    break;
                }
                case 3 : {
                    int column = -1;
                    while (column < 0 || column >= cdtframe->width) {
                        printf("Jusqu'a quelle colonne voulez-vous afficher ? (colonne max : %d) \n",
                               cdtframe->width - 1);
                        scanf(" %d", &column);
                    }
                    display_partial_columns(cdtframe, column);
                    break;
                }
                case 4 : {
                    print_cdataframe_column_name(cdtframe);
                    break;
                }
                case 5 : {
                    print_full_cdataframe_titles(cdtframe);
                    break;
                }
            }
        }
    }

/**
* @brief: allows you to choose which modification to make in the Dataframe, he must be not empty
* @param1: Pointer to the CDataframe.
* @return: modification of CDataframe no need to return something
*/
void modif_cdataframe_menu(CDATAFRAME *cdtframe) {
        if (cdtframe->width==0){
            printf("Erreur, le cdataframe est vide, vous ne pouvez pas acceder à ce menu \n");
            return;
        }
        int choice = -1;
        while (choice != 5) {
            printf("\nMenu de modification du CDATAFRAME : \n");
            printf("Que voulez-vous faire ? \n"
                   " 1) Ajouter une ligne au CDATAFRAME \n"
                   " 2) Supprimer une ligne au CDATAFRAME \n"
                   " 3) Supprimer une colonne au CDATAFRAME \n"
                   " 4) Supprimer plusieurs colonnes du CDATAFRAME \n"
                   " 5) Sortir/Retourner en arriere \n");
            scanf(" %d", &choice);
            switch (choice) {
                case 1 : {
                    append_row_in_cdataframe(cdtframe);
                    break;
                }
                case 2 : {
                    int row = -1;
                    while (row < 0 || row >= cdtframe->height) {
                        printf("Quelle ligne voulez-vous supprimer ? (ligne max : %d) \n", cdtframe->height - 1);
                        scanf(" %d", &row);
                    }
                    delete_row_from_CDataframe(cdtframe, row);
                    break;
                }
                case 3 : {
                    int column = -1;
                    while (column < 0 || column >= cdtframe->width) {
                        printf("Quelle colonne voulez-vous supprimer ? (colonne max : %d) \n", cdtframe->width - 1);
                        scanf(" %d", &column);
                    }
                    delete_column_from_CDataframe(cdtframe, column);
                    break;
                }
                case 4 : {
                    delete_multiple_columns(cdtframe);
                    break;
                }
            }
        }
    }
/**
* @brief: allows you to choose which information you want to know in the Dataframe
* @param1: Pointer to the CDataframe.
* @return: printing the value so no need to return something
*/
void additionnal_cdataframe_functions_menu(CDATAFRAME *cdtframe) {
        int choice = -1, val = 0;
        while (choice != 5) {
            printf("\nMenu des fonctions d'Analyse du CDATAFRAME : \n");
            printf("Que voulez-vous faire ? \n"
                   " 1) Savoir si une valeur est presente dans le CDATAFRAME \n"
                   " 2) Savoir le nombre d'occurences d'une valeur \n"
                   " 3) Savoir le nombre de valeurs plus grandes qu'une valeur \n"
                   " 4) Savoir le nombre de valeurs plus petites qu'une valeur  \n"
                   " 5) Sortir/Retourner en arriere \n");
            scanf(" %d", &choice);
            switch (choice) {
                case 1 : {
                    check_value_existence_in_CDataframe(cdtframe);
                    break;
                }
                case 2 : {
                    printf("Saisir la valeur \n");
                    scanf(" %d", &val);
                    printf("Le nombre d'occurences de la valeur %d est %d",val,count_occurrences_in_cdataframe(cdtframe, val));
                    break;
                }
                case 3 : {
                    printf("Saisir la valeur \n");
                    scanf(" %d", &val);
                    printf("Le nombre de valeur plus grandes que %d est %d",val,count_greater_in_cdataframe(cdtframe, val));
                    break;
                }
                case 4 : {
                    printf("Saisir la valeur \n");
                    scanf(" %d", &val);
                    printf("Le nombre de valeur plus petites que %d est %d",val,count_lower_in_cdataframe(cdtframe, val));
                    break;
                }
            }
        }
    }

void check_value_existence_in_CDataframe(CDATAFRAME* cdtframe){
    int val=0;
    printf("Saisir la valeur que vous voulez rechercher : \n");
    scanf(" %d",&val);
    if(count_occurrences_in_cdataframe(cdtframe,val)!=0){
        printf("La valeur %d est presente dans le CDATAFRAME \n",val);
    }
    else{
        printf("La valeur %d n'est pas presente dans le CDATAFRAME \n",val);
    }
}