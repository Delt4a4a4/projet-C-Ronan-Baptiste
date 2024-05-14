//
// Created by Baptiste BERTRAND on 14/05/2024.
//

#ifndef PROJET_C_RONAN_BAPTISTE_CDATAFRAMELS_H
#define PROJET_C_RONAN_BAPTISTE_CDATAFRAMELS_H

typedef struct maillon {
    struct maillon * succ;
    COLUMN* col;
} MAILLON;

typedef struct CDATAFRAMELS {
    MAILLON* maillon;
    int width;
}CDATAFRAMELS;

MAILLON* create_maillon();






#endif //PROJET_C_RONAN_BAPTISTE_CDATAFRAMELS_H
