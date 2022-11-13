#include <stdio.h>
#include <stdlib.h>

int main()
{
    float mat[10][20]; //declarare matrice
    int i, j, m, n;

    //citire date de intrare

    printf("Dati dimensiunile matricii:\n"); // "\n" new line
    scanf("%d %d", &m, &n); //citesc m, n si in ghilimele pus descriptorul de variabila si &m sugereaza ca memorez in locul de memorie alocat variabilei m

    for(i=0; i<m; i++)                          //citire elementelor din matrice
    {
        for(j=0; j<n;j++)
        {
            printf("mat[%d][%d]=", i, j);
            scanf("%f", &mat[i][j]);
        }
    }

    //afisare

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%6.2f ", mat[i][j]); //se citesc 6 cifre inainte de virgula si 2 dupa virgula
        printf("\n");
    }

    _getch();
    return 0;
}
