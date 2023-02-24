/* Subprogramul C care:
 * - inmultire scalar cu matrice
 * - valoarea scal este citita in subprogram
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

void inmultireMcuScalar(int** mat, int m, int n, int *scal)
{
    int i,j;
    printf("Valoarea sacalarului");
    scanf("%d", *scal);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            mat[i][j] = (*scal) * mat[i][j];
        }
    }
}

int main() {

    int m,n;
    int scal;
    int** mat;
    int** newMat;

    printf("Dimens: ");
    scanf("%d %d", &m, &n);
    printf("\n");

    mat = alocareM(m, n);
    citireM(mat, m, n);
    afisareM(mat, m, n);

    inmultireMcuScalar(mat, m, n, &scal);
    printf("Inmultirea s-a petrecut\n");
    afisareM(mat, m, n);
    printf("Afisarea s-a petrecut\n");
    dezalocareM(mat, m);
    printf("Dezalocarea s-a petrecut\n");

    return 0;
}
