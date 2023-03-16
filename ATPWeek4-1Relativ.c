//Creare fisier organizat relativ
//De la tastatura introduce elemente (populare)
//Scriem elemente in fisier in functie de elementul cod care reprezinta pozitia elementului din fisier
#include <stdio.h>

typedef struct {
	char denumire[20];
	float pret;
	int cant[20];
	char is; //valori de 0 sau 1
} Produs;

int nrart(FILE* f, int l) // l este sizeof(Produs)
{
	long p;
	int n;

	p = ftell(f); // retine pozitia curenta din fisier
	fseek(f, 0, 2); // pozitionare la sf fisierul
	n = ftell(f) / l; // calculam numar articole din fisier
	fseek(f, p, 0); // revenire la pozitia initiala

	return n;
}


int main()
{
	FILE* f;
	Produs p;
	int i, cod; //cod ajuta la pozitionarea articolelor in fisier (unicitatea articolului)
	char nume[20];

	f = fopen("FisRel.dat", "wb+"); //fopen_s(&f, "FisRel.dat", "wb+");

	printf("Cod produs: ");
	scanf("%d", &cod);

	while (!feof(stdin))
	{
		if (cod >= nrart(f, sizeof(Produs)))
		{
			//Preformare fisier pentru a ajunde la pozitia data de cod
			p.is = 0;
			fseek(f, 0, 2);
			for (i = nrart(f, sizeof(Produs)); i <= cod; i++)
			{
				fwrite(&p, sizeof(Produs), 1, f);
				fseek(f, cod * sizeof(Produs), 0); //pozitionare la inceputul articolul scris
				fread(&p, sizeof(Produs), 1, f);

				if (p.is == 1) { printf("Articolul exista deja!"); }
				else {
					fseek(f, cod * sizeof(Produs), 0);
					printf("Denumire: ");
					fflush(stdin);
					scanf("%s", &p.denumire);

					printf("Pret: ");
					scanf("%f", &p.pret);

					p.is = 1;

					for (i = 0; i < 3; i++)
					{
						printf("Cant[%d] = ", i + 1);
						scanf("%d", &p.cant[i]);
					}

					p.is = 1; //marcare articol scris

					fwrite(&p, sizeof(Produs), 1, f); //p - sursa si f destinatia
				}
			}
			printf("Cod produs NOU: ");
			scanf("%d", &cod);
		}
	}
	fclose(f);
	return 0;
}
