#pragma once
#include <iostream>
#include <iomanip>
#include "Classes.h"
#include "Storage.h"

using namespace std;


int input();
void invalidInput(int&);
void invalidInputTT(int&);
void invalidInputTM(int&);
void beautifyOut(int, TTime, TMoney, TStorage*);
double calculate(TTime, TMoney);
void output(TTime);
void output(TMoney);