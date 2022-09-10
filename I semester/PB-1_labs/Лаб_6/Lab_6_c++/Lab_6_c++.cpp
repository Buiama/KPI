#include <iostream>
using namespace std;

int nsd(int a, int b);//ініціалізуємо функцію

int main()
{
    int a, b, c;//ініціалізуємо значення
    cin >> a >> b >> c;//вводимо значення
    cout << nsd(nsd(a, b), c);//виводимо результат НСД трьох чисел
}
int nsd(int a, int b) {//створюємо функцію по алгоритму Евкліда
    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;//повертаємо ообчислене НСД
}
