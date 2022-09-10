#include "Class.h"


double TMatrix::getEl(int i, int j) {
    return matrix[i][j];
}
double TMatrix::getNormaE() {
    return normaEuclid;
}
void TMatrix::setNormaE(double euclid) {
    normaEuclid = euclid;
}
double TMatrix::getNormaM() {
    return normaM;
}
void TMatrix::setNormaM(double m) {
    normaM = m;
}
double TMatrix::getNormaL() {
    return normaL;
}
void TMatrix::setNormaL(double l) {
    normaL = l;
}

TMatrix::TMatrix(const TMatrix& other) { // конструктор копирования
    n = other.n;
    matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
TMatrix::TMatrix(int dimention) { // конструктор для рандомного заполнения
    n = dimention;
    srand(time(NULL));
    matrix = new double* [dimention];
    for (int i = 0; i < dimention; i++) {
        matrix[i] = new double[dimention];
        for (int j = 0; j < dimention; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}
TMatrix::TMatrix(int dimention, double number) { // конструктор для заполнения от нашего числа
    n = dimention;
    matrix = new double* [dimention];
    for (int i = 0; i < dimention; i++) {
        matrix[i] = new double[dimention];
        for (int j = 0; j < dimention; j++) {
            matrix[i][j] = number++;
        }
    }
}
TMatrix::~TMatrix() {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void TMatrix::findNormaM() { // поиск нормы М (максимальная из сумм рядов матрицы)
    double sum, max = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(matrix[i][j]);
        }
        if (max < sum) max = sum;
    }
    setNormaM(max);//normaM=max;
}
void TMatrix::findNormaL() { // поиск нормы L (максимальная из сумм столбцов матрицы)
    double sum, max = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(matrix[j][i]);
        }
        if (max < sum) max = sum;
    }
    normaL = max;//setNormaL(max);
}
void TMatrix::findNormaE() { // поиск Эвклидовой нормы (корень из сумм квадратов всех элементов)
    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += pow(matrix[i][j], 2);
        }
    }
    sum = sqrt(sum);
    normaEuclid = sum;//setNormaE(sum);
}

void TMatrix::print() { // вывод
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(9) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "Norm M = " << normaM << endl;
    cout << "Norm L = " << normaL << endl;
    cout << "Norm E = " << normaEuclid << endl << endl;;
}

TMatrix TMatrix::operator+(const TMatrix& obj) const { // перегрузка оператора плюс
    TMatrix tmp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
        }
    }
    return tmp;
}
TMatrix TMatrix::operator*(const TMatrix& obj) const { // перегрузка оператора умножения
    TMatrix tmp(n, 1);
    double s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s = 0;
            for (int k = 0; k < n; k++) {
                s += matrix[i][k] * obj.matrix[k][j];
            }
            tmp.matrix[i][j] = s;
        }
    }
    return tmp;
}
void TMatrix::operator=(const TMatrix& obj) { // перегрузка оператора равенства
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    n = obj.n;
    matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = obj.matrix[i][j];
        }
    }
}