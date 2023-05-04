//problema permutarilor (var. cu ratie): n=3 P(3)=3!=6 k=3 S={1,2,3} => 123 132 213 231 312 321
// C - multimea elementelor consumate

#include <stdio.h>
#include <stdlib.h>

//functia de validare - adaugare element nou
//IN: v[] - permutare; i - nivelul curent
//OUT: 1 - valid; 0 - invalid`

int posibil(int *v, int i) {
    int j;
    for (j = 0; j < i; j++)
        if (v[i] == v[j])
            return 0;
    return 1;
}

//functia de retinere a solutiei
//IN: num - nr solutiei; v[] - solutia completa; nr - dimensiune permutare
//OUT: - afisarea permutarii

void retinere_solutii(int num, int *v, int nr) {
    int i;
    printf("\nSolutia nr. %d: ", num);
    for(i=0;i<nr;i++)
        printf("%2d ", v[i]);
}

//functia de permutare
//IN: n - dimensiun permutari
//OUT: nr - numarul de solutii
int permutari(int n){
    int* p; //permutare de construit - sol partiala
    int i, am, nr; //nivel curent; am - daca adaug sau nu elem curent; nr - nr solutii
    p=(int*)malloc(n*sizeof(int));

    i=0;
    p[0]=0;
    nr=0;
    
    while(i>=0)
    {
        am=0;
        while(am==0 && p[i]<n)
        {
            p[i]++;
            am=posibil(p,i);
        }

        if(am==1)
        {
            if(i==n-1)
            {
                nr++;
                retinere_solutii(nr,p,n); //am pus un element valid si am construit o solutie completa
            }
            else
            {
                p[++i]=0; //i++ p[i]=0 - am pus un element valid si am construit o solutie completa
            }
        }
        else
            i--; //se revine la niv anterior fiind consumate toate valorile pentru nivelul curent
    }

    free(p);
    return nr;
}

int main() {
    int n, nr;
    printf("\nDimensiune permutare: ");
    scanf("%d", &n);

    nr=permutari(n);
    printf("\nNumarul total de solutii este: %d", nr);

    return 0;
}
