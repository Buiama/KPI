#include <iostream>
#include <string>
using namespace std;

string clear(string); // ініціалізація функцій
string makeSentence(string,int&);
string* arrOfWords(string, string*);
void outputFinal(string*, int, int);

int main()
{
    string str;
    int k, w;
    w = 0;
    cout << "Your string: "; // вводимо рядок
    getline(cin, str);
    cout << "Amount of letters in words: "; // кількість букв у слові
    cin >> k;
    str = clear(str);
    str = makeSentence(str,w);
    cout << "Your string: " << str;
    cout << "\nAmount of words in the sentence: " << w << endl;
    string* res = new string[w];
    arrOfWords(str, res);
    cout << k << " letter words:";
    outputFinal(res, w, k);
}

/*  Можливо було зробити набагато простіше за допомогою вбудованих функцій, але нас попереджали, що ми будемо робити власні бібліотеки.
    Я хочу зробити заміну методу split(), якого нема в с++, за допомогою використовуємих функцій, тому робив вручну.
    І саме тому тут є деякі речі, які можна було обійти, наприклад, масив з словами, але для заміни split() це потрібно*/

string clear(string str) { // видаляє всі непотрібні елементи, які повторюються
    for (int i = 1; i < str.length(); i++) {// або можна int i = 1; i < str.length()-1; i++
        if (!isalpha(str[i - 1]) && !isalpha(str[i])) {// або можна isalpha(str[i - 1]) && !isalpha(str[i]) && !isalpha(str[i + 1])
            str.erase(i, 1);
            i--; // повертаємося, щоб перевірити всі оновлені елементи
        }
    }
    return str;
}

string makeSentence(string str,int& w) { // зводить до вигляду рядка
    if (!isalpha(str[0])) { // видаляє зайвий пробіл на початку речення
        str.erase(0, 1);
    }
    if (!isalpha(str[str.length() - 1])) { // видаляє зайвий пробіл на кінці речення
        str.erase(str.length() - 1, 1);
    }
    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str[i])) {
            str.replace(i, 1, " "); // замінює всі непотрібні елементи, які залишились, на пробіл
            w++;
        }
    }
    w = w + 1;
    return str;
}

string* arrOfWords(string str, string* res) { // робимо масив з слів речення
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isspace(str[i])) {
            j++;
        }
        else {
            res[j] += str[i];
        }
    }
    return res;
}

void outputFinal(string* res, int w, int k) { // виводимо потрібні нам слова
    for (int i = 0; i < w; i++) {
        if (res[i].length() == k) {
            cout << endl << res[i];
        }
    }
}

/*gh!yt!!!!!,_jh+gs , sts+;h ? - check phrase*/