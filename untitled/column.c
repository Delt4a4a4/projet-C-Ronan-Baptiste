//
// Created by Baptiste BERTRAND on 21/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "column.h"
/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN* create_column(char* title){
    COLUMN* colonne= malloc(sizeof(COLUMN));
    colonne->titre=title;
    colonne->tab=NULL;
    colonne->tl=0;
    colonne->tp=0;
    return colonne;
}

/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN* col, int value){
    int* p=NULL;
    if (col->tp==0){
        p=malloc(sizeof(int)*256);
        if(p==NULL){
            return 0;
        }
        col->tab=p;
        col->tp=256;
        col->tab[0]=value;
        col->tl=1;
        return 1;

    }
    if (col->tl%256==0) {
        p=realloc(col->tab,sizeof(int)*((col->tl)+256));
        if(p==NULL){
            return 0;
        }
        col->tab=p;
        col->tl=(col->tl)+256;

    }
    col->tab[col->tl]=value;
    col->tl++;
    return 1;
}

/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
*/
void delete_column(COLUMN** col){
    free((*col)->tab);
    free(*col);
}

/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN* col){
    for (int i=0; i<col->tl ; i++){
        printf("[%d] %d\n",i,(col->tab)[i]);
    }
}

/**
* @brief: Returns the number of occurrences of value x in a column.
* @param1: Pointer to a column
* @param2 : Value x to count occurrences of
* @return: Number of occurrences of value x
*/
int count_occurrences(COLUMN* col, int value){
    int occ=0;
    for (int i=0; i<col->tl ; i++){
        if ((col->tab)[i]==value){
            occ++;
        }
    }
    return occ;
}

/**
* @brief: Returns the value at position x in a column.
* @param1: Pointer to a column
* @param2: Position x
* @return: Value at position x
*/
int get_value(COLUMN* col, int position){
    if (col->tl<position){
        printf("Error! No value is assigned to this position");
        return 0;
    }
    return col->tab[position];
}

/**
* @brief: Returns the number of values greater than x in a column.
* @param1: Pointer to a column
* @param2: Value x to compare against
* @return: Number of values greater than x
*/
int count_greater(COLUMN* col, int value){
    int occ=0;
    for (int i=0; i<col->tl ; i++){
        if ((col->tab)[i]>value){
            occ++;
        }
    }
    return occ;
}

/**
* @brief: Returns the number of values less than x in a column.
* @param1: Pointer to a column
* @param2: Value x to compare against
* @return: Number of values less than x
*/
int count_lower(COLUMN* col, int value){
    int occ=0;
    for (int i=0; i<col->tl ; i++){
        if ((col->tab)[i]<value){
            occ++;
        }
    }
    return occ;
}