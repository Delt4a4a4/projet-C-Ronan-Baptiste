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
    cdtframe->tab=malloc(sizeof(COLUMN*));
    cdtframe->width=0;
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
}


/**
* @brief: Display the entire CDataframe.
* @param1: Pointer to the CDataframe to be displayed.
*/
void display_full_CDataframe(CDATAFRAME* cdtframe){
    for (int i=0 ; i<(cdtframe->tab)[0]->tl ; i++){
        for (int j=0 ; j < cdtframe->width ; j++){
            printf(" %d ",(cdtframe->tab)[i]->tab[j]);
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
    for (int i=0 ; i<(cdtframe->tab)[0]->tl ; i++){
        for (int j=0 ; j < limit ; j++){
            printf(" %d ",(cdtframe->tab)[i]->tab[j]);
        }
        printf("\n");
    }
}
void display_partial_rows2(CDATAFRAME* cdtframe, int limit){
    for (int i=0 ; i< limit; i++){
        for (int j=0 ; j < (cdtframe->width) ; j++){
            if (i < (cdtframe->tab)[j]->tl){
            printf(" %d ",(cdtframe->tab)[j]->tab[i]);
        }}
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

