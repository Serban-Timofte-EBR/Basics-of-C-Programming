//
//  main.c
//  Transpusa unei matrici
//
//  Created by Serban Timofte on 02.12.2022.
//

#include <stdio.h>

int main() {
    
        float a[100][100], t[100][100];
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
    
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                t[i][j] = a[j][i];
            }
        }
    
    printf("Matricea transpusa este: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%6.2f", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
