#include "Classes.h"


int TPair::getFirst() {
    return first;
}
void TPair::setFirst(int a) {
    first = a;
}
int TPair::getSecond() {
    return second;
}
void TPair::setSecond(int b) {
    second = b;
}

void TPair::print() {
    cout << first << " " << second;
}

TPair TPair::operator++() {
    ++second;
    transfer(update());
    return *this;
}
TPair TPair::operator++(int notused) {
    second++;
    transfer(update());
    return *this;
}
TPair TPair::operator--() {
    --second;
    transferBack(update());
    return *this;
}
TPair TPair::operator--(int notused) {
    second--;
    transferBack(update());
    return *this;
}

int TPair::update() { return second; }

void TPair::transfer(int a) {
    if (second > (a - 1)) {
        first += second / a;
        second %= a;
    }
}

void TPair::transferBack(int a) {
    if (second < 0) {
        first--;
        second += a;
    }
    if (first < 0) {
        first = 0;
        second = 0;
    }
}



void TTime::print() {
    if (second < 10) cout << first << ":0" << second;
    else cout << first << ":" << second;
}

int TTime::update() { // максимальное значение второго числа
    return 60;
}



void TMoney::print() {
    if (second < 10) cout << first << ".0" << second;
    else cout << first << "." << second;
}

int TMoney::update() {
    return 100;
}
