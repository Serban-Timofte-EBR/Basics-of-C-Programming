//
//  main.c
//  BPCPP212Ian
//
//Fie o matrice de dimensiune mxn, reprezentând vânzările valorice a m produse într-o perioadă de n zile, dintr-un magazin. Să se scrie ① subprogramul C care determină zilele fără vânzări, precum și ② programul apelator. Transferul datelor se va realiza exclusiv prin parametri.
//  Created by Serban Timofte on 12.01.2023.
//

#include <stdio.h>
#include <stdlib.h>

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

void fara_vanzari(int m, int n, int mat[10][10], int zile[10], int *k)
{
    
    *k = 0;
    
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        
        for (int j = 0; j < m; j++)
        {
            total += mat[j][i];
        }
        
        if (total == 0)
        {
            zile[*k] = i;
            *k = *k + 1;
        }
    }
}

int main() {
    // insert code here...
    int mat[10][10];
    int zile[10];
    int m,n,k;
    
    printf("Dimensiune matrice: ");
    scanf("%d %d", &m, &n);
    
    citireM(m, n, mat);
    afisareM(m, n, mat);
    
    fara_vanzari(m, n, mat, zile, &k);
    
    for(int i=0; i<k;i++)
    {
        printf("%d", zile[i]);
        printf(" ");
    }
    
    printf("\n");
    return 0;
}
