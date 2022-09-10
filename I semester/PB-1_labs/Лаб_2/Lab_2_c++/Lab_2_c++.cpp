#include <iostream>
using namespace std;
int main()
{
	double x, y; // значення координати точки
	cout << "x = "; cin >> x; // введення координати х
	cout << "y = "; cin >> y; // введення координати у
	if (abs(y) >= pow(x, 2) && abs(x) >= pow(y, 2)) cout << "\nYes, this point belongs to this plane\n"; // виводимо результат, якщо умова виконана
	else cout << "\nNo, this point does not belong to this plane\n"; // виводимо результат, якщо умова не виконана
}
