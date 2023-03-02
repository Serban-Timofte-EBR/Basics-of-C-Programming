#include <stdio.h>
#include "math.h"

//Metoda bisectiei - parametru de tipul pointer la functie

float fct(float x)
{
    return x*x*x - 3*x + 14; //pas 1 - declararea fct catre care se pointeaza
}

//cod si x paramentrii de output && eps este eroarea pe care o permitem noi
void bisectie(float a, float b, float (*f)(float), float eps, long n, int *cod, float *x)
// cod = 0 daca nu s-a gasit solutie
// cod = 1 daca s-a gasit solutie cu valoarea in x
{
   long c;
   int gata = 0;

   for(c=0;c<n && !gata; c++)
   {
       *x = (a+b)/2;
       gata = fabs(*x - a) < eps;

       if( (*f)(*x) * (*f)(a) < 0 )
       {
           b = *x;
       }

       else
       {
           a = *x;
       }
   }
   *cod = gata;
}

int main() {

    float a,b,eps,x;
    long n;
    int cod;
    float (*functie)(float); //pas 2 - declarearea pointerului la functie

    printf("Citeste a: ");
    scanf("%f", &a);

    printf("Citeste b: ");
    scanf("%f", &b);

    printf("Citeste epsiolon: ");
    scanf("%f", &eps);

    printf("Citeste n -  Numarul maxim de iteratii: ");
    scanf("%li", &n);

    functie = fct; // pas 3 - asociere functie fct

    bisectie(a,b, functie, eps, n, &cod, &x); // pas 4 - apel functie prin intermediul pointerului la functie

    if(!cod) { printf("Nu exista solutii! :(");}
    else { printf("Solutia este: %f :)", x);}

    return 0;
}
