//
// Created by Baptiste BERTRAND on 14/05/2024.
//
#include "cdataframeLS.h"
#include <stdio.h>
#include <stdlib.h>
#include "column.h"


CDATAFRAMELS* create_empty_CDataframeLS(){
    CDATAFRAMELS* cdtframe=malloc(sizeof(CDATAFRAMELS));
    cdtframe->maillon=create_maillon();
    cdtframe->width=1;
    return cdtframe;
}

MAILLON* create_maillon(){
    char* title[100];
    printf("Saisir le nom de votre nouvelle colonne \n");
    scanf(" %s",title);
    MAILLON* maillon;
    maillon->col=create_column(title);
    maillon->succ=NULL;
    return maillon;
}

MAILLON* create_cdtframe_maillon(){
    char* title[100];
    printf("Saisir le nom de votre nouvelle colonne \n");
    scanf(" %s",title);
    MAILLON* p=create_maillon(title);
    p->col= create_column(title)
}

void unique_column_choice(CDATAFRAMELS* cdtframe){
    int n=-1;
    int test=0;
    while(n<0){
        printf("Quel est l'indice de la colonne que vous voulez modifier ?");
        scanf(" %d",&n);
    }
    if(n>=cdtframe->width){
        printf("Cette colonne n'existe pas, voulez-vous créer une colonne %d ? \n 1) Oui \n 2) Non",cdtframe->width);
        scanf(" %d",&test);
        if(test==1){
            create_maillon();
            n=(cdtframe->width)-1;
        }
        else{
            return;
        }
    }
    column_menu((cdtframe->tab)[n]);
}

void add_maillon(CDATAFRAMELS*){
    MAILLON* maillon=create_maillon();
    while(CDATAFRAMELS)
    column_menu(maillon->col);

}