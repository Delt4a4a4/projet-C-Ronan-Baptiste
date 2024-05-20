//
// Created by Baptiste BERTRAND on 21/04/2024.
//
/**
* Projet_C_Ronan_Baptiste
* Baptiste BERTRAND / Ronan MYCHALSKI
* Contient les fonctions en lien avec les colonnes.
*/
#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include <string.h>
/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN* create_column(char* title){
    COLUMN* colonne= malloc(sizeof(COLUMN));
    colonne->titre=malloc(sizeof(char)*(strlen(title)+1));
    strcpy(colonne->titre,title);
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
    }
    if (col->tl==col->tp) {
        p=realloc(col->tab,sizeof(int)*((col->tl)+256));
        if(p==NULL){
            printf("Erreur de reallocation \n");
            return 0;
        }
        col->tab=p;
        col->tp=(col->tp)+256;

    }
    col->tab[(col->tl)++]=value;
    return 1;
}

/**
* @brief: Insert a value into the column at the desired position.
* @param1: Pointer to the column.
* @param2: Value to be inserted.
* @param3: Desired position for insertion.
* @return: 1 if the value is inserted successfully, 0 otherwise.
*/
int insert_value_in_col(COLUMN* col, int value, int pos){
    if(pos>col->tl){
        printf("Cette ligne est trop grande donc la valeur %d est ajoutée à la fin de la colonne",value);
        insert_value(col,value);
        return 1;

    }
    if (col->tl==col->tp) {
        int *p = NULL;
        p = (int*) realloc(col->tab, sizeof(int) * ((col->tl) + 256));
        if (p == NULL) {
            printf("Erreur de reallocation \n");
            return 0;
        }
        col->tab = p;
        col->tp = (col->tp) + 256;
    }
    for (int i=(col->tl)-1; i>=pos ; i--){
        (col->tab)[i+1]=(col->tab)[i];
    }
        (col->tab)[pos]=value;
        (col->tl)++;
        return 1;
}

/**
* @brief: Modify the value stored at the specified position in the column to the given value.
* @param1: Pointer to the column.
* @param2: New value.
* @param3: Position where the value is to be modified.
* @return: modification of the column no need to return something
*/
void modify_value(COLUMN* col, int value, int pos){
    if(pos>=col->tl) {
        int test = -1;
        printf("Erreur ligne %d trop grande / taille colonne %d \n", pos, (col->tl));
        while (test != 1 && test != 2) {
            printf("Voulez_vous ajouter cette valeur a la fin de la colonne ? \n 1) Oui 2) Non");
            scanf(" %d", &test);
        }
        if(test==1){
            insert_value(col,value);
        }
        return;
    }
    (col->tab)[pos]=value;
}

/**
* @brief: Delete the value located at the desired position in the column.
* @param1: Pointer to the column.
* @param2: Position of the value to be deleted.
* @return: modification of the column no need to return something
*/
void delete_value(COLUMN* col, int pos){
    if(pos>=col->tl){
        printf("La case que vous tentez de supprimer n'existe pas");
        return;
    }
    for (int i=pos ; i<(col->tl)-1 ; i++ ){
        (col->tab)[i]=(col->tab)[i+1];
    }
    (col->tl)--;
}

/**
* @brief: Fill a column from the last occupied position of the column up to a user-chosen row.
* @param1: Pointer to the column.
* @return: modification of the column no need to return something
*/
void fill_column(COLUMN* col){
    int size=-1;
    int value=0;
    while(size<0){
        printf("Combien de lignes voulez-vous remplir a partir de la ligne %d",col->tl);
        scanf("%d",&size);
    }
    int tl=col->tl;
    for(int i=tl ; i<size+tl ; i++){
        printf("Valeur de la ligne %d \n",i);
        scanf("%d",&value);
        insert_value(col,value);
    }
}

/**
* @brief: Fill a column from a user-chosen start position up to a user-chosen end position and replace existing values.
* @param1: Pointer to the column.
* @return: modification of the column no need to return something
*/
void fill_and_replace_column(COLUMN* col){
    int first_row=-1;
    int last_row=-1;
    int value=0;
    while(first_row<0 || first_row>col->tl){
        printf("A partir de quelle ligne voulez-vous remplir la colonne ?");
        scanf("%d",&first_row);
    }
    while(last_row<first_row ){
        printf("Jusqu'a quelle ligne voulez-vous remplir la colonne (non inclue) ?");
        scanf("%d",&last_row);
    }
    for(int i=first_row ; i<last_row ; i++){
        printf("Valeur de la ligne %d \n",i);
        scanf("%d",&value);
        modify_value(col,value,i);
    }
}


/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
* @return: deleting the column no need to return something
*/
void delete_column(COLUMN** col){
    free((*col)->tab);
    free(*col);
}

/**
* @brief: Print a column content
* @param: Pointer to a column
* @return : display of values thanks to print no need for return
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

/**
* @brief: Allows you to choose the actions you want to perform on the column
* @param1: Pointer to a column
* @return: modification of the column no need to return something
*/
void fill_column_menu(COLUMN* col){
    int choice=-1;
    while(choice!=5){
        printf("\nMenu de remplissage d'une colonne : \n");
        printf("Que voulez-vous faire ? \n "
               "1) remplir la colonne en fixant un debut et une fin et en ecrasant les donnees pre-enregistrees \n "
               "2) Commencer a remplir a la suite des donnees pre-enregistre \n "
               "3) ajouter seulement une valeur a la suite \n "
               "4) modifier une unique cellule \n "
               "5) Sortir/retourner en arriere \n");

        scanf("%d",&choice);
        switch(choice){
            case 1 : {fill_and_replace_column(col); break;}
            case 2 : {fill_column(col); break;}
            case 3 : {  int val=0;
                printf("Quelle valeur voulez-vous insérer ?");
                scanf("%d",&val);
                insert_value(col,val); break;}
            case 4 : {int val=0; int pos=0;
                printf("Quelle position voulez-vous modifier ?");
                scanf("%d",&pos);
                printf("Quelle valeur voulez-vous inserer ?" );
                scanf("%d",&val);
                modify_value(col,val,pos); break;}
                case 5 : {return;}
            default : { printf("Error"); }
        }
    }
}

/**
* @brief:Allows you to choose whether you want to delete one or more cells and at which row if you choose to delete one cell
* @param1: Pointer to a column
* @return: modification of the column no need to return something
*/
void delete_cells_menu(COLUMN* col){
    int choice=-1;
    while(choice!=3){
        printf("\nMenu de suppression dans une colonne : \n");
        printf("Que voulez-vous faire ? \n"
               " 1) supprimer une unique cellule \n"
               " 2) supprimer plusieurs cellules de la colonne \n"
               " 3) Sortir/Retourner en arriere \n");
        scanf(" %d",&choice);
    switch(choice){
        case 1 : {int pos=0;
                    printf("A quelle ligne voulez-vous supprimer une cellule ?");
                    scanf(" %d",&pos);
                    delete_value(col,pos);break;}
        case 2 :{delete_cells_in_column(col); break;}
        case 3 :{return;}
        default : { printf("Error"); }
    }
    }
}

/**
* @brief:Allows you to delete several cells from a certain line to another
* @param1: Pointer to a column
* @return: modification of the column no need to return something
*/
void delete_cells_in_column(COLUMN* col){
    int first_row=-1;
    int last_row=-1;
    int value=0;
    while(first_row<0 || first_row>col->tl){
        printf("A partir de quelle ligne voulez-vous supprimer des cellules ? \n");
        scanf(" %d",&first_row);
    }
    while(last_row<first_row || last_row>col->tl){
        printf("Jusqu'a quelle ligne voulez-vous supprimer des cellules (non inclue) ? \n");
        scanf(" %d",&last_row);
    }
    for(int i=first_row; i<last_row ; i++){
        delete_value(col,first_row);
    }
}

/**
* @brief:Allows you to choose whether you want to modify/fill a cell or delete one or more cells
* @param1: Pointer to a column
* @return: modification of the column no need to return something
*/
void column_menu(COLUMN* col) {
    int choice = -1;
    while (choice != 3) {
        printf("\nMenu general d'une colonne : \n");
        printf("Que voulez-vous faire ? \n"
               " 1) Remplir ou modifier une ou des cellules \n"
               " 2) Supprimer une ou des cellules \n"
               " 3) Sortir/Retourner en arriere \n");
        scanf(" %d", &choice);
        switch (choice) {
            case 1 :{fill_column_menu(col);break;}
            case 2 : {delete_cells_menu(col); break;}
            case 3 : {return;}
            default : {printf("Error");}
        }
    }
}
