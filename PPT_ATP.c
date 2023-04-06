//Timofte Serban Gabriel
//Grupa 1026, An 1, Serie E
//Scrieti un program care inregistreaza recuperarea unui seminar de catre un student. Studentul este identificat prin nuamrul matricol, disciplina este identificata prin pozitia in vector

#include <stdio.h>
typedef struct {
    char is;
    int nrmat;
    char nume[25];
    int grupa;
    char an;
    char absente[30];
} student;

void listareDataTXT(const char* numeFisBin, const char* numeFisTxt)
{
    FILE* f, *g;
    student s;
    int i, j;
    g = NULL;

    f = fopen(numeFisBin, "rb");
    if (!f) { printf("Fisierul binar nu a fost deschis"); }
    g = fopen(numeFisTxt, "w");

    fread(&s, sizeof(student), 1, f);
    fprintf(g, "\nNr. Mat. Nume %15s Grupa An Absente", "");

    while (!feof(f))
    {
        if (s.is == 1)
        {
            fprintf(g, "\n\n%d %s\t %s\t %d\t %d\t ", s.nrmat, s.nume, "",s.grupa,s.an);
            for (i = 0; i < 30; i++)
            {
                fprintf(g, "%d ", s.absente[i]);
            }
        }
        fread(&s, sizeof(student), 1, f);
    }
    fclose(f);
    fclose(g);
}

int main() {

    FILE *f;
    student s;
    int i,j,matCautat;

    f = fopen("Fis_relativ_Absente.dat", "rb+");

    printf("Numarul matricol cerut: ");
    scanf("%d", &matCautat);

    while(!feof(stdin))
    {
        fseek(f, matCautat*sizeof(student), 0);
        fread(&s, sizeof(student), 1, f);
        fseek(f, 0, 1);
        if(s.is == 0) { printf("Numarul matricol nu este valid!");}
        else
        {
            printf("Introduceti indexul materiei ceruta: ");
            scanf("%d", &i);
            printf("Este curs sau seminar(0/1)?: ");
            scanf("%d", &j);

            i = i +j; // daca este seminar j este 1 si mergem la urmatoarea pozitie din vectorul de absente pentru a modifica corect
            s.absente[i] = s.absente[i] - 1;

            fseek(f, matCautat*sizeof(student), 0);
            fwrite(&s, sizeof(student), 1, f);
            printf("Am scazut cu 1 numarul de absente la mataria ceruta!");
        }

        printf("Noul cod matricol: ");
        scanf("%d", &matCautat);
    }
    fclose(f);

    listareDataTXT("Fis_relativ_Absente.dat", "FisTXT.txt");
    return 0;
}
