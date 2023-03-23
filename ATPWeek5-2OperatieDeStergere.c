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


int main()
{
    FILE* f;
    PRODUS p;
    int i, e, n=0;

    f = fopen("ProduseInitial.dat", "rb+");
    if(!f){ printf("Fisierul nu a fost deschis");}
    else
    {
        fread(&p, sizeof(PRODUS), 1, f);
        while (!feof(f))
        {
            if(p.is == 1)
            {
                e = 0;
                for(i=0;i<12 && e<3;i++)
                {
                    if(p.cant[i] == 0)
                    {
                        e++;
                    }
                }

                if(e>=3)
                {
                    printf("\n%-20s", p.denumire);
                    fseek(f, ftell(f)-sizeof(PRODUS), 0); //ma mut inainte de articolul citit mai sus
                    p.is = 0;
                    fwrite(&p, sizeof(PRODUS), 1, f);
                    fseek(f,0,1); //trece din pozitia de scriere in pozitia de citire
                    n++;
                }
            }
            fread(&p, sizeof(PRODUS), 1, f);
        }
    }
    fclose(f);
    printf("\nAu fost sterse %d articole", n);
    return 0;
}
