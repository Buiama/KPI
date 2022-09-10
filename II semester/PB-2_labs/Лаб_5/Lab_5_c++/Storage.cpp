#include "Storage.h"


double TStorage::getRes() {
    return result;
}

void TStorage::setRes(double r) {
    result = r;
}

double TStorage::getTotal() {
    return total;
}

void TStorage::setTotal(double t) {
    total = t;
}

double TStorage::calculate(TTime a, TMoney b) {
    double res;
    double minutes, price;
    minutes = a.getFirst() * 60 + a.getSecond();
    price = b.getFirst() + b.getSecond() * 0.01;
    res = minutes * price;
    return res;
}

TStorage::TStorage(TTime a, TMoney b) {
    time = a;
    money = b;
    result = calculate(time, money);
    total += result;
}