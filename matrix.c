/*
***************************************************************************************
** étant difficile voir quasi impossible de définir des tableaux multidimensionnels  **
** en C nous utiliseront des structures comme moyen cachés de définir des tableaux   **
** multidimensionnel                                                                 **
***************************************************************************************
*/

#include "matrix.h"
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* ÉTABLISSEMENT DU SYSTEME MATRICIEL DE BASE
################################################################################################
*/

/**
* init - fonction désignant un faux dans le vérificateur de contenu verify(fonction)
* description:cette fonction fut créé dans le seul but de renvoyer un indicateur de 
* semblable a false. la plupart des fonctions devant retourner une matrice d'ou le format
* Return: un element de matrice 
**/
_Tab_ init(){
    _Tab_ p = (_Tab_) malloc(sizeof(Tab));
    p->data = 0;
    p->next = NULL;
    p->prev = NULL;
    // il est nécessaire qu'elle soit hors des indice normal
    p->ref.i = -1;
    p->ref.j = -1;
    free(p);
    return p;
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
_Tab_ verify(_Ref_ tab, int i, int j){

    _Tab_ left = (_Tab_) malloc(sizeof(Tab));
    left = tab->start;

    _Tab_ right = (_Tab_) malloc(sizeof(Tab));
    right = tab->end;

    _Tab_ current = (_Tab_) malloc(sizeof(Tab));

    while((left->ref.i != i && left->ref.j != j) || (right->ref.i != i && right->ref.j != j) || 
        (left->next != right && right->prev != left)){

        left = left->next;
        right = right->prev;
    
    }
        
    if(left->ref.i != i || right->ref.i != i){

        free(left);
        free(right);

        return init();

    }else{

        if(left->ref.i == i && left->ref.j == j)
             current = left;

        if(right->ref.i == i && right->ref.j == j)
            current = right;
    }
    free(left);
    free(right);

    return current;
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
        news->prev = NULL;
        tab->start = news;
        tab->end = news;
        tab->count++;
    // insertion en fin de liste
    }else{

        if(tab->count < tab->countX * tab->countY){
            current = tab->end->prev;
            current->next = news;
            news->next = NULL;
            tab->end = news;
            news->prev = current;
            tab->count++;
        }else {
            printf("matrice pleine");
        }
    }
    free(news);
    free(current);
}

/**
* IniT - crée une matrix inutilisable [ valeur faux positif]
* Return:une matrice
**/ 
matrix IniT(){
    matrix p;
    _Tab_ e = init();
    _Tab_ s = e;
    insert(&p, s);
    return p;
}


/** fin du systeme matriciel de base
    FONCTION SUBTILE DE MATRICE
#############################################################################################
**/


/**
* trace - permet de determiner la trace d'une matrice
*
* @matrice: matrice dont la trace sera calculer
*
* Return: un element de type Data
**/
double trace(matrix matrice){

    _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
    elt = matrice.start;

    double tr = 0.0;
    while (elt->next != NULL) {

        if(elt->ref.i == elt->ref.j)
            tr += elt->data;
        elt = elt->next;
    }
    free(elt);
    return tr;
}

/**
* equal - fonction de comparaison de 2 matrice
*
* @matrice_1:
* @matrice_2:
*
* Return: 1 si identique pour tout element, -1 si l'un est le négatif de l'autre, 0 sinon
**/
int equal(matrix matrice_1, matrix matrice_2){

    if(matrice_1.count != matrice_2.count)
        return 0;
    else{

        // parcourt de gauche vers la droite
        _Tab_ eltL = (_Tab_) malloc(sizeof(Tab));
        eltL = matrice_1.start;

        _Tab_ currentL = (_Tab_) malloc(sizeof(Tab));
        currentL = matrice_2.start;

        // parcours de droite vers la gauche
        _Tab_ eltR = (_Tab_) malloc(sizeof(Tab));
        eltR = matrice_1.end;

        _Tab_ currentR = (_Tab_) malloc(sizeof(Tab));
        currentR = matrice_2.end;

        int i = 0, j = 0;
        while((eltL->next != eltR && eltR->prev != eltL) || 
            (currentL->next != currentR && currentR->next != currentL)){

            if(eltL == currentL && eltR == currentR)
                i += 2;
            if(eltL->data == -currentL->data && eltR->data == -currentR->data) 
                j += 2;

            eltL = eltL->next;
            eltR = eltR->prev;

            currentL = currentL->next;
            currentR = currentR->prev;
        }
        free(eltL);
        free(eltR);
        free(currentL);
        free(currentR);

        if(i == matrice_1.count)
            return 1;
        else if(j == matrice_2.count)
            return -1;
        else
            return 0;
    }
}

/**
* dim - définir les dimensions n×m d'un matrice
*
* @row: nombre de ligne
* @col: nombre de colonne
**/
void dim(matrix matrice, int row, int col){
    matrice.countX = row;
    matrice.countY = col;
}

/**
* copy - permet une copy exact de la matrice passer en paramètre
* 
* @matrice: matrice a dupliquer
*
* Return: une matrice identique
**/
matrix copy(matrix matrice){
    _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
    elt = matrice.start;

    matrix m;
    while(elt->next != NULL){
        insert(&m, elt);
        elt = elt->next;
    }
    free(elt);
    return m;
}

/**
*screen - reduction de matrice a la matrice n-1 × m-1
*
*@matrice: la matrice a réduire
*@row: ligne a ôter
*@col: colonne a ôter
*
*Return: une matrice
**/ 
matrix screen(matrix matrice, int row, int col){

    matrix m;
    dim(m,matrice.countX - 1,matrice.countY - 1);

    _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
    elt = matrice.start;
    _Tab_ current = (_Tab_) malloc(sizeof(Tab));

    int i = 0, j = 0;
    while(elt->next != NULL){

        if(elt->ref.i != row || elt->ref.j != col){
            if(elt->ref.i < row)
                current->ref.i = elt->ref.i;
            else
                current->ref.i = elt->ref.i - 1;

            if(elt->ref.j < j)
                current->ref.j = j;
            else
                current->ref.j = elt->ref.j - 1;

            current->data = elt->data;
        }
        elt = elt->next;
    }
    free(elt);
    free(current);
    return m;
}

/**
* deter - determinant d'une matrice 2×2
*
* @matrice:
*
* Return: un double
**/
double deter(matrix matrice){

    return verify(&matrice, 0, 0)->data * verify(&matrice, 1, 1)->data - 
        verify(&matrice, 0, 1)->data * verify(&matrice, 1, 0)->data; 
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
void append(matrix matrice, double data, int i, int j){

    _Tab_ t = (_Tab_) malloc(sizeof(Tab));
    t->data = data;

    if(i != matrice.end->ref.i && j != matrice.end->ref.j){
        t->ref.i = i;
        t->ref.j = j;
    }
    insert(&matrice, t);
    free(t);
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
void add(matrix matrice,  int row, ...){

    va_list collect;
    double elt;
    va_start(collect, row);

    int stop = 0, x = 0, y = 0;

    while (stop != matrice.count){
        elt = va_arg(collect, double);
        _Tab_ news = (_Tab_) malloc(sizeof(Tab));
        y++;
        if(y == matrice.count){
            x++;
            y = 0;
        }
        news->data = elt;
        news->ref.i = x;
        news->ref.j = y;

        insert(&matrice, news);
        stop++;
    }
}

/**
* print - affichage de la matrice
*
* @matrice:
**/
void print(matrix matrice){
    _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
    elt = matrice.start;
    int i = 0;

    while(elt->next != NULL){

        printf("%p", elt);

        if(i == matrice.countY-1){
            i = 0;
            printf("\n");
        }
        elt = elt->next;
        i++;
    }
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
        // matrice qui contiendra element a ajouter
        _Ref_ tab = (_Ref_) malloc(sizeof(matrix));

        // si n est inférieur a la dimension actuel de la matrice a agrandir
        if(sub < matrice.countY){

            int i = 0, j =0;
            _Tab_ current = (_Tab_) malloc(sizeof(Tab));

            while (i < matrice.countX) {

                

                while (j < sub) {
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
                 // pour conserver la ligne de la matrice normal sans perdre a suite initial
                _Tab_ old = (_Tab_) malloc(sizeof(Tab));
                old = elt->next;

                //parcourir les elements a ajouter
                current = tab->start;

                while (current->next != NULL) {

                    elt->next = current;
                    current = current->next;
                }
                elt->next = old;

                /*
                * on libère les elements de parcours afin de les réutiliser mais pas elt car 
                * sont parcours continue
                */
                free(tab);
                free(old);
                i++;
            }
            free(current);
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
                        old = elt->next;
                        elt->next = tab->start;
                    }

                    elt = elt->next;
                    j++;
                }

                while (elt->next != NULL) {
                    elt = elt->next;
                }
                elt->next = old;

                free(old);
                i++;
            }
            
            resize(matrice,matrice.countY - n, 0);
        }

        free(elt);
        free(tab);

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
* @matrice_1:
* @matrice_2:
*
* Return: matrix
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

        cur->data = cur1->data + cur2->data;
        insert(&m, cur);

        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    free(cur);
    free(cur1);
    free(cur2);

    return m;
} 

matrix mul(matrix matrice_1, matrix matrice_2){

    matrix m, m1 = copy(matrice_1), m2 = copy(matrice_2);
   
    if(matrice_1.countY != matrice_2.countX){
    //dimension j de la premiere matrice = a la dimension i de la seconde sinon appel a resize
        if(matrice_1.countY > matrice_2.countX)
            m2 = resize(matrice_2, matrice_1.countY, 1);
        else
            m1 = resize(matrice_1, matrice_2.countX, 0);
    }

    dim(m,m1.countX, m2.countY);

    _Tab_ cur1 =(_Tab_) malloc(sizeof(Tab));

    _Tab_ cur2 =(_Tab_) malloc(sizeof(Tab));
    
    _Tab_ cur =(_Tab_) malloc(sizeof(Tab));

    int i = 0, j = 0;
    while (i < m.count) {

        cur1 = m1.start;
        cur2 = m2.start;

        
        
    }
    
    free(cur1);
    free(cur2);
    free(cur);
    return m;
}

matrix scalar(int k, matrix matrice){

    _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
    elt = matrice.start;

    while (elt->next != NULL) {
        elt->data = k * elt->data;
        elt = elt->next;
    }
    free(elt);
    return matrice;
}

matrix trp(matrix matrice){

    _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
    elt = matrice.start;

    _Tab_ current = (_Tab_) malloc(sizeof(Tab));

    matrix m;
    m.countX = matrice.countX;
    m.countY = matrice.countY;

    int i = 0, j= 0, k = 0;
    while(k < m.count){

        while(elt->next != NULL){

            current->ref.i = i;
            current->ref.j = j;

            if(elt->ref.i == j && elt->ref.j == i){
                current->data = elt->data;
                insert(&m, current);
            }
            elt = elt->next;
            j++;
            if(j == m.countY)
                j = 0;
        }
        i++;
        k++;
        if(i == m.countX)
            i = 0;
    }
    free(elt);
    free(current);
    return m;
}

double det(matrix matrice){

    if(matrice.count == 4)
        return deter(matrice);
    else{

        _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
        elt = matrice.start;

        double delta = 0;

        while(elt->ref.j != matrice.countY){

            delta += elt->data * pow(-1,elt->ref.i+elt->ref.j) * 
                det(screen(matrice, elt->ref.i, elt->ref.j));

            elt = elt->next;
        }
        free(elt);
        return delta;
    }
}

matrix coma(matrix matrice){

    matrix m;

    _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
    elt = matrice.start;

    _Tab_ current = (_Tab_) malloc(sizeof(Tab));

    while(elt->next != NULL){

        current->ref.i = elt->ref.i;
        current->ref.j = elt->ref.j;

        current->data = pow(-1, elt->ref.i + elt->ref.j) * 
            det(screen(matrice, elt->ref.i, elt->ref.j));
        
        insert(&m, current);

        elt = elt->next;
    }
    free(elt);
    free(current);
    return m;
}

matrix rev(matrix matrice){
    if(det(matrice) == 0) return IniT();
    else
        return scalar(1/det(matrice),trp(coma(matrice)));
}

matrix por(matrix matrice, double n){
    matrix m, p = copy(m) ;
    /*
     afin de ne pas fais des carrée de 2 alors cela fais m multiplier par le m originel
     et non le m actuel qui est deja issu d'un precedent produit
     */
    while(n > 0){
        m = mul(m,p);
        n--;
    }
    return m;
}



int sym(matrix matrice){
    return equal(matrice, matrice);
}

matrix sys(matrix matrice, matrix tab){

    // la matrice tab devra être une matrice 1×n d'ou la trp(tab) est n×1
    if(matrice.countX != tab.countY) return IniT();
    else{

        matrix eq = copy(matrice), snd = trp(copy(tab));

        _Tab_ elt = (_Tab_) malloc(sizeof(Tab));
        elt = eq.start;

        _Tab_ current = (_Tab_) malloc(sizeof(Tab));
        current = snd.start;

        int i = 0, j = 0,p = 0, k = 0;
        while(k < tab.countX - 1){

            i = k + 1;
            while(i < tab.countX-1){

                while(elt->next != NULL){
                    if(j <= k && elt->ref.j == j) elt->data = 0;
                    else{
                        if(elt->ref.i == i){
                            elt->data -=  verify(&eq,i,j)->data * 
                            verify(&eq,k,j)->data/verify(&eq,k,k)->data;
                        }
                    }
                    elt = elt->next;
                    j++;
                }
                while(current->next != NULL){
                    if(current->ref.i == i)
                        current->data -= verify(&eq,i,p)->data * 
                            verify(&eq,k,p)->data/verify(&eq,k,k)->data;

                    current = current->next;
                    p++;
                }
                i++;
            }
            k++;
        }
        current->data =  verify(&snd,snd.countX - 1, 0)->data /
         verify(&eq, eq.countX -1, eq.countY - 1)->data;

        for(i = 0; i < eq.countX - 1; i++){
            for(k = i+1; k < eq.countX; k++){
                
            }
        }
    }
}