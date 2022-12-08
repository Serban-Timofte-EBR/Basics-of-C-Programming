//
// Citire de masivi
//  Produsul scalar, vectorial
//  Week11-1
//
//  Created by Serban Timofte on 08.12.2022.
//

#include <stdio.h>

//INPUT: m, v[]
//OUTPUT: v[]

void citireV(int m, int v[10])
{
    int i;
    
    for(i = 0; i<m; i++)
    {
        printf("v[%d]= ", i);
        scanf("%d", &v[i]);
    }
}

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

//pb2 - Produs scalar a doi vectori
//2.1 - Rezultat intors prin numele functiei

int prodScal1(int m, int v1[10], int v2[10])
{
    int i;
    int ps = 0;
    
    for(int i=0; i<m; i++)
    {
        ps += v1[i]*v2[i];
    }
    
    return ps;
}

//pb2 - Prodis scalar a doi vectori
//2.2 - Rezultat intors prin paramentru

void prodScal2(int m, int v1[10], int v2[10], int *ps)
{
    int i;
    *ps = 0;
    
    for(i=0;i<m;i++)
    {
        *ps += v1[i]*v2[i];
    }
}

//3. Produs vectorial
//Intors prin paramanetru

void prodVect(int m, int v1[10], int v2[10], int pv[10])
{
    int i;
    for(int i=0; i<m; i++)
    {
        pv[i] = v1[i] * v2[i];
    }
}

int main() {
    
    int m, v1[10], v2[10], pv[10];
    int ps;
    
    printf("Dati dimensiunea vectorului: ");
    scanf("%d", &m);
    
    citireV(m, v1);
    citireV(m, v2);
    afisareV(m, v1);
    afisareV(m, v2);
    
    printf("\n");
    printf("Prod Scal 1: %d", prodScal1(m, v1, v2));
    
    printf("\n");
    prodScal2(m, v1, v2, &ps);
    printf("Prod Scal 2: %d", ps);
    
    printf("\n");
    prodVect(m, v1, v2, pv);
    afisareV(m, pv);
    return 0;
}
