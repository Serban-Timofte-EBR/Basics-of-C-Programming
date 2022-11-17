#include <stdio.h>
#include <stdlib.h>

/*
    Min, max la nivel de linii si coloane
*/

int main()
{
    float mat[10][20], min, max;
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
        min = mat[i][0];
        max = mat[i][0];

        for(j=0; j<n; j++)
        {
            if(min > mat[i][j]) {min = mat[i][j];}
            if(max < mat[i][j]) {max = mat[i][j];}
        }
        //afisare min si max pt linia i
        printf("\nLinia %d are max = %6.2f si min = %6.2f", i,max,min);
    }


    return 0;
}
