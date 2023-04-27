//Metoda Rucsacului - Greedy Algorithm ( forma intreaga )
//IN: q - capacitate rucsac, n - nr de obiecte, c[] - vector capacitati
//OUT: sol[] - vector solutie ( 0 sau 1 )

#include <stdio.h>

void rucsacIntr(float q, int n, float c[], int sol[])
{
    float qr; //capacitate ramasa
    int indexVector;

    qr = q;

    for(indexVector=0;indexVector<n;indexVector++)
        if(qr>=c[indexVector]) //verificare daca obiectul intra in rucsac
        {
            sol[indexVector]=1; //adaugare obiect
            qr=qr-c[indexVector]; //modificare capacitate rucsac
        }
        else
            sol[indexVector]=0;
}


int main() {

    float CT=33; //capacitate totala rucsac
    float c[10] = {1,2,3,4,5,6,7,8,9,10}; //vector capacitati
    float v[10] = {3,2,1,4,5,3,2,7,1,8}; //vector valori

    int sol[10]; //vector solutie
    int indexVector1,indexVector2,n=10;

    float castig=0; //castigul
    float aux; //variabila auxiliara

    for(indexVector1=0;indexVector1<n-1;indexVector1++)
        for(indexVector2=indexVector1+1;indexVector2<n;indexVector2++)
            if(v[indexVector1]/c[indexVector1]<v[indexVector2]/c[indexVector2])
            {
                aux=v[indexVector1];
                v[indexVector1]=v[indexVector2];
                v[indexVector2]=aux;

                aux=c[indexVector1];
                c[indexVector1]=c[indexVector2];
                c[indexVector2]=aux;
            }

    rucsacIntr(CT, n, c, sol);

    for(indexVector1=0;indexVector1<n;indexVector1++)
        printf("\n%2d: c=%5.2f, v=%5.2f, %2d, castig=%5.2f,",indexVector1+1, c[indexVector1], v[indexVector1], sol[indexVector1], castig += sol[indexVector1]*v[indexVector1]);

    return 0;
}
