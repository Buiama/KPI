#pragma once
#include <iostream>
#include <iomanip>
#include "Classes.h"

using namespace std;

class TStorage {
    TTime time;
    TMoney money;
    double result;
    double total;
public:
    double getRes();
    void setRes(double r);
    double getTotal();
    void setTotal(double t);
    double calculate(TTime a, TMoney b);
    TStorage(TTime a, TMoney b);
    TStorage() {}
    ~TStorage() {}
};