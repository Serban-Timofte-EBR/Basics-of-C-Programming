//Grafuri
//Graf neorientat neponderat - preluare din fisier txt in forma tabelara si conversie in forma matriciala
//citire din fisier dupa structura:
//nr. varfuri - nr. muchii
//perechi muchii ( 1-2; 1-3; 2-4; 2-6; 3-4; 3-5; 4-5; 5-6)

#include <stdio.h>

//preluare graf din fiser txt in forma tabelara
//IN: fisierul txt
//OUT: nr varfuri, nr muchii, matrice forma tabelara - g[][2], er - error collector
int preluareGraf(const char *fisier, int *nrV, int *nrM, int g[][2]) {
    int err;
    FILE *f = fopen(fisier, "r");
    if (f == NULL) {
        err = 1;
    }
    err = 0;
    fscanf(f, "%d %d", nrV, nrM); //preluare numar varfuri si numar muchii
    printf("Nr Varfuri: %d, Nr Muchii: %d\n", *nrV, *nrM);
    for (int i = 0; i < *nrM; i++) {
        fscanf(f, "%d %d", &g[i][0], &g[i][1]);
        printf("%d %d\n", g[i][0], g[i][1]);
    }
    fclose(f);
    return err;
}

//conversie graf din forma tabelara in forma matriciala
//IN: nr varfuri, nr muchii, matrice forma tabelara - g[][2]
//OUT: matrice forma matriciala - gM[][nrV]
void conversieGraf(int nrV, int nrM, int g[][2], int mat[6][6]) {
    //initializare cu 0 in matricea de adiacenta
    for (int i = 0; i < nrV; i++) {
        for (int j = 0; j < nrV; j++) {
            mat[i][j] = 0;
        }
    }
    //constructie matrice de adiacenta
    for (int i = 0; i < nrM; i++) {
        mat[g[i][0] - 1][g[i][1] - 1] = 1;
        mat[g[i][1] - 1][g[i][0] - 1] = 1; //se omite pentru graf orientat
    }
}

//afisare graf in forma matriciala
void afisare(int nrV, int gM[][nrV]) {
    for (int i = 0; i < nrV; i++) {
        for (int j = 0; j < nrV; j++) {
            printf("%d ", gM[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int err, nrV, nrM, tabel[8][2], mat[6][6];
    printf("---1\n");
    err = preluareGraf("g1.txt", &nrV, &nrM, tabel);
    if(err==1){ printf("Fisierul nu s-a deschis!");}
    else { printf("Tabelul s-a deschis!\n");}

    printf("--2\n");
    conversieGraf(nrV, nrM, tabel, mat);
    printf("--3\n");
    afisare(nrV, mat);
    printf("--4\n");
    return 0;
}
