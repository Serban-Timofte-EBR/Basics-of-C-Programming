/*
    Sortare vector prin metoda selectiei in subprogram
 */

#include <stdio.h>

// IN: v[], m
// OUT: v[]

void sortareSelectieVector(int v[10], int m)
{
    int i,j,aux;

    for(i=0;i<m-1;i++)
    {
        for(j=i+1; j<m;j++)
        {
            if(v[i]>v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {

    int v[10], m, i;

    printf("Citeste dimensiunea vectorului!\n");
    scanf("%d", &m);

    printf("Elementele vectorului: ");
    for(i=0;i<m;i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    sortareSelectieVector(v, m);

    for(i=0; i<m;i++)
    {
        printf("%d", v[i]);
        printf(", ");
    }


    return 0;
}
