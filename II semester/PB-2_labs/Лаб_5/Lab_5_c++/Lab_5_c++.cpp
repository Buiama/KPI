#include "Classes.h"
#include "Storage.h"
#include "Functions.h"


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian"); // для '№'
    //system("color 02"); зелёненький текст))
    int n = input();
    cout << " № | Hours worked | Price per minute | To pay" << endl;

    TStorage* arr = new TStorage[n];
    for (int i = 0; i < n; i++) {
        TTime b;
        TMoney c;
        arr[i] = TStorage(b, c);
        beautifyOut(i, b, c, arr);
    }

    cout << "Total: " << arr[n-1].getTotal();

    int fTime, sTime;
    cout << "\nEnter hours: "; cin >> fTime;
    cout << "Enter minutes: "; cin >> sTime;
    invalidInputTT(sTime);
    TTime a(fTime, sTime);
    output(a);

    int fMoney, sMoney;
    cout << "\nEnter hryvnias: "; cin >> fMoney;
    cout << "Enter kopecks: "; cin >> sMoney;
    invalidInputTM(sMoney);
    TMoney d(fMoney, sMoney);
    output(d);

    delete[] arr;
}