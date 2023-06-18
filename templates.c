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

