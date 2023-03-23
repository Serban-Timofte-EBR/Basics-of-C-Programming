//fisiere organizate relativ
// 1 - Creare fisier
// 2 - Listare din fisier binar in fisier text
// 3 - Operatie asupra fisierului de la pct. 1 (stergere articol(e) care indeplinesc o conditie)
// 4 - Listare fisier binar nou
// 5 - Exercitii/Tema

#include<stdio.h>

typedef struct
{
    char denumire[20];
    float pret;
    int cant[12];
    char is;
} PRODUS;

void listareBinToTxt(const char* numeBin, const char* numeText)
{
    FILE *f, *g;
    g = NULL;
    PRODUS p;
    int i;
    int n=0;

    f = fopen(numeBin, "rb");
    if(!f){ printf("Fisierul binar nu a fost gasit");}
    else
    {
        g = fopen(numeText, "w");
        fprintf(g,"\nNr. Denumire %5s Pret Cantitati", "");

        fread(&p, sizeof(PRODUS), 1, f);

        while(!feof(f))
        {
            if(p.is == 1)
            {
                fprintf(g, "\n%3d %-20s %6.2f", ++n, p.denumire, p.pret);
                for(i=0; i<12; i++)
                {
                    fprintf(g, "%3d ", p.cant[i]);
                }
            }
            fread(&p, sizeof(PRODUS), 1, f);
        }
        fclose(f);
        fclose(g);
    }
}

int main()
{
    listareBinToTxt("ProduseInitial.dat", "Raport01.txt");
    return 0;
}
