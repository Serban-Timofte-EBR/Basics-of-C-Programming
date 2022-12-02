//
//  main.c
// Fie informatiile referitoare la m studenti si n discipline
// a) identificati studentii integralisti toate notele >=5
// b) identificati studentii bursieri >= 8,5 si (+)integralisti
//
//  Created by Serban Timofte on 02.12.2022.
//

#include <stdio.h>

int main() {
    
        float mat[100][100];
        int m, n, in, bu;
        in = 0;
        bu = 0;
        printf("Numarul de studenti si discipline este:\n");
        scanf("%d %d", &m, &n);
        printf("Datele din tabel sunt: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%f", &mat[i][j]);
            }
        }
    
    
        for (int i = 0; i < m; i++)
        {
            float s = 0;
            int ok = 1;

            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] < 5)
                {
                    ok = 0;
                }
                s += mat[i][j];
            }
            if (ok == 1)
                in++;
            if (ok == 1 && (s / n) > 8.5)
                bu++;
        }
        printf("Bursieri sunt: %d\n", bu);
        printf("Integralisti sunt: %d\n", in);
        return 0;
}
