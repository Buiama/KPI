#include "Class.h"

/*double TCubic::getA() {
    return a;
}
double TCubic::getB() {
    return b;
}
double TCubic::getC() {
    return c;
}
double TCubic::getD() {
    return d;
}
void TCubic::setA(double a3) {
    a = a3;
}
void TCubic::setB(double a2) {
    b = a2;
}
void TCubic::setC(double a1) {
    c = a1;
}
void TCubic::setD(double a0) {
    d = a0;
}*/
double TCubic::getMin() {
    return min;
}
void TCubic::setMin(double m) {
    min = m;
}
void TCubic::findMin(double aMin, double bMax, double e) { // находим минимум функции
    double min, current, newE;
    newE = e / 2;
    min = a * pow(aMin, 3) + b * pow(aMin, 2) + c * aMin + d;
    for (double x = aMin + e; x <= bMax; x += newE) {
        current = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
        //13.48651358952 -> 13.4865 при e=0.0001  - пон€тие точности в этой задаче
        if (current < min) min = current;
        min = round(min * (1 / e)) / (1 / e);
    }
    setMin(min);
}
void TCubic::printEquation() { // красивый вывод цельного уравнени€
    if (b < 0) {
        if (c < 0) {
            if (d < 0) cout << a << "x^3 - " << abs(b) << "x^2 - " << abs(c) << "x - " << abs(d);
            else cout << a << "x^3 - " << abs(b) << "x^2 - " << abs(c) << "x + " << d;
        }
        else {
            if (d < 0) cout << a << "x^3 - " << abs(b) << "x^2 + " << c << "x - " << abs(d);
            else cout << a << "x^3 - " << abs(b) << "x^2 + " << c << "x + " << d;
        }
    }
    else {
        if (c < 0) {
            if (d < 0) cout << a << "x^3 + " << b << "x^2 - " << abs(c) << "x - " << abs(d);
            else cout << a << "x^3 + " << b << "x^2 - " << abs(c) << "x + " << d;
        }
        else {
            if (d < 0) cout << a << "x^3 + " << b << "x^2 + " << c << "x - " << abs(d);
            else cout << a << "x^3 + " << b << "x^2 + " << c << "x + " << d;
        }
    }
}