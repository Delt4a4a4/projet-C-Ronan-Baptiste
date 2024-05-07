//
// Created by Baptiste BERTRAND on 17/04/2024.
//
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
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
 *
 *
 *
 * ?????????????????? Reverifier ce qu'il faut exactement faire ??????????????????
*/
void fill_CDataframe(CDATAFRAME* cdtframe){
    cdtframe->width=7;
    cdtframe->height=7;
    for (int i=0 ; i<cdtframe->width ; i++){
        (cdtframe->tab)[i]=create_column("A");
        for (int j=0 ; j < cdtframe->height ; j++){
            insert_value((cdtframe->tab)[i], 1);
        }
    }
}



/**
* @brief: Display the entire CDataframe.
* @param1: Pointer to the CDataframe to be displayed.
*/
void display_full_CDataframe(CDATAFRAME* cdtframe){
    for (int i=0 ; i<cdtframe->height ; i++){
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

void unique_column_choice(CDATAFRAME* cdtframe){
    int n=-1;
    int test=0;
    while(n<0){
        printf("Quel est l'indice de la colonne que vous voulez modifier ?");
        scanf(" %d",&n);
    }
    if(n>cdtframe->width){
        printf("Cet colonne n'existe pas, voulez-vous créer une colonne %d ? \n 1) Oui \n 2) Non",cdtframe->width);
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
}

void Create_Cdataframe_Column(CDATAFRAME* cdtframe){
    COLUMN** p=NULL;
    char name[100];
    printf("Saisir le nom de votre nouvelle colonne \n");
    scanf(" %s",name);
    cdtframe->tab=realloc(cdtframe->tab,sizeof(COLUMN*)*((cdtframe->width)+1));
    (cdtframe->tab)[cdtframe->width]= create_column(name);
    (cdtframe->width)++;
    return;
}