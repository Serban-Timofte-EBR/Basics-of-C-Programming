#include <stdio.h>

int main()
{
    FILE* f, * g;
    float x[5]={1,2,3,4,5};
    float y;

    f = fopen("FisBin.dat", "wb");
    fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(float), f);
    fclose(f);

    f = fopen("FisBin.dat", "rb");
    g = fopen("FisText.txt", "w");

    if(!f) { printf("Fisierul binar nu s-a deschis");}
    else
    {
        if(!g) { printf("Fisierul text nu s-a deschis");}
        else
        {
            fread(&y, sizeof(float), 1,f);
            while(!feof(f))
            {
                fprintf(g, "%6.2f\t", y);
                fread(&y, sizeof(float), 1, f);
            }
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}
