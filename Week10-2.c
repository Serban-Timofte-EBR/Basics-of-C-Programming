//
//  main.c
//  Inmultirea a doua matrici
//
//  Created by Serban Timofte on 02.12.2022.
//

#include <stdio.h>

int main() {
    
    float a[100][100], b[100][100], c[100][100];
        int n, m, p;
        printf("Dimensiunile matricelor: \n");
        scanf("%d %d %d", &m, &n, &p);
    
        printf("Elementele primei matrici: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("a[%d][%d]= ", i,j);
                scanf("%f", &a[i][j]);
            }
        }
    
        printf("Elementele celei de a doua matrici: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < p; j++)
            {
                printf("b[%d][%d]= ", i,j);
                scanf("%f", &b[i][j]);
            }
        }
    
        printf("Produsul matricilor este: /n");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < p; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }

        printf("\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < p; j++)
                printf("%.2f ", c[i][j]);
            printf("\n");
        }
  return 0;
}
