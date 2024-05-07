//
// Created by Baptiste BERTRAND on 21/04/2024.
//

#ifndef UNTITLED_COLUMN_H
#define UNTITLED_COLUMN_H


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

int insert_value_in_col(COLUMN* col, int value, int pos);

void modify_value(COLUMN* col, int value, int pos);

void delete_value(COLUMN* col, int pos);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int count_occurrences(COLUMN* col, int value);

int get_value(COLUMN* col, int position);

int count_greater(COLUMN* col, int value);

int count_lower(COLUMN* col, int value);

#endif //UNTITLED_COLUMN_H