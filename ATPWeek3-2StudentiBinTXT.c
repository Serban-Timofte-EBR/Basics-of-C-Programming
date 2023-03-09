// 3 - Listare din fisier binar in fisier text
#include <stdio.h>
#define freadb(x,f) fread(&(x), sizeof(Student), 1, f)
#define fwriteb(x,f) fwrite(&(x), sizeof(Student), 1, f)

typedef struct
{
    int nr; //numar matricol
    char nume[30];
    int an;
    int grupa;
    int n; //numar de discipline cu note
    int note[15];
} Student;

int main()
{
    FILE* f;
    FILE* g;
    Student s;
    int i,n;

    printf("Deschidem fisierul binar pentru citire");
    f = fopen("Fisbin.dat", "rb");

    if(!f) {
        printf("Fisierul binar nu s-a deschis!");
    }
    else{
        printf("Deschidem fisierul text pentru scriere");
        g = fopen("Fistxt.txt", "w");

        fprintf(g, "\nNr. Nume %25s An Grupa Note", "");

        n = 0;
        freadb(s, f);
        while (!feof(f))
        {
            fprintf(g, "\n%3d %-30s, %2d, %4d", ++n, s.nume, s.an, s.grupa);
            for(i=0;i<s.n;i++)
            {
                fprintf(g, "%2d ", s.note[i]);
            }

            freadb(s, f);
        }
    }

    fclose(f);
    fclose(g);
    
    return 0;
}
