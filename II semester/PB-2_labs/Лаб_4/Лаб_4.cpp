#include "Functions.h"
#include "Class.h"


class TMatrix {
    int n;
    double num;
    double** matrix;
    double normaM, normaL, normaEuclid;
public:
    double getEl(int i,int j);
    double getNormaM();
    void setNormaM(double m);
    double getNormaL();
    void setNormaL(double l);
    double getNormaE();
    void setNormaE(double euclid);
    TMatrix(int dimention); // random
    TMatrix(int dimention, double number); // all matrix contains number
    TMatrix(int dimension, double** matr) : n(dimension), matrix(matr) {}
    ~TMatrix() {};
    void findNormaM(); // ряды
    void findNormaL(); // столбцы
    void findNormaE(); // квадраты
    void print();
    TMatrix operator+(const TMatrix obj);
    TMatrix operator*(const TMatrix obj);
};

TMatrix::TMatrix(int dimention) {
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

TMatrix::TMatrix(int dimention, double number) {
    n = dimention;
    matrix = new double* [dimention];
    for (int i = 0; i < dimention; i++) {
        matrix[i] = new double[dimention];
        for (int j = 0; j < dimention; j++) {
            matrix[i][j] = number;
        }
    }
}
/*TMatrix::~TMatrix() {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}*/

double TMatrix::getEl(int i,int j) {
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
void TMatrix::findNormaM() {
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
void TMatrix::findNormaL() {
    double sum, max = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(matrix[j][i]);
        }
        if (max < sum) max = sum;
    }
    setNormaL(max);
}
void TMatrix::findNormaE() {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += pow(matrix[i][j], 2);
        }
    }
    sum = sqrt(sum);
    setNormaE(sum);
}
void TMatrix::print() {
    cout << "Your matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "Norm M = " << normaM << endl;
    cout << "Norm L = " << normaL << endl;
    cout << "Norm E = " << normaEuclid << endl;
}

TMatrix TMatrix::operator+(const TMatrix obj) {
    double** m = new double*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
        for (int j = 0; j < n; j++) {
            m[i][j] = matrix[i][j] + obj.matrix[i][j];
        }
    }
    TMatrix tmp(n, m);
    return tmp;
}
TMatrix TMatrix::operator*(const TMatrix obj) {
    double** m = new double* [n];
    TMatrix tmp(n, m);
    double s;
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
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

int main()
{
    cout << "Hello World!\n";
    int n;
    cin >> n;
    TMatrix one(n), two(n,2);
    double** m = new double* [n];
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
        for (int j = 0; j < n; j++) {
            m[i][j] = 1.2;
        }
    }
    TMatrix three(n, m);
    one.findNormaM(); two.findNormaM(); three.findNormaM();
    one.findNormaL(); two.findNormaL(); three.findNormaL();
    one.findNormaE(); two.findNormaE(); three.findNormaE();
    one.print(); two.print(); three.print();
    TMatrix four(n, 1);
    four = one+two;
    four.findNormaM(); four.findNormaL(); four.findNormaE();
    four.print();
    TMatrix five(n, 0.1);
    five = four * three;
    five.findNormaM(); five.findNormaL(); five.findNormaE();
    five.print();
    one.print(); two.print(); three.print(); four.print();
}