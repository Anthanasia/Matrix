/*
***************************************************************************************
** étant difficile vor quasi impossible de définir des tableaux multidimensionnels   **
** en C nous utiliseront des structures comme moyen cachés de définir des tableaux   **
** multidimensionnel                                                                 **
***************************************************************************************
* count struct 
* définis les indices d'un tableau
*
*/

#include "matrix.h"
#include <stdarg.h>
#include <stdlib.h>


Data nulle = {0};

/**
* init - fonction désignant un faux dans le vérificateur de contenu verify(fonction)
* description:cette fonction fut créé dans le seul but de renvoyer un indicateur de 
* semblable a false. la plupart des fonctions devant retourner une matrice d'ou le format
* Return: un element de matrice 
*/
Tab init(){
    _Tab_ p = (_Tab_) malloc(sizeof(Tab));
    p->data = nulle;
    p->next = NULL;
    // il est nécessaire qu'elle soit hors des indice normal
    p->ref.i = -1;
    p->ref.j = -1;
    return *p;
}

/**
* verify - fonction allant a la recherche de la ressource se trouvant 
* a l'indice i×j et retournant un faux (init()) si absent
*
* @tab: pointeur sur un element de matrix 
* @i: i_eme ligne
* @j: j_eme colonne
*
* Return: un element de matrix
**/
Tab verify(_Ref_ tab, int i, int j){
    _Tab_ current = (_Tab_) malloc(sizeof(Tab));
    current = tab->start;
    while((current->ref.i!=i && current->ref.j!=j) || current->next!=NULL)
        current = current->next;
    if((current->ref.i!=i && current->ref.j!=j)) return init();
    else
        return *current;
}

/**
* insert - fonction d'initialisation et d'ajout d'element a la matrice
*
* @tab: pointeur sur une matrix
* @elt: pointeur sur un element de matrix
*
* Return: @{Ref}
**/
void insert(_Ref_ tab, _Tab_ elt){

    _Tab_ news = (_Tab_) malloc(sizeof(Tab));
    _Tab_ current = (_Tab_) malloc(sizeof(Tab));

    news = elt;
    // insertion dans une liste vide
    if(tab->count < 1){

        news->next = NULL;
        tab->start = news;
        tab->end = news;
        tab->count++;
    // insertion en fin de liste
    }else{

        *current = verify(tab, news->ref.i, news->ref.j);
        current->next = news;
        news->next = NULL;
        tab->end = news;
        tab->count++;
    }
}

/**
* append - ajout element par element
*
* Description: peut s'utiliser avec une boucle pour l'ajout en masse
*
* @matrice: la matrix
* @data: un point de la matrice
* @i: coordonnée du point sur la ligne i
* @j: coordonnée du point sur la colonne j
**/
void append_i(matrix matrice, int data, int i, int j){

    _Tab_ t = (_Tab_) malloc(sizeof(Tab));
    t->data.entier = data;

    if(i != matrice.end->ref.i && j != matrice.end->ref.j){
        t->ref.i = i;
        t->ref.j = j;
    }
    insert(&matrice, t);
}

void append_d(matrix matrice, double data, int i, int j){

    _Tab_ t = (_Tab_) malloc(sizeof(Tab));
    t->data.reel = data;

    if(i != matrice.end->ref.i && j != matrice.end->ref.j){
        t->ref.i = i;
        t->ref.j = j;
    }
    insert(&matrice, t);
}

void append_f(matrix matrice, float data, int i, int j){

    _Tab_ t = (_Tab_) malloc(sizeof(Tab));
    t->data.variant = data;

    if(i != matrice.end->ref.i && j != matrice.end->ref.j){
        t->ref.i = i;
        t->ref.j = j;
    }
    insert(&matrice, t);
}

void append_ic(matrix matrice, complex int data, int i, int j){

    _Tab_ t = (_Tab_) malloc(sizeof(Tab));
    t->data.cmplxI = data;

    if(i != matrice.end->ref.i && j != matrice.end->ref.j){
        t->ref.i = i;
        t->ref.j = j;
    }
    insert(&matrice, t);
}

void append_dc(matrix matrice, complex double data, int i, int j){

    _Tab_ t = (_Tab_) malloc(sizeof(Tab));
    t->data.cmplxD = data;

    if(i != matrice.end->ref.i && j != matrice.end->ref.j){
        t->ref.i = i;
        t->ref.j = j;
    }
    insert(&matrice, t);
}

void append_cf(matrix matrice, complex float data, int i, int j){

    _Tab_ t = (_Tab_) malloc(sizeof(Tab));
    t->data.entier = data;

    if(i != matrice.end->ref.i && j != matrice.end->ref.j){
        t->ref.i = i;
        t->ref.j = j;
    }
    insert(&matrice, t);
}

/***
* IniT - crée une matrix inutilisable [ valeur faux positif]
* Return:une matrice
**/ 
matrix IniT(){
    matrix p, *t;
    Tab e = init();
    _Tab_ s = &e;
    insert(&p, s);
    return p;
}

/**
* add_i - fonction (int) d'initialisation de masse des elements de la matrice
*
* @matrice:
* @ligne: nombre de lignes
* @colonne: nombre de colonnes
* @(...): liste de variables de type homogène int 
*
**/
void add_i(matrix matrice, int ligne, int colonne, ...){

    va_list collect;
    int elt;
    va_start(collect, colonne);
    matrice.countX = ligne;
    matrice.countY = colonne;
    matrice.count = matrice.countX * matrice.countY;
    int stop = 0, x = 0, y = 0;
    
    while (stop != matrice.count)
        elt = va_arg(collect, int);
        _Tab_ news = (_Tab_) malloc(sizeof(Tab));
        y++;
        if(y == matrice.count){
            //fin de ligne passage a une nouvelle 
            x++;
            y = 0;
        }
        news->data.entier = elt;
        news->ref.i = x;
        news->ref.j = y;

        _Ref_ mat = (_Ref_) malloc(sizeof(matrix));
        mat = &matrice;
        insert(mat, news);
        stop++;
}

/**
* add_d - fonction (double) d'initialisation de masse des elements de la matrice
*
* @matrice:
* @ligne: nombre de lignes
* @colonne: nombre de colonnes
* @va_arg: liste de variables de type point d'une matrice _(donnee, ligne, colonne)
*
**/
void add_d(matrix matrice, int ligne, int colonne, ...){

    va_list collect;
    double elt;
    va_start(collect, colonne);
    matrice.countX = ligne;
    matrice.countY = colonne;
    matrice.count = matrice.countX * matrice.countY;
    int stop = 0, x = 0, y = 0;

    while (stop != matrice.count)
        elt = va_arg(collect, double);
        _Tab_ news = (_Tab_) malloc(sizeof(Tab));
        y++;
        if(y == matrice.count){
            x++;
            y = 0;
        }
        news->data.reel = elt;
        news->ref.i = x;
        news->ref.j = y;

        _Ref_ mat = (_Ref_) malloc(sizeof(matrix));
        mat = &matrice;
        insert(mat, news);
        stop++;
}

/**
* add_f - fonction (float) d'initialisation de masse des elements de la matrice
*
* @matrice:
* @ligne: nombre de lignes
* @colonne: nombre de colonnes
* @va_arg: liste de variables de type point d'une matrice _(donnee, ligne, colonne)
*
**/
void add_f(matrix matrice, int ligne, int colonne, ...){

    va_list collect;
    float elt;
    va_start(collect, colonne);
    matrice.countX = ligne;
    matrice.countY = colonne;
    matrice.count = matrice.countX * matrice.countY;
    int stop = 0, x = 0, y = 0;

    while (stop != matrice.count)
        elt = va_arg(collect, double);
        _Tab_ news = (_Tab_) malloc(sizeof(Tab));
        y++;
        if(y == matrice.count){
            x++;
            y = 0;
        }
        news->data.variant =(float)elt;
        news->ref.i = x;
        news->ref.j = y;

        _Ref_ mat = (_Ref_) malloc(sizeof(matrix));
        mat = &matrice;
        insert(mat, news);
        stop++;
}

/**
* add_ic - fonction (complex int) d'initialisation de masse des elements de la matrice
*
* @matrice:
* @ligne: nombre de lignes
* @colonne: nombre de colonnes
* @va_arg: liste de variables de type point d'une matrice _(donnee, ligne, colonne)
*
**/
void add_ic(matrix matrice, int ligne, int colonne, ...){

    va_list collect;
    complex int elt;
    va_start(collect, colonne);
    matrice.countX = ligne;
    matrice.countY = colonne;
    matrice.count = matrice.countX * matrice.countY;
    int stop = 0, x = 0, y = 0;

    while (stop != matrice.count)
        elt = va_arg(collect, complex int);
        _Tab_ news = (_Tab_) malloc(sizeof(Tab));
        y++;
        if(y == matrice.count){
            x++;
            y = 0;
        }
        news->data.cmplxI = elt;
        news->ref.i = x;
        news->ref.j = y;

        _Ref_ mat = (_Ref_) malloc(sizeof(matrix));
        mat = &matrice;
        insert(mat, news);
        stop++;
}

/**
* add_dc - fonction (complex double) d'initialisation de masse des elements de la matrice
*
* @matrice:
* @ligne: nombre de lignes
* @colonne: nombre de colonnes
* @va_arg: liste de variables de type point d'une matrice _(donnee, ligne, colonne)
*
**/
void add_dc(matrix matrice, int ligne, int colonne, ...){

    va_list collect;
    complex double elt;
    va_start(collect, colonne);
    matrice.countX = ligne;
    matrice.countY = colonne;
    matrice.count = matrice.countX * matrice.countY;
    int stop = 0, x = 0, y = 0;

    while (stop != matrice.count)
        elt = va_arg(collect, complex double);
        _Tab_ news = (_Tab_) malloc(sizeof(Tab));
        y++;
        if(y == matrice.count){
            x++;
            y = 0;
        }
        news->data.cmplxD = elt;
        news->ref.i = x;
        news->ref.j = y;

        _Ref_ mat = (_Ref_) malloc(sizeof(matrix));
        mat = &matrice;
        insert(mat, news);
        stop++;
}

/**
*resize - redimensionnement de la matrice pour l'option élargie
*
*@matrice: matrice
*@n: dimension en i ou j et l'autre matrice selon la valeur du boolean
*@boolean: 0 pour élargissement en colonne et 1 pour ligne
*
*Return: matrice
*/
matrix resize(matrix matrice, int n, int boolean){
    // matrice incomplete en colonne
    if(boolean == 0){
        // nombre d'element manquant pour atteindre n
        int sub = n-matrice.countY;
        // element parcourant la matrice
        _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
        elt = matrice.start;
        // la ligne a ajouter
        _Ref_ tab = (_Ref_) malloc(sizeof(matrix));

        // si n est inférieur a la dimension actuel de la matrice a agrandir
        if(sub < matrice.countY){

            int i = 0, j =0;

            while (i < matrice.countX) {

                _Tab_ current = (_Tab_) malloc(sizeof(Tab));

                while (j <= sub) {
                    // on modifie les numero de ligne et colonne
                    current->data = elt->data;
                    current->ref.i = i;
                    current->ref.j = matrice.countY + j;

                    //on crée le chaînage a ajouter
                    insert(tab, current);
                    elt = elt->next;
                    j++;
                }
                free(current);

                // atteindre la fin de la premiere ligne pour ajouter les nouveau element
                while ((elt->ref.i != matrice.countX - 1) && (elt->ref.j != i)){
                    elt = elt->next;
                }
                 // pour conserver la ligne de la matrice normal sans perdre a suite
                _Tab_ old = (_Tab_) malloc(sizeof(Tab));
                old = elt;

                //parcourir les elements a ajouter
                current = tab->start;

                while (current->next != NULL) {

                    elt->next = current;
                    current = current->next;
                }
                elt->next = old->next;

                /*
                * on libère les elements de parcours afin de les réutiliser mais pas elt car 
                * sont parcours continue
                */
                free(tab);
                free(old);
                i++;
            }
        }else {
            // n supérieur a la dimension actuel de la matrice
            int i = 0, j = 0;
            /* 
            * remettre le compteur a zero puisque elt a ete définir en dehors 
            * de la premiere boucle
            */
            free(elt);
            elt = tab->start;

            _Tab_ old = (_Tab_) malloc(sizeof(Tab));
            old = elt;
            while (i < tab->countX) {

                _Tab_ current = (_Tab_) malloc(sizeof(Tab));
                while (j < tab->countY) {
                    // on modifie les numero de ligne et colonne
                    
                    current->data = elt->data;
                    current->ref.i = i;
                    current->ref.j = matrice.countY + j;

                    //on crée le chaînage a ajouter
                    insert(tab, current);
                    /* 
                    * étant donné que le nombre d'elements ajouter est plus grand que la 
                    * dimension il faut intercepter le passage a le ligne suivante avant 
                    * juste a la fin de la boucle
                    */
                    if(elt->next->ref.i == i + 1){
                        // pour conserver la ligne de la matrice normal sans perdre a suite
                        old = elt;
                        elt->next = tab->start;
                    }

                    elt = elt->next;
                    j++;
                }

                while (elt->next != NULL) {
                    elt = elt->next;
                }
                elt->next = old->next;

                free(old);
                i++;
            }
            free(elt);
            free(tab);
            resize(matrice,matrice.countY - n, 0);
        }

    }else {
        //matrice incomplete en ligne

        // nombre d'element manquant pour atteindre n
        int sub = n - matrice.countX;
        // element parcourant la matrice
        _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
        elt = matrice.start;
        // element a ajouter
        _Ref_ tab = (_Ref_) malloc(sizeof(matrix));

        if(sub < matrice.countX){

            int i = 0, j = 0;
            while(i != sub){

                 _Tab_ current = (_Tab_) malloc(sizeof(Tab));

                while(j != matrice.countY){
                    current->data = elt->data;
                    current->ref.i = matrice.countX + i;
                    current->ref.j = elt->ref.j;

                    insert(tab,current);
                    elt = elt->next;
                    j++;
                }

                while (elt->next != NULL) {
                    elt = elt->next;
                }
                elt->next = tab->start;

                while(elt->next != NULL){
                    elt = elt->next;
                }
                free(current);
                free(elt);

                elt = matrice.start;
                // retour a la ligne suivant celle terminer dans la boucle de j
                while(elt->ref.i != i+1){
                    elt = elt->next;
                }
            }
        }else {

            int i = 0, j = 0;
            while(i != matrice.countX){

                 _Tab_ current = (_Tab_) malloc(sizeof(Tab));

                while(j != matrice.countY){
                    current->data = elt->data;
                    current->ref.i = matrice.countX + i;
                    current->ref.j = elt->ref.j;

                    insert(tab,current);
                    elt = elt->next;
                    j++;
                }

                while (elt->next != NULL) {
                    elt = elt->next;
                }
                elt->next = tab->start;

                while(elt->next != NULL){
                    elt = elt->next;
                }
                free(current);
                free(elt);

                elt = matrice.start;
                // retour a la ligne suivant celle terminer dans la boucle de j
                while(elt->ref.i != i+1){
                    elt = elt->next;
                }
            }
            resize(matrice,matrice.countY - n, 1);
        }
        free(elt);
        free(tab);
    }
    return matrice;
}

/**
* sum - sommes de 2 matrice avec option élargie
*
* description: voir /README.md
*
* @t2:
* @t2:
*
* Return: 
**/
matrix sum(matrix matrice_1, matrix matrice_2){

    matrix m1;
    matrix m2;
    matrix m;

    if(matrice_1.countX != matrice_2.countX){
        if(matrice_1.countX > matrice_2.countX)
            m2 = resize(matrice_2, matrice_1.countX, 1);
        else
            m1 = resize(matrice_1, matrice_2.countX, 1);
    }

    if(matrice_1.countY != matrice_2.countY){
        if(matrice_1.countY > matrice_2.countY)
            m2 = resize(matrice_2, matrice_1.countY, 0);
        else
            m1 = resize(matrice_1, matrice_2.countY, 0);
    }

    _Tab_ cur1 =(_Tab_) malloc(sizeof(Tab));
    cur1 = m1.start;

    _Tab_ cur2 =(_Tab_) malloc(sizeof(Tab));
    cur2 = m2.start;

    _Tab_ cur =(_Tab_) malloc(sizeof(Tab));

    while(cur1->next != NULL){

        cur->ref.i = cur1->ref.i;
        cur->ref.j = cur1->ref.j;

        // compatibilité des données -- il doivent être de meme type
        if(cur1->data.entier && cur2->data.entier)
            cur->data.entier = cur1->data.entier + cur2->data.entier;

        if(cur1->data.reel && cur2->data.reel)
            cur->data.reel = cur1->data.reel + cur2->data.reel;

        if(cur1->data.variant && cur2->data.variant)
            cur->data.variant = cur1->data.variant + cur2->data.variant;

        if(cur1->data.cmplxI && cur2->data.cmplxI)
            cur->data.cmplxI = cur1->data.cmplxI + cur2->data.cmplxI;

        if(cur1->data.cmplxD && cur2->data.cmplxD)
            cur->data.cmplxD = cur1->data.cmplxD + cur2->data.cmplxD;

        if(cur1->data.cmplxF && cur2->data.cmplxF)
            cur->data.cmplxF = cur1->data.cmplxF + cur2->data.cmplxF;

        if(cur->data.entier || cur->data.reel || cur->data.variant || 
        cur->data.cmplxD || cur->data.cmplxF || cur->data.cmplxI)
            insert(&m, cur);
        else
            insert(&m, NULL);

        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    free(cur);
    free(cur1);
    free(cur2);
    return m;
} 

matrix mul(matrix matrice_1, matrix matrice_2){

    matrix m, m1, m2;

    if(matrice_1.countY != matrice_2.countX){
        if(matrice_1.countY > matrice_2.countX)
            m2 = resize(matrice_2, matrice_1.countY, 1);
        else
            m1 = resize(matrice_1, matrice_2.countX, 0);
    }

    if(matrice_1.countX != matrice_2.countY){
        if(matrice_1.countX > matrice_2.countY)
            m2 = resize(matrice_2, matrice_1.countX, 0);
        else
            m1 = resize(matrice_1, matrice_2.countY, 1);
    }

    _Tab_ cur1 =(_Tab_) malloc(sizeof(Tab));
    cur1 = matrice_1.start;

    _Tab_ cur2 =(_Tab_) malloc(sizeof(Tab));
    cur2 = matrice_2.start;

    _Tab_ cur =(_Tab_) malloc(sizeof(Tab));

    int i = 0, j = 0;
    while(cur1->next != NULL){

        while(cur2->next != NULL){

            cur->ref.i = i;
            cur->ref.j = j;
            if(cur1->ref.j == j && cur2->ref.j == j){
                
            if(cur1->data.entier && cur2->data.entier)
                cur->data.entier = cur1->data.entier * cur2->data.entier;

            if(cur1->data.reel && cur2->data.reel)
                cur->data.reel = cur1->data.reel * cur2->data.reel;

            if(cur1->data.variant && cur2->data.variant)
                cur->data.variant = cur1->data.variant * cur2->data.variant;

            if(cur1->data.cmplxI && cur2->data.cmplxI)
                cur->data.cmplxI = cur1->data.cmplxI * cur2->data.cmplxI;

            if(cur1->data.cmplxD && cur2->data.cmplxD)
                cur->data.cmplxD = cur1->data.cmplxD * cur2->data.cmplxD;

            if(cur1->data.cmplxF && cur2->data.cmplxF)
                cur->data.cmplxF = cur1->data.cmplxF * cur2->data.cmplxF;

            if(cur->data.entier || cur->data.reel || cur->data.variant || 
                cur->data.cmplxD || cur->data.cmplxF || cur->data.cmplxI)
                insert(&m, cur);
            else
                insert(&m, NULL);

            cur2 = cur2->next;
            j++;
            }
            cur1 = cur1->next;
            i++;
        }
    }
    free(cur1);
    free(cur2);
    free(cur);
    return m;
}

matrix scalar(int k, matrix matrice){

}

matrix trp(matrix matrice){

}

double trce(matrix matrice){

}

double det(matrix matrice){

}

matrix rev(matrix matrice){

}

matrix por(matrix matrice){

}

int sym(matrix matrice){

}

int pos(matrix matrice){

}

matrix diag(matrix matrice){

}

matrix sys(matrix matrice){

}