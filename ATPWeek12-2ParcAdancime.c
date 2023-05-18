//Parcurgerea de grafuri
// 2. Parcurgerea in adancime

#include <stdio.h>

//a - matricea de adiacenta; viz - vector de vizitati; coada - coada rezultat parcurgere
int a[20][20], viz[20];
// i,j - condori; n - varfuri; m - muchii; el - element curent; pl - varf plecare;
// x,y - variabile ajutatoare pentru constuirea matrice de adiacenta, p, u - pozitii coada
int i,j,n,m, pl, x, y;

void parcurgere_adancime(int pl)
{
    int j;
    printf("Vf. vizitat: %d\n", pl);
    viz[pl]=1;
    
    for(j=1;j<=n;j++)
    {
        if(a[pl][j]==1 && viz[j]==0)
            parcurgere_adancime(j);
    }
    
}

int main() {

    //citire graf
    printf("Nr. varfuri: "); scanf("%d", &n);
    printf("\nNr. muchii: "); scanf("%d", &m);

    //construire matrice de adiacenta
    for(i=1; i<=m; i++)
    {
        printf("x="); scanf("%d", &x);
        printf("y="); scanf("%d", &y);
        a[x][y]=1; a[y][x]=1;
    }

    //initializare vector de vizitare
    for(i=1;i<=n;i++)
        viz[i]=0;

    printf("\nVarf plecare: "); scanf("%d", &pl);

    parcurgere_adancime(pl);

    return 0;
}
