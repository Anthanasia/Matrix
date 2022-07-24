# BIBLIOTHÈQUE MATRICE EN C

Le **C** reste un puissance langage de programmation et le pere mérité de plusieurs et de ce fait nous a Anthanasia avions pris sur nous le désir de l’explorer pendant un moment qui certainement nous sera bénéfique et dans cette mesure nous livrons a tous la bibliothèque Matrix implémentant un nombre conséquent des capacités d'une matrice et a la mesure de nos connaissances actuel.

## Contributeur

je commence ce grand voyage seul avec espoir de croisé sur mon chemin des personnes désirant offrir au monde leur connaissances

**Victor Dol.** alias  _hydromel Fondateur d'Anthanasia

## Concept

nous implémenteront au fur et a mesure de nombreux concepts tel que:

### Rendu d'un faux

1 - lorsque vous entrez des données erronée quelque soit la fonction, si elle retourne un element de matrix alors elle vous retournera un faux c'est a dire l"element  de valeur 0 a la position  
x = -1, y = -1  { confere la fonction init() dans le fichier matrix.c -> valeur de retour un struct }

2 - lorsque cette fonction retourne une matrice elle enverra une matrice d'un element le faux
{confere IniT() dans le fichier matrix.c -> valeur deretour un struct}

### Sommes de matrice

Somme de matrice: A[i][j]+B[i][j]

si les matrices sont de taille différentes elle seront dimensionner sur les tailles i×j les plus grande en dupliquant au maximum dans la direction de la longueur a atteindre ie:

A[n][m]+B[m+n][m-k] = A[n+m][m]+B[m+n][(m-k)+k] en complétant les lignes et colonnes manquantes par la matrice elle meme.

<table>
    <th colspan=3>A[n][m]</th>
    <tr>
        <td>1</td>
        <td>2</td>
        <td>3</td>
    </tr>
    <tr>
        <td>4</td>
        <td>5</td>
        <td>6</td>
    </tr>
    <tr>
        <td>7</td>
        <td>8</td>
        <td>9</td>
    </tr>
</table>
                
<table>
    <th colspan=3>B[m+n][m-k]</th>
    <tr>
        <td>1</td>
        <td>2</td>
    </tr>
    <tr>
        <td>3</td>
        <td>4</td>
    </tr>
    <tr>
        <td>5</td>
        <td>6</td>
    </tr>
    <tr>
        <td>7</td>
        <td>8</td>
    </tr>
</table>

<table>
    <th colspan=3>A[n][m]</th>
    <tr>
        <td>1</td>
        <td>2</td>
        <td>3</td>
    </tr>
    <tr>
        <td>4</td>
        <td>5</td>
        <td>6</td>
    </tr>
    <tr>
        <td>7</td>
        <td>8</td>
        <td>9</td>
    </tr>
    <tr>
        <td>1</td>
        <td>2</td>
        <td>3</td>
    </tr>
</table>

<table>
    <th colspan=3>B[m+n][m-k]</th>
    <tr>
        <td>1</td>
        <td>2</td>
        <td>1</td>
    </tr>
    <tr>
        <td>3</td>
        <td>4</td>
        <td>3</td>
    </tr>
    <tr>
        <td>5</td>
        <td>6</td>
        <td>5</td>
    </tr>
    <tr>
        <td>7</td>
        <td>8</td>
        <td>7</td>
    </tr>
</table>

### Produit de matrice

    prod[i][j] = A[i][j] * B[i][j]

### Inverse de matrice

    rev[i][j] = (1/Determinant(A)) * Transpose( Co-matrice(A) )

### Trace d'une matrice - la fonction trace

    Trace = somme(aii) des elements de la diagonale

### Comparaison de matrice - la fonction equal

comparaison element par element, return 1 si les elements sont egaux , -1 s'il sont contraire c'est a dire
le negatif l'un de l'autre et zero sinon

### Definition de la dimension  -  la fonction dim

definis le nombre de ligne et de colonne de la matrice

### Copie de matrice - la fonction copy

crée une copy de la matrice en parametere ( copy profonde )

### Reduction de matrice - fonction screen

reduire une matrice au rang (i - 1)×(j - 1) en otant les elements d'une certaine ligne et colonne

### Determinant d'une matrice  - fonction det

### Ajout element par element a une matrice - fonction append

ajout 'd'un element a la fois, approprié pour une utilisation dans une boucle

### Ajout de masse - fonction add

ajout de plusieurs elements definis l'une a la suite de l'autre

### affichage de matrice - fonction print


### Identité matriciel

comment amener un programme a reconnaître une matrice selon quel est soit:
- Diagonale
- Symétrique
- Antisymétrique

### Determinant de matrice

### Puissance d'une matrice

### Equation matriciel
