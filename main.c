#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double thresholdAdd =  0.000001;

unsigned factorialFunc (unsigned number);

double sinXFunc ( double argSinD );

int main()
{
    double argSinD = 45;
    double sinx = sinXFunc(argSinD);
    printf ("result sinx = %lf\n", sinx );

    double radNum = M_PI/180 * argSinD;
    printf ("result sinxMath_h = %lf\n", sin(radNum) );
    system("pause");
    return 0;
};

double sinXFunc ( double argSinD )
{
    double sinX = 0;
    double sinXAdd = 0;
    int itrSinX = 0;

    printf ("argSinDegree = %lf\n", argSinD );

    double radNum = M_PI/180 * argSinD;

    printf ("argSinRad = %lf\n", radNum );

    for (;;)
    {
        int nMulty2Plus1 = 2*itrSinX+1;
        sinXAdd = (pow(-1,itrSinX) * pow(radNum,nMulty2Plus1))/factorialFunc(nMulty2Plus1);
        ++itrSinX;
        printf ("itrSinX = %d, sinXAdd = %lf\n",itrSinX , sinXAdd );
        sinX += sinXAdd;
        if (fabs(sinXAdd) < thresholdAdd)
        {
            break;
        }
    }
    return sinX;
};

unsigned factorialFunc (unsigned number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return factorialFunc(number - 1) * number;
    }
};





