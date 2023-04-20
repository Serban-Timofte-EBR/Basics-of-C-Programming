//Determinati produsul scalare a doi vectori de dimensiune n.
//Metoda descompunerii
//Metoda reducerii
#include <stdio.h>

//a) Descompunere

float prodScal1(float x[], float y[], int ls, int ld)
{
    float s; //produsul scalar

    if(ls==ld)
        s=x[ls]*y[ls];
    else
    {
        int m=(ls+ld)/2;
        s=prodScal1(x, y, ls, m)+prodScal1(x, y, m+1, ld);
    }

    return s;
}

//b) Reducere

float prodScal2(float x[], float y[], int n)
{
    // cazul de baza
    if (n == 0) {
        return 0;
    }
    // apel recursiv
    return (x[n-1] * y[n-1]) + prodScal2(x, y, n-1);
}

int main() {
    float x[10], y[10];
    int n, i, s;

    printf("\nDimensiunea vectorilor: ");
    scanf("%d", &n);

    printf("\nElementele vectorului x: ");
    for(i=0;i<n;i++)
    {
        printf("\nx[%d] = ", i);
        scanf("%f", &x[i]);
    }

    printf("\nElementele vectorului y: ");
    for(i=0;i<n;i++)
    {
        printf("\ny[%d] = ", i);
        scanf("%f", &y[i]);
    }

    //a) Descompunere

    s = prodScal1(x, y, 0, n-1);
    printf("\nProdusul scalar prin metoda descompunerii a celor doi vectori este: %d", s);

    //b) Reducere

    s = prodScal2(x, y, n);
    printf("\nProdusul scalar prin metoda reducerii a celor doi vectori este: %d", s);

    return 0;
}
