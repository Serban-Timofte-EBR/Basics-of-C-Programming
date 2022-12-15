//
//
//  Matrice cu notele a m studenti la n discipline
//  Fie o matrice care contine informatiile privind vanzarile zilnice a m societati in n zile
//  Determinati intr-un subprogram in C amplitudinea vanzarilor zilnice (max - min pe coloane)
//  Week12
//
//  Created by Serban Timofte on 15.12.2022.
//

#include <stdio.h>
#include <stdlib.h> //librarie pentru alocare dinamica a variabilelor

// alocare memorie

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

//alocare memoriei

int** alocareM(int m, int n)
{
    int** t;
    t = (int**)malloc(m*sizeof(int*));
    for(int i=0; i<m; i++)
    {
        t[i] = (int*)malloc(n*sizeof(int));
    }
    return t;
}

//dezalocarea memoriei

void dezalocareM(int** mat, int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        free(mat[i]);
    }
    
    free(mat);
}

//citire matrice

void citireM(int** mat, int m, int n)
{
    int i,j;
    for(i = 0; i<m;i++)
    {
        for(j=0; j<n;j++)
        {
            printf("mat[%d][%d]= ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

//afisare matrice

void afisareM(int** mat, int m, int n)
{
    int i,j;
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

//pb1 - eliminare disciplina - problema cu studenti
    //INPUT: mat, m, n, nrColDeSters
    //OUTPUT: mat(noua), n

void amplitudineColoane(int** mat, int m, int n, int* amp)
{
    int i,j,min,max;
    for(j=0;j<n;j++)
    {
        max=mat[0][j];
        min=mat[0][j];
        for(i=0;i<m;i++)
        {
            if(max < mat[i][j])
            {
                max = mat[i][j];
            }
            
            if(min > mat[i][j])
            {
                min = mat[i][j];
            }
        }
        
        amp[j] = max - min;
    }
}

int main() {
    
    int m,n;
    int* v;
    int* amp;
    int** mat;
    
    printf("Dimens: ");
    scanf("%d %d", &m, &n);
    printf("\n");
    
    //v = alocareV(m);
    //citireV(v, m);
    //afisareV(v, m);
    
    mat = alocareM(m, n);
    citireM(mat, m, n);
    afisareM(mat, m, n);
    
    //free(v); //eliberare memorie pentru vectori

    
    amp = alocareV(m);
    amplitudineColoane(mat, m, n, amp);
    
    printf("\n");
    afisareV(amp, m);
    free(amp);
    dezalocareM(mat, m);
    
    return 0;
}
