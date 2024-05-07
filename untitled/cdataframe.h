//
// Created by Baptiste BERTRAND on 17/04/2024.
//

#ifndef PROJET_CDATAFRAME_H
#define PROJET_CDATAFRAME_H


#include <stdio.h>
#include <stdlib.h>
#include "column.h"

/**
CDataFrame
*/

typedef struct {
    COLUMN** tab;
    int width;
    int height;
}CDATAFRAME;

CDATAFRAME* create_empty_CDataframe();

void fill_CDataframe(CDATAFRAME* cdtframe);

void display_full_CDataframe(CDATAFRAME* cdtframe);

void display_partial_rows(CDATAFRAME* cdtframe, int limit);

void display_partial_columns(CDATAFRAME* cdtframe, int limit);

void add_row_to_CDataframe(CDATAFRAME* cdtframe);

void delete_row_from_CDataframe(CDATAFRAME* cdtframe, int index);

void add_column_to_CDataframe(CDATAFRAME* cdtframe);

void delete_column_from_CDataframe(CDATAFRAME* cdtframe, int index);

void rename_column_in_CDataframe(CDATAFRAME* cdtframe, int index, char* title);

int check_value_existence_in_CDataframe(CDATAFRAME* cdtframe, int value);

int access_cell_in_CDataframe(CDATAFRAME* cdtframe, int row, int column);

void modify_cell_in_CDataframe(CDATAFRAME* cdtframe, int row, int column);

void display_column_names(CDATAFRAME* cdtframe);

void Create_Cdataframe_Column(CDATAFRAME* cdtframe);

void unique_column_choice(CDATAFRAME* cdtframe);

#endif //PROJET_CDATAFRAME_H




