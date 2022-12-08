//
// O matrice m x n cu m studenti si n materii => pe linie sunt notele unui student
// Determinati materiile cu nr maxim de restantieri
// Week11-4
//
//  Created by Serban Timofte on 08.12.2022.
//

#include <stdio.h>

void afisareV(int m, int v[10])
{
    int i;
    printf("\n");
    for(i=0;i<m;i++)
    {
        printf("%d", v[i]);
        printf(" ");
    }
}

//citire matrice

void citireM(int m, int n, int mat[10][10])
{
    int i,j;
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("mat[%d][%d]= ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void afisareM(int m, int n, int mat[10][10])
{
    int i,j;
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }
}

//fac pointer valorile pe care nu le stiu la inceputul subprogramului
void analizaPeLinii(int m, int n, int mat[10][10], int nrRestF[10], int *k, int *max)
{
    int i,j;
    int nr = 0;
    int nrRest[10];
    
    //a) Determinare vector cu nr de restante per disciplina
    
    for(j=0; j<n; j++)
    {
        nr=0;
        for(i=0; i<m; i++)
        {
            if(mat[i][j]<5) {nr++;}
            nrRest[j] = nr;
        }
    }
    
    //b) Determinare maxim din nrRest
    
    *max=nrRest[0];
    
    for(j=0;j<n;j++)
    {
        if(nrRest[j]>*max)
        {
            *max = nrRest[j];
        }
    }
    
    //c) Determinare pozitii max din nrRest => nrRestF si dimensiunea sa
    
    *k=0;
    
    for(j=0;j<n;j++)
    {
        if(nrRest[j] == *max)
        {
            nrRestF[(*k)] = j;
            (*k)++; // acelasi lucru ca *k = *k + 1
        }
    }
}

int main() {
    
    int m,n, mat[10][10], nrRestF[10], k, max;
    m=4;
    n=4;
    
    citireM(m, n, mat);
    afisareM(m, n, mat);
    
    analizaPeLinii(m, n, mat, nrRestF, &k, &max);
    printf("Maximul de restantieri este: %d", max);
    afisareV(k, nrRestF);
    
    return 0;
}
