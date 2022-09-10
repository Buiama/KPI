#include <iostream>
using namespace std;

void input(int**, int); // ініціалізуємо функції
void output(int, int, int**);
void sort(int, int**);
void vectorX(int**, int**, int);
void createMatrix(int**, int);

int main()
{
    int n;
    cout << "n = "; // задаємо розмірність квадратної матриці
    cin >> n; cout << endl;
    int** b = new int* [n]; // створюємо матрицю
    input(b, n);
    //createMatrix(b, n); // альтернативний ввід
    cout << "\nYour matrix A("<<n<<" x "<<n<<"):\n";
    output(n, n, b);
    sort(n, b);
    cout << "\nSorted matrix:\n";
    output(n, n, b);
    int** x = new int* [n];
    vectorX(b, x, n);
    cout << "\nVector X(n):\n";
    output(n, 1, x);
}

void input(int** matrix, int n) { // функція для введення значень матриці з клавіатури
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

void createMatrix(int** matrix, int n) { // функція для автоматичного генерування значень матриці
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void output(int m, int n, int** matrix) { // функція для виводу матриці в консоль
    for (int i = 0; i < m; i++) {
        cout << endl;
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
}

void sort(int n, int** matrix) { // функція для сортування єлементів матриці за умовою
    bool isSorted = false;
    int* buf = new int[n];
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (matrix[i][0] < matrix[i + 1][0]) {
                isSorted = false;

                for (int j = 0; j < n; j++) {
                    buf[j] = matrix[i][j];
                    matrix[i][j] = matrix[i + 1][j];
                    matrix[i + 1][j] = buf[j];
                }
            }
        }
    }
}

void vectorX(int** matrix, int** vector, int n) { // функція для отримання вектору
    for (int i = 0; i < n; i++) {
        vector[i] = new int[1];
        vector[i][0] = matrix[i][i];
    }
}