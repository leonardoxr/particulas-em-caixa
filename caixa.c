#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>

double dist(double x1,double x2,double y1,double y2);


void main()
{
    FILE *arq2;
    arq2 = fopen("histograma.txt", "w+");
    int i,discos;

    for(i=0; i<1000; i++)
    {
        discos = caixa();
        fprintf(arq2,"%d\n", discos);
    }

    fclose(arq2);
}
int caixa()
{

    double box[1000][2],disco_xy[2];
    int i,k,j,l,r,discos;
    bool found;

    FILE *arq1;

    arq1 = fopen("discos.txt", "w+");

    srand48(time(NULL));

    for(i=0; i<2; i++)
    {
        for(j=0; j<1000; j++)
        {
            box[i][k] = 0;
        }
    }

    l = 50;
    r = drand48();
    discos = 0;
    while (i < 50000)
    {
        disco_xy[0] = 1 + drand48() * (l-2);
        disco_xy[1] = 1 + drand48() * (l-2);
        found = false;

        j = 0;
        while (j < discos+1)
        {
            if (   dist(disco_xy[0],box[j][0],disco_xy[1],box[j][1])  < 2*r   )
            {
                found = true;
                i++;
                break;
            }
            j++;

        }

        if (found == false)
        {
            box[j][0] = disco_xy[0];
            box[j][1] = disco_xy[1];
            i = 0;
            discos++;
            //fprintf(arq1,"%lf %lf \n", disco_xy[0],disco_xy[1]);
        }


    }



    fclose(arq1);
    return discos;



}


double dist(double x1,double x2,double y1,double y2)
{
    double distanc;
    distanc = sqrt( pow(x2-x1,2) + pow(y2-y1,2) );
    return distanc;

}
