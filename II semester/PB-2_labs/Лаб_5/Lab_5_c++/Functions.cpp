#include "Functions.h"


int input() {
    int n;
    cout << "Enter the number of pairs: "; cin >> n;
    invalidInput(n);
    cout << endl;
    return n;
}

void beautifyOut(int i, TTime time, TMoney money, TStorage* arr) {
    cout << setw(2) << (i + 1) << " |";
    cout << setw(6); time.print(); cout << setw(6) << "|";
    cout << setw(8); money.print(); cout << setw(8) << "|";
    cout << " " << fixed << setprecision(2) << arr[i].getRes() << endl;
}

void invalidInput(int& n) {
    while (!cin || n < 1) {
        cin.clear();
        cin.ignore(64, '\n');
        cout << "Your input is wrong, try again: "; cin >> n;
    }
}

void invalidInputTT(int& t) {
    while (!cin || t < 0 || t > 59) {
        cin.clear();
        cin.ignore(64, '\n');
        cout << "Your input is wrong, try again: "; cin >> t;
    }
}

void invalidInputTM(int& m) {
    while (!cin || m < 0 || m > 99) {
        cin.clear();
        cin.ignore(64, '\n');
        cout << "Your input is wrong, try again: "; cin >> m;
    }
}

void output(TTime a) {
    cout << "\nNew TTime object: "; a.print();
    a++;
    cout << "\nPostfix incrementing: "; a.print();
    ++a;
    cout << "\nPrefix incrementing: "; a.print();
    a--;
    cout << "\nPostfix decrementing: "; a.print();
    --a;
    cout << "\nPrefix decrementing: "; a.print();
    cout << endl;
}

void output(TMoney a) {
    cout << "\nNew TMoney object: "; a.print();
    a++;
    cout << "\nPostfix incrementing: "; a.print();
    a--;
    cout << "\nPostfix decrementing: "; a.print();
    --a;
    cout << "\nPrefix decrementing: "; a.print();
    ++a;
    cout << "\nPrefix incrementing: "; a.print();
    cout << endl;
}