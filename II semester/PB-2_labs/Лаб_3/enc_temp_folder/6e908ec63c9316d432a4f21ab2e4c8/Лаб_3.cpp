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
* 0 | Functions:                |   Inflection point (min):
* --|---------------------------|--------------------------
* 1 | 1x^3 + 1x^2 - 4x - 4      |   (0.868517; -6.064605) 
* 2 | 1x^3 - 5x^2 + 8x - 4      |   (2; 0)
* 3 | -1.2x^3 + 1x^2 + 1x + 0.3 |   (-0.317989; 0.121712)
* 3 | 4x^3 - 3x + 0x - 1        |   (0.5; -2)
* 4 | 10x^3 - 9x^2 - 3x + 2     |   (0.735889; -1.096381)
* 5 | 4x^3 - 19x^2 + 19x + 6    |   (2.54438; -2.772365)
* 6 | 0x^3 + 4x^2 - 2x - 1      |   (0.25; -1.25)
* 7 | 0x^3 + 0x^2 + 1x - 2      |   (aMin; aMin-2)
* 8 | 0x^3 + 0x^2 + 0x + 1.5    |   const (aMin; 1.5)
*/