//
//  main.c
//  Suma a doua matrice
//
//  Created by Serban Timofte on 02.12.2022.
//

#include <stdio.h>

int main() {
    
    float a[100][100], b[100][100], c[100][100];
    int n,m;
    
    printf("Introduceti dimensiunile matricei: \n");
    scanf("%d %d", &n, &m);
    
    printf("Valorile primei matrici sunt: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("a[%d][%d]=", i,j);
            scanf("%f", &a[i][j]);
        }
    }
    
    printf("Valorile celei de a doua matrici sunt: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("b[%d][%d]=", i,j);
            scanf("%f", &b[i][j]);
        }
    }
    
    printf("Matricile a si b sunt: \n");
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%6.2f", a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%6.2f", b[i][j]);
        }
        printf("\n");
    }
    
    printf("Suma matricilor este matricea: \n");
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            printf("%6.2f", c[i][j]);
        }
        printf("\n");
    }
        
    return 0;
}
