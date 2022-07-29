/*
***************************************************************************************
** étant difficile voir quasi impossible de définir des tableaux
*multidimensionnels  **
** en C nous utiliseront des structures comme moyen cachés de définir des
*tableaux   **
** multidimensionnel **
***************************************************************************************
*/

#include "matrix.h"
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ÉTABLISSEMENT DU SYSTEME MATRICIEL DE BASE  ( la boite noire )
################################################################################################

/**
 * trp - transposer de matrice
 * @matrice: la matrice de base
 * Return: matrice
 **/
matrix trp(matrix matrice) {

  _Tab_ elt = (_Tab_)malloc(sizeof(Tab));
  elt = matrice.start;

  _Tab_ current = (_Tab_)malloc(sizeof(Tab));

  matrix m;
  m.countX = matrice.countX;
  m.countY = matrice.countY;

  int i = 0, j = 0, k = 0;
  while (k < m.count) {

    while (elt->next != NULL) {

      current->ref.i = i;
      current->ref.j = j;

      if (elt->ref.i == j && elt->ref.j == i) {
        current->data = elt->data;
        insert(&m, current);
      }
      elt = elt->next;
      j++;
      if (j == m.countY)
        j = 0;
    }
    i++;
    k++;
    if (i == m.countX)
      i = 0;
  }
  free(elt);
  free(current);
  return m;
}

/**
 * det - determinant d'une matrice
 * @matrice: la matrice de base
 * Return: double number
 **/
double det(matrix matrice) {

  if (matrice.count == 4)
    return deter(matrice);
  else {

    _Tab_ elt = (_Tab_)malloc(sizeof(Tab));
    elt = matrice.start;

    double delta = 0;

    while (elt->ref.j != matrice.countY) {

      delta += elt->data * pow(-1, elt->ref.i + elt->ref.j) *
               det(screen(matrice, elt->ref.i, elt->ref.j));

      elt = elt->next;
    }
    free(elt);
    return delta;
  }
}

/**
 * coma - co-matrice
 * @matrice: la matrice de base
 * Return: matrice
 **/
matrix coma(matrix matrice) {

  matrix m;

  _Tab_ elt = (_Tab_)malloc(sizeof(Tab));
  elt = matrice.start;

  _Tab_ current = (_Tab_)malloc(sizeof(Tab));

  while (elt->next != NULL) {

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

/**
 * rev - inverse d'une matrice
 * @matrice: la matrice de base
 * Return: matrix
 **/
matrix rev(matrix matrice) {
  if (det(matrice) == 0)
    return Init();
  else
    return scalar(trp(coma(matrice)), 1 / det(matrice), all);
}

/**
 * por - elevation a la puissance
 * @matrice: la matrice de base
 * @n: facteur de puissance
 **/
matrix por(matrix matrice, double n) {
  matrix m, p = copy(m);
  /*
   afin de ne pas fais des carrée de 2 alors cela fais m multiplier par le m
   originel et non le m actuel qui est deja issu d'un precedent produit
   */
  while (n > 0) {
    m = mul(m, p);
    n--;
  }
  return m;
}

/**
 * sym - détecte le genre d'une matrice
 * Description: -1 antisymétrique, 1 symétrique sinon 0
 * @matrice: la matrice de base
 **/
int sym(matrix matrice) { return equal(matrice, matrice); }

/**
 * sys - resolution d'equation matriciel
 * @matrice: matrice du systeme d'equation
 * @tab: second membre
 * Return: matrice ligne de b0 à bn
 **/
matrix sys(matrix matrice, matrix tab) {

  matrix eq = copy(matrice), snd = copy(tab);
  // la matrice tab devra être une matrice 1×n d'ou la trp(tab) est n×1
  if (matrice.countX != tab.count) {

    if (matrice.countX > tab.count) {
      // si la matrice tab est de type 1×n
      if (tab.countY > 1)
        snd = resize(tab, matrice.countX, 0);
      else // si la matrice tab est de type n×1
        snd = resize(tab, matrice.countX, 1);
    } else
      eq = resize(matrice, tab.count, 1);
  }

  _Tab_ elt = (_Tab_)malloc(sizeof(Tab));
  elt = eq.start;

  _Tab_ current = (_Tab_)malloc(sizeof(Tab));
  current = snd.start;

  int i = 0, j = 0, p = 0, k = 0;
  while (k < tab.count - 1) {

    i = k + 1;
    while (i < tab.count - 1) {

      while (elt->next != NULL) {

        if (j <= k && elt->ref.j == j)
          elt->data = 0;
        else {
          if (elt->ref.i == i) {
            elt->data -= verify(&eq, i, j)->data * verify(&eq, k, j)->data /
                         verify(&eq, k, k)->data;
          }
        }
        elt = elt->next;
        j++;
      }
      while (current->next != NULL) {

        if (current->ref.i == i)
          current->data -= verify(&eq, i, p)->data * verify(&eq, k, p)->data /
                           verify(&eq, k, k)->data;

        current = current->next;
        p++;
      }
      i++;
    }
    k++;
  }
  current->data = verify(&snd, snd.count - 1, 0)->data /
                  verify(&eq, eq.countX - 1, eq.countY - 1)->data;

  current = current->prev;
  double b = 0;

  for (i = snd.count - 2; i >= 0; i--) {

    for (j = snd.count - 1; j > i; j--) {
      b += verify(&eq, i, j)->data * verify(&snd, i, 0)->data;
    }
    current->data -= b / verify(&eq, i, i)->data;
    current = current->prev;
  }
  free(elt);
  free(current);
  return snd;
}