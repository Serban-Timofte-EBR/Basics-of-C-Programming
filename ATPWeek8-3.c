//Suma elementelor impare ale unui vector cu elemente intregi
//Metoda descompunerii
//Metoda reducerii
#include <stdio.h>

//a) Descompunere

int sumOddDesc(int a[], int ls, int ld)
{
    int rez;

    if(ls==ld)
    {
        if(a[ls] % 2 != 0)
            rez = a[ls];
        else
            rez = 0;
    }
    else
    {
        int m = (ls+ld)/2;
        rez = sumOddDesc(a, ls, m) + sumOddDesc(a, m+1, ld);
    }

    return rez;
}

//b) Reducere

int sumOdd(int a[], int n) {

    int rez;

    // cazul de baza
    if (n == 0) {
        rez = 0;
    }

    else
    {
        rez = sumOdd(a, n-1);
        if(a[n-1] % 2 != 0)
            rez += a[n-1];
    }
    return rez;
}


int main() {
    int x[10], s;
    int n, i;

    printf("\nDimensiunea vectorilor: ");
    scanf("%d", &n);

    printf("\nElementele vectorului x: ");
    for(i=0;i<n;i++)
    {
        printf("\nx[%d] = ", i);
        scanf("%d", &x[i]);
    }

    //a) Descompunere

    s = sumOdd(x,n);
    printf("\nSuma elementelor impare ale vectorului x este ( metoda descompunerii ): %d", s);

    //b) Reducere

    s = sumOdd(x,n);
    printf("\nSuma elementelor impare ale vectorului x este ( metoda reducerii) : %d", s);

    return 0;
}
