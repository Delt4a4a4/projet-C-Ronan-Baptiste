//
// Created by Baptiste BERTRAND on 17/04/2024.
//

#ifndef PROJET_CDATAFRAME_H
#define PROJET_CDATAFRAME_H

#endif //PROJET_CDATAFRAME_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* titre;
    int* tab;
    int tl;
    int tp;
}COLUMN;

COLUMN* create_column(char* title);

int insert_value(COLUMN* col, int value);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int count_occurrences(COLUMN* col, int value);

int get_value(COLUMN* col, int position);

int count_greater(COLUMN* col, int value);

int count_lower(COLUMN* col, int value);

/**
CDataFrame
*/

typedef struct {
    COLUMN** tab;
    int tp;
}CDATAFRAME;

CDATAFRAME* create_empty_CDataframe();

void display_full_CDataframe(CDATAFRAME* cdtframe);


