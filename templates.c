#include <stdio.h>

// divide et Impera
void maxImpare(int v[], int start, int end, int *max){
    if(start == end)
    {
        if(v[start]%2 == 1) { 
            if (*max < arr[start]) {
                *max = arr[start];
            }}
        else {return -1;}
    }
    
    int m=(start+end)/2;
    int half1 = maxImpare(v, start, m, *max);
    int half2 = maxImpare(v, m+1, end, *max);
}

//backtracking

int generare_s(int *x, int n, int i, int a, int b, int nr)
{
   int j;
   if (i == n) {
        if (conditie_finala(x,n))
        {
            nr++;
            retine_solutia(nr, x, n);
        }
    }
    else
         for (j = a; j <= b; j++) {
            x[i] = j;
            nr = generare_s(x,n, i + 1, a, b,nr);
      }
     return nr;
}
