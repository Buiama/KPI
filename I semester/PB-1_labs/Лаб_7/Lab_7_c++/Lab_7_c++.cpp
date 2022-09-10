#include <iostream>
using namespace std;

void input(int*, int); // ініціалізуємо функції
void createArr(int*, int);

void output(int*, int);
int* minMax(int*, int);
int subtraction(int* );
int* replace(int*, int);

int main()
{
    int n;
    cout << "Amount of elements: "; cin >> n; // задаємо довжину масиву
    int* b = new int[n]; // створюємо масив
    input(b, n);
    //createArr(b, n);
    cout << "\nArray B(" << n << "): ";
    output(b, n);
    cout << "\nArray MinMax[min,max,minIndex]: ";
    output(minMax(b, n),3);
    cout << "\nmax-min = " << subtraction(minMax(b, n));
    cout << "\n\nFinal array: ";
    output(replace(b, n), n);
}

void input(int* arr, int length) { // функція для вводу значень масиву з клавіатури
    for (int i = 0; i < length; i++) {
        cout << "b[" << i << "] = "; cin >> arr[i];
    }
}

void createArr(int *arr, int length) { // функція для автоматичного генерування значень масиву
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 20001 - 10000; // в проміжку [-10000;10001)
        cout << "b[" << i << "] = " << arr[i] << endl;
    }
}

void output(int *arr, int length) { // функція для виводу масива в консоль
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}

int* minMax(int *arr, int length) { // функція для знаходження мінімального, максимального елементів та індексу мін. ел.
    int* minMax = new int[3];
    minMax[0] = arr[0];
    minMax[1] = arr[0];
    minMax[2] = 0;
    for (int i = 1; i < length; i++) { // в одному циклі знаходимо екстремуми та індекс
        if (arr[i] < minMax[0]) { // Щоб не писати два масиви, які виконують одне й те ж))
            minMax[0] = arr[i];
            minMax[2] = i;
        }
        if (arr[i] > minMax[1]) {
            minMax[1] = arr[i];
        }
    }
    return minMax;
}

int subtraction(int* minMax) { // функція для знаходження різниці між максимальним та мінімальним елементом
    return minMax[1] - minMax[0];
}

int* replace(int *arr, int length) { // функція, що міняє мінімальний та останній елемент масиву
    int tmp = arr[length - 1];
    arr[length - 1] = minMax(arr,length)[0];
    arr[minMax(arr,length)[2]] = tmp;
    return arr;
}