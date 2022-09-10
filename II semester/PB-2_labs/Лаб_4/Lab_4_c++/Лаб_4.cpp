#include "Functions.h"
#include "Class.h"


int main()
{
    int n = input();
    double k = inputNum();

    TMatrix one(n), two(n,k);
    cout << "Your randomly generated M1:" << endl;
    findNorm(one); one.print();

    cout << "Your M2 filled with " << k << ": " << endl;
    findNorm(two); two.print();

    double** m = inputM(n);
    TMatrix three(n, m);
    cout << "\nYour own M3: " << endl;
    findNorm(three); three.print();
    
    three = one + two;
    cout << "Sum M1 + M2:" << endl;
    findNorm(three); three.print();

    three = (three * three);
    cout << "Squared M3:" << endl;
    findNorm(three); three.print();

    cout << "First (random) M1:" << endl; // показываем, что начальные значения
    one.print(); 
    cout << "Second (filled) M2:" << endl; // не изменились
    two.print();
}