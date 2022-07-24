# BIBLIOTHÈQUE MATRICE EN C

Le **C** reste un puissance langage de programmation et le pere mérité de plusieurs et de ce fait nous a Anthanasia avions pris sur nous le désir de l’explorer pendant un moment qui certainement nous sera bénéfique et dans cette mesure nous livrons a tous la bibliothèque Matrix implémentant un nombre conséquent des capacités d'une matrice et a la mesure de nos connaissances actuel.

## Contributeur

je commence ce grand voyage seul avec espoir de croisé sur mon chemin des personnes désirant offrir au monde leur connaissances

**Victor Dol.** alias  _hydromel Fondateur d'Anthanasia

## Concept

les matrices que nous concevrons seront généralisé au type pouvant exister dans une matrice a savoir:
- Integer
- Double
- Float
- Complex

nous implémenteront au fur et a mesure de nombreux concepts tel que:

### Sommes de matrice

Somme de matrice: A[i][j]+B[i][j]<br> 
si les matrices sont de taille différentes elle seront dimensionner sur les tailles i×j les plus grande en dupliquant au maximum dans la direction de la longueur a atteindre ie: <br>
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

### Trace d'une matrice

    Trace = somme(aij)

### Identité matriciel

comment amener un programme a reconnaître une matrice selon quel est soit:
- Diagonale
- Triangulaire Supérieur
- Triangulaire Inférieur
- Symétrique
- Antisymétrique

### Determinant de matrice

### Puissance d'une matrice

### Equation matriciel
