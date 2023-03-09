// 1 - Creare fisier binar organizat secvential
// 2 - Introducere date din struct in fisier BINAR

#include <stdio.h>

typedef struct
{
    int nr; //numar matricol
    char nume[30];
    int an;
    int grupa;
    int n; //numar de discipline cu note
    int note[15];
} Student;

int main() {

    FILE* f;
    Student s;
    int i;
    char s1[20];

    printf("Deschidere fisier\n");
    f= fopen("Fisbin.dat", "wb");

    //verificare deschidere fisier - tema
    if(!f)
    {
        printf("Fisierul nu s-a deschis!");
    }
    else{
        printf("Numar matricol: ");
        scanf("%d", &s.nr);

        while (!feof(stdin))
        {
            printf("Nume: ");
            fflush(stdin);
            scanf("%s", &s.nume);

            printf("An: ");
            scanf("%d", &s.an);

            printf("Grupa: ");
            scanf("%d", &s.grupa);

            printf("Numar discipline cu note: ");
            scanf("%d", &s.n);

            for(i=0;i<s.n;i++)
            {
                printf("Nota[%d] = ", i+1);
                scanf("%d", &s.note[i]);
            }

            fwrite(&s, sizeof(Student), 1, f);

            printf("Numar matricol nou: ");
            scanf("%d", &s.nr);
        }
        fclose(f);
    }
    return 0;
}
