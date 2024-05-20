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
        printf("Quel est l'indice de la colonne que vous voulez modifier ?");
        scanf(" %d",&n);
    }
    if(n>cdtframe->width){
        printf("Cette colonne n'existe pas, voulez-vous créer une colonne %d ? \n 1) Oui \n 2) Non",cdtframe->width);
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

void delete_multiple_columns(CDATAFRAME* cdtframe){
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


void delete_column_from_CDataframe(CDATAFRAME* cdtframe, int pos){
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

int count_occurrences_in_cdataframe(CDATAFRAME* cdtframe, int x){
    int somme=0;
    for(int i=0 ; i<cdtframe->width ; i++){
        somme+= count_occurrences((cdtframe->tab)[i],x);
    }
    return somme;
}

int count_greater_in_cdataframe(CDATAFRAME* cdtframe, int x){
    int somme=0;
    for(int i=0 ; i<cdtframe->width ; i++){
        somme+= count_greater((cdtframe->tab)[i],x);
    }
    return somme;
}

int count_lower_in_cdataframe(CDATAFRAME* cdtframe, int x){
    int somme=0;
    for(int i=0 ; i<cdtframe->width ; i++){
        somme+= count_lower((cdtframe->tab)[i],x);
    }
    return somme;
}

void print_width(CDATAFRAME* cdtframe){
    printf("Votre cdataframe contient %d colonnes \n",cdtframe->width);
}

void print_height(CDATAFRAME* cdtframe){
    printf("Votre cdataframe contient %d lignes\n", cdtframe->height);
}

void append_row_in_cdataframe(CDATAFRAME* cdtframe){
    int row=-1;
    int val;
    while(row<0 || row>=cdtframe->height){
        printf("Quelle ligne voulez-vous inserer ? (ligne max : %d) \n",cdtframe->height-1);
        scanf(" %d",&row);
    }

    for (int i=0 ; i<cdtframe->width ; i++){
        printf("Saisir la valeur en [%d ; %d] \n", row, i);
        scanf(" %d",&val);
        insert_value_in_col((cdtframe->tab)[i],val,row);
    }
    (cdtframe->height)++;
}

void rename_cdataframe_column(CDATAFRAME* cdtframe){
    char title[100];
    int column=-1;
    if(cdtframe->width==0){
        printf("Cdataframe vide \n");
        return;
    }
    while(column<0 || column>=cdtframe->width){
        printf("Quelle colonne voulez-vous renommer ? (ligne max : %d) \n",cdtframe->height-1);
        scanf(" %d",&column);
    }
    rename_column((cdtframe->tab)[column]);
}

void print_cdataframe_column_name(CDATAFRAME* cdtframe){
    int column=-1;
    if(cdtframe->width==0){
        printf("Cdataframe vide \n");
        return;
    }
    while(column<0 || column>=cdtframe->width){
        printf("Voulez-vous afficher le nom de quelle colonne ? (ligne max : %d) \n",cdtframe->height-1);
        scanf(" %d",&column);
    }
    printf("Le nom de la colonne %d est %s \n",column,(cdtframe->tab)[column]->titre);
}

void print_full_cdataframe_titles(CDATAFRAME* cdtframe){
    printf("Les noms des colonnes du cdataframe sont :");
    for (int i=0 ; i<cdtframe->width ; i++){
        printf(" [%d] %s \n",i,(cdtframe->tab)[i]->titre);
    }
}