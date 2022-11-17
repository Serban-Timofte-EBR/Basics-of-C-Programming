c#include <stdio.h>
#include <stdlib.h>

/*
    Sortarea cu metoda selectiei pe linii
*/

int main()
{
    float mat[10][20], aux;
    int i, j, m, n;


    printf("Dati dimensiunile matricii:\n");
    scanf("%d %d", &m, &n);

    for(i=0; i<m; i++)                          //citire elementelor din matrice
    {
        for(j=0; j<n;j++)
        {
            printf("mat[%d][%d]=", i, j);
            scanf("%f", &mat[i][j]);
        }
    }


    for(i=0; i<m; i++)
    {
        for(j=0; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(mat[i][j] > mat[i][k])
                {
                    aux = mat[j][k];
                    mat[j][k] = mat[j][k+1];
                    mat[j][k+1] = aux;
                }
            }

        }
    }


    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            printf("%6.2f ", mat[i][j]); //se citesc 6 cifre inainte de virgula si 2 dupa virgula
        printf("\n");
    }

    return 0;
}
