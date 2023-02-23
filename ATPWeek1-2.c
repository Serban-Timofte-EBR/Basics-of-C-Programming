/* Subprogramul C care:
 * - aloca dinamic memoria pt vector
 * - citeste un vector
 * - afiseaza un vector
*/

#include <stdio.h>
#include "mm_malloc.h"

int* alocareV(int m)
{
    int* p;
    p = (int*)malloc(m*sizeof(int));
    return p;
}

void citireV(int* v, int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("v[%d]= ", i);
        scanf("%d", &v[i]);
    }
}

void afisareV(int* v, int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("%d\t", v[i]);
    }
}


int main() {

    int* v;
    int m;

    printf("Citeste dimensiunea vectorului!\n");
    scanf("%d", &m);

    v = alocareV(m);

    printf("Elementele vectorului: ");
    citireV(v, m);

    printf("Vectorul: ");
    afisareV(v, m);

    free(v);
    return 0;
}
