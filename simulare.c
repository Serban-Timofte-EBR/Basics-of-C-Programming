#include <stdio.h>

typedef struct
{
  char is;
  int nrmat;
  char nume[25];
  int grupa;
  char an;
  char absente[2][15];
} student;

int nrart(FILE* f, int l)
{
  int n, p;
  p = ftell(f);
  fseek(f, 0, 2);
  n = ftell(f) / l;
  fseek(f, p, 0);
  return n;
}

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
  for (i = 0; i < 2; i++)
  {
  for (j = 0; j < 15; j++)
  {
  fprintf(g, "%d ", s.absente[i][j]);
  }
  }
  }

  fread(&s, sizeof(student), 1, f);
  }
  fclose(f);
  fclose(g);
}


int main()
{
  FILE* f;
  student s; 
  int i, j, nrCautat, indexMat, statusCS, nrAbs;

  f = fopen("Fis_relativ_abs.dat", "rb+");
  if (!f) { printf("Fisierul binar nu a fost deschis"); }

  printf("Numarul matricol cautat: ");
  scanf("%d", &nrCautat);

  while (!feof(stdin))
  {

  fseek(f, nrCautat * sizeof(student), 0);
  fread(&s, sizeof(student), 1, f);

  if (s.is == 1)
  {
  printf("Studentul a fost gasit!\n");
  printf("Materia la care schimbam numarul de absente: ");
  scanf("%d", &indexMat);
  printf("\nEste curs sau seminar?(0/1): ");
  scanf("%d", &statusCS);
  printf("\nNoul numar de absente: ");
  scanf("%d", &nrAbs);
  s.absente[statusCS][indexMat] = nrAbs;

  fseek(f, nrCautat * sizeof(student), 0);
  fwrite(&s, sizeof(student), 1, f);
  }

  else
  {
  printf("Nu exista studentul");
  }

  printf("Noul cod matricol: ");
  scanf("%d", &nrCautat);

  }

  listareDataTXT("Fis_relativ_abs.dat", "FisRelTXT.txt");
  return 0;
}
