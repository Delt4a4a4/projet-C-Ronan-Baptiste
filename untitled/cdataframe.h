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

void delete_column_from_CDataframe(CDATAFRAME* cdtframe, int pos);

void rename_column_in_CDataframe(CDATAFRAME* cdtframe, int index, char* title);

int check_value_existence_in_CDataframe(CDATAFRAME* cdtframe, int value);

int access_cell_in_CDataframe(CDATAFRAME* cdtframe, int row, int column);

void modify_cell_in_CDataframe(CDATAFRAME* cdtframe, int row, int column);

void display_column_names(CDATAFRAME* cdtframe);

void Create_Cdataframe_Column(CDATAFRAME* cdtframe);

void unique_column_choice(CDATAFRAME* cdtframe);

void delete_multiple_columns(CDATAFRAME* cdtframe);

int count_occurrences_in_cdataframe(CDATAFRAME* cdtframe, int x);

int count_greater_in_cdataframe(CDATAFRAME* cdtframe, int x);

int count_lower_in_cdataframe(CDATAFRAME* cdtframe, int x);

void print_width(CDATAFRAME* cdtframe);

void print_height(CDATAFRAME* cdtframe);

void append_row_in_cdataframe(CDATAFRAME* cdtframe);

void rename_cdataframe_column(CDATAFRAME* cdtframe);

void print_column_name(CDATAFRAME* cdtframe);

void print_cdataframe_column_name(CDATAFRAME* cdtframe);

void print_full_cdataframe_titles(CDATAFRAME* cdtframe);

#endif //PROJET_CDATAFRAME_H




