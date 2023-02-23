/* Subprogramul C care:
 * - aloca dinamic memoria pt o matrice
 * - citeste o matrice
 * - afiseaza o matrice
*/

#include <stdio.h>
#include "mm_malloc.h"

int** alocareM(int m, int n)
{
    int** t;
    t = (int**)malloc(m*sizeof(int*));
    for(int i=0; i<m; i++)
    {
        t[i] = (int*)malloc(n*sizeof(int));
    }
    return t;
}

//dezalocarea memoriei

void dezalocareM(int** mat, int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        free(mat[i]);
    }

    free(mat);
}

//citire matrice

void citireM(int** mat, int m, int n)
{
    int i,j;
    for(i = 0; i<m;i++)
    {
        for(j=0; j<n;j++)
        {
            printf("mat[%d][%d]= ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

//afisare matrice

void afisareM(int** mat, int m, int n)
{
    int i,j;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}


int main() {

    int m,n;
    int** mat;

    printf("Dimens: ");
    scanf("%d %d", &m, &n);
    printf("\n");

    mat = alocareM(m, n);
    citireM(mat, m, n);
    afisareM(mat, m, n);
    dezalocareM(mat, m);

    return 0;
}
