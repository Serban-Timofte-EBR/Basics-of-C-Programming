#include <stdio.h>
#include <stdlib.h>

/*
    Suma elementelor unei matrici
*/

int main()
{
    float mat[20][30],s;
    int i,j,m,n;

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

    s = 0;

    printf("Suma elementelor este: ");

    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            s = s + mat[i][j];
        }
    }

    printf("%6.2f", s);
    return 0;
}
