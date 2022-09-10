#pragma once
#include "Class.h"


void invalidInput(double&);
void invalidInput(int&);
int validInput();
void input(int, TCubic*);
void output(int, TCubic*);
void validInputLimits(double&, double&, double&);
void outputFindMin(TCubic*, int, double, double, double);
double findMinOfMin(TCubic*, int, int&);
void outputMin(TCubic*, double, double, int, double);