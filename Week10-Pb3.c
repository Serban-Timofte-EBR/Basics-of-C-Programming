//
//  main.c
//  Produsul scalar a celor doua diagonale
//
//  Created by Serban Timofte on 02.12.2022.
//

#include <stdio.h>

int main() {
    
        float a[100][100], ps;
        int n, m;
        printf("Dimensiunile matricelor: \n");
        scanf("%d %d", &m, &n);
    
        printf("Elementele primei matrici: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("a[%d][%d]= ", i,j);
                scanf("%f", &a[i][j]);
            }
        }
    
        printf("Matricea este: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%6.2f", a[i][j]);
            }
            printf("\n");
        }
        
        ps = 0;
    
        for(int i=0; i<n;i++)
        {
            ps += a[i][i] + a[i][n-1-i];
        }
        
    printf("Produsul scalar cerut este: ");
    printf("%f", ps);
    
    return 0;
}
