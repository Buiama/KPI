#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class TPair {
protected:
    int first;
    int second;
public:
    int getFirst();
    void setFirst(int a);
    int getSecond();
    void setSecond(int b);
    virtual void print();//вывод с использованием полиморфизма
    TPair(int a, int b) : first(a), second(b) {}
    TPair() {}
    ~TPair() {}
    TPair operator++();//перегруженные операторы для инкрементации
    TPair operator++(int notused);
    TPair operator--();
    TPair operator--(int notused); // или декрементации
    virtual int update(); // виртуальная функция для операторов
    void transfer(int a);
    void transferBack(int a);
};

class TTime : public TPair {
public:
    TTime() :TPair(rand() % 24, rand() % 60) {}
    TTime(int a, int b) :TPair(a, b) {}
    ~TTime() {}
    void print() override;
    int update() override;
};

class TMoney : public TPair {
public:
    TMoney() : TPair(rand() % 100, rand() % 100) {}
    TMoney(int a, int b) :TPair(a, b) {}
    ~TMoney() {}
    void print() override;
    int update() override;
};