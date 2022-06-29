<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <div class=menu>
            <h2>Menu</h2>
            <a href=#préambule class=lien><div class=liens>Préambule</div></a>
            <a href=#contrib class=lien><div class=liens>Contributeur</div></a>
            <div>
                <h3>Concept</h3>
                <a href=#sum class=lien><div class=liens>Sommes</div></a>
                <a href=#product class=lien><div class=liens>Produits</div></a>
                <a href=#reverse class=lien><div class=liens>Inverse</div></a>
                <a href=#trace class=lien><div class=liens>Trace</div></a>
                <a href=#trace class=lien><div class=liens>Identité</div></a>
                <a href=#deter class=lien><div class=liens>Determinant</div></a>
                <a href=#power class=lien><div class=liens>Puissance</div></a>
                <a href=#equat class=lien><div class=liens>Equation</div></a>
            </div>
        </div>
        <div class=body>
            <div id=préambule>
                <h1>BIBLIOTHÈQUE MATRICE EN C</h1>
                <div>
                    Le <strong>C</strong> reste un puissance langage de programmation et le pere mérité de plusieurs et de ce fait nous a Anthanasia avions pris sur nous le désir de l’explorer pendant un moment qui certainement nous sera bénéfique et dans cette mesure nous livrons a tous la bibliothèque Matrix implémentant un nombre conséquent des capacités d'une matrice et a la mesure de nos connaissances actuel.
                </div>
            </div>
            <div id=contrib>
                <h2 class=title>Contributeur</h2>
                <div>
                    je commence ce grand voyage seul avec espoir de croisé sur mon chemin des personnes désirant offrir au monde leur connaissances
                    <div><strong>Victor Dol. alias _hydromel</strong> Fondateur d'Anthanasia</div>
                </div>
            </div>
            <div>
                <h2 class=title>Concept</h2>
                <p>
                    les matrices que nous concevrons seront généralisé au type pouvant exister dans une matrice a savoir:
                    <ul>
                        <li>Integer</li>
                        <li>Double</li>
                        <li>Float</li>
                        <li>Complex</li>
                    </ul>
                    nous implémenteront au fur et a mesure de nombreux concepts tel que:
                </p>
                <div id=sum>
                    <h3 class=implement>Sommes de matrice</h3>
                    <div>
                        <p>
                            Somme de matrice: A[i][j]+B[i][j]<br> 
                            si les matrice sont de tailles différentes elle seront dimensionner sur les tailles i×j les plus grande en dupliquant au maximum dans la direction de la longueur a atteindre ie: <br>
                            A[n][m]+B[m+n][m-k] = A[n+m][m]+B[m+n][(m-k)+k] en complétant les lignes et colonnes manquantes par la matrice elle meme
                        </p>
                        <div class=over>
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
                    </div>
                    <div>
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
                    </div>
                    <div class=over>
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
                    </div>
                    <div>
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
                    </div>
                </div><br>
                <div id=product>
                    <h3 class=implement>Produit de matrice</h3>
                    prod[i][j] = A[i][j] * B[i][j]
                </div><br>
                <div id=reverse>
                    <h3 class=implement>Inverse de matrice</h3>
                    rev[i][j] = (1/Determinant(A)) * Transpose( Co-matrice(A) )
                </div><br>
                <div id=trace>
                    <h3 class=implement>Trace d'une matrice</h3>
                    trace = somme(aij)
                </div>
                <div id=trace>
                    <h3 class=implement>Identité matriciel</h3>
                    comment amener un programme a reconnaître une matrice selon quel est soit:<br>
                    - Diagonale<br>
                    - Triangulaire Supérieur<br>
                    - Triangulaire Inférieur<br>
                    - Symétrique<br>
                    - Antisymétrique<br>
                </div>
                <div id=deter>
                    <h3 class=implement>Determinant de matrice</h3>
                </div>
                <div id=power>
                    <h3 class=implement>Puissance d'une matrice</h3>
                </div>
                <div id=equat>
                    <h3 class=implement>Equation matriciel</h3>
                </div>
            </div>
        </div>
    </body>
</html>