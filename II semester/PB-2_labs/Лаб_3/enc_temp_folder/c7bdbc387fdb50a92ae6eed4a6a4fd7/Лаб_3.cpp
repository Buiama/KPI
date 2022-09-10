#include "Functions.h"
#include "Class.h"


int main()
{
    int n = validInput();
    TCubic* polynoms = new TCubic[n];
    input(n, polynoms);
    output(n, polynoms);

    double aMin, bMax, e;
    validInputLimits(aMin, bMax, e);

    int counter = 0;
    outputFindMin(polynoms, n, aMin, bMax, e);
    double min = findMinOfMin(polynoms, n, counter);
    outputMin(polynoms, aMin, bMax, counter, min);

    delete[]polynoms;
}


/*
* Functions:               |   Inflection point (min):
* -------------------------|--------------------------
* 1x^3 + 1x^2 - 4x - 4     |   (0.868517; -6.064605) 
* 1x^3 - 5x^2 + 8x - 4     |   (2; 0)
* -1x^3 - 2x^2 + 1x + 1    |   (-1.54858; - 1.63113)
* 4x^3 - 3x + 0x - 1       |   (0.5; -2)
* 10x^3 - 9x^2 - 3x + 2    |   (0.735889; -1.096381)
* 4x^3 - 19x^2 + 19x + 6   |   (2.54438; -2.772365)
* 0x^3 + 4x^2 - 2x - 1     |   (0.25; -1.25)
* 0x^3 + 0x^2 + 1x - 2     |   (aMin; ?)
* 0x^3 + 0x^2 + 0x + 1.5   |   const (aMin; 1.5)
*/