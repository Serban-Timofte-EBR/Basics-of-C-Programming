#include <stdio.h>
#include <stdlib.h>

/*
    Suma pe linii si stocarea valorilor intr-un vector
*/

int main()
{
    float mat[10][20], sum[10], s;
    int i,j,m,n;

    printf("Dati dimensiunile matricii:\n");
    scanf("%d %d", &m, &n);


    for(i=0; i<m; i++)
    {
        for(j=0; j<n;j++)
        {
            printf("mat[%d][%d]=", i, j);
            scanf("%f", &mat[i][j]);
        }
    }

    s = 0;

    for(i=0;i<m;i++)
    {
        for(int j=0; j<n; j++)
        {
            s = s + mat[i][j];
        }

        sum[i] = s;
        s = 0;
    }

    printf("Suma linilor este: \n");

    for(i=0; i<m; i++)
    {
        printf("%f", sum[i]);
        printf("\n");
    }


    return 0;
}
