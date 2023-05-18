//Parcurgerea de grafuri
// 1. BF - Parcurgerea in latime

#include <stdio.h>

//a - matricea de adiacenta; viz - vector de vizitati; coada - coada rezultat parcurgere
int a[20][20], viz[20], coada[20];
// i,j - condori; n - varfuri; m - muchii; el - element curent; pl - varf plecare;
// x,y - variabile ajutatoare pentru constuirea matrice de adiacenta, p, u - pozitii coada
int i,j,n,m, el, pl, x, y, p, u;

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

    viz[pl]=1; coada[1]=pl; //marcare ca vizitat si adaugare in coada a varfului de plecare
    p=1; u=1; //modificare coada

    while(p<=u)
    {
        el = coada[p]; //extragere element din coada
        for(j=1;j<=n;j++)
        {
            if(a[el][j]==1 && viz[j]==0) //daca exista muchie si nu este vizitat
            {
                u++; //modificare coada
                coada[u]=j; //adaugare in coada
                viz[j]=1; //marcare ca vizitat
            }
        }
        p++; //modificare coada
    }

    for(i=1;i<=u;i++)
        printf("%d ", coada[i]);
    
    return 0;
}
