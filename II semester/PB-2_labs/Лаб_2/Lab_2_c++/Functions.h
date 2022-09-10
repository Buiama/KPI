#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct TTalk {
    char number[35];
    char start[6], end[6];
    int hs, ms;
    int he, me;
};

bool validLetters(string);
void validSpaces(string&);
void validDuplicates(string&);
bool find(string);
string validNumbers(string);
void validTime(string, int&, int&);
string timeToString(int, int);
void setTime(int, int, int, int, TTalk&, int&);
bool tooLongCondition(int, int, int, int, int, int, int, int);
void writeText(int&, string, string);
TTalk* readFile(int, string);
void output(int, TTalk*);
void writeDayNightFile(string, string, TTalk*, int, int&, int&);