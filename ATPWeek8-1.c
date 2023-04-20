//Determinarea numarului de elemente negative intr-un vector
//Metoda descompunerii
//Metoda reducerii

#include <stdio.h>

//a) Descompunere

int nrneg1(float x[], int ls, int ld)
{
    int rez;

    if(ld==ls)
    {
        if(x[ls]<0)
        {
            rez=1;
        }
        else
        {
            rez=0;
        }
    }

    else
    {
        rez = nrneg1(x,ls,(ls+ld)/2) + nrneg1(x,(ls+ld)/2+1,ld);
    }

    return rez;
}

//b) Reducere

int nrneg2(float x[], int n)
{
    int i, rez;

    //conditie de oprire
    if(n==0)
    {
        rez = 0;
    }

    else
    {
        //recursivitate
        rez = nrneg2(x,n-1);
        //conditia de oprire
        if(x[n-1]<0)
        {
            rez++;
        }
    }

    return rez;
}

int main() {
    float x[10];
    int n, i, rez;

    printf("\nDimensiunea vectorului: ");
    scanf("%d", &n);

    printf("\nElementele vectorului: ");
    for(i=0;i<n;i++)
    {
        printf("\nx[%d] = ", i);
        scanf("%f", &x[i]);
    }

    //a) Descompunere
    rez = nrneg1(x,0,n-1);
    printf("\nNumarul de elemente negative prin metoda descompunerii este: %d", rez);

    //b) Reducere
    rez = nrneg2(x,n);
    printf("\nNumarul de elemente negative prin metoda reducerii este: %d", rez);

    return 0;
}
