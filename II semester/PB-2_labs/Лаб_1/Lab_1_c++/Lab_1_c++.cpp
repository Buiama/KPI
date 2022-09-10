#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string writeText(int&);
void textToFile(string);
string* readFile(int);
void outputRFile(int, string*);
void plusDigit(int, string*);
void rewriteFile(int, string*);

int main()
{
    cout << "Press Enter to go to the next line\nPress Ctrl + [ to end writing\n\nEnter your text:\n";

    int counter = 0;
    
    string text = writeText(counter);

    cout << "\nYour text:\n\n" << text;

    cout << "\n\nnumber of lines = " << counter;
    
    textToFile(text);
    cout << "\n\nNow we can see in the file Text123.txt that everything is recorded!\n";
    
    string* docText = readFile(counter);
    
    cout << "\nThe contents of our file:\n";
    outputRFile(counter, docText);
    
    plusDigit(counter, docText);

    cout << "\n\nWe added numbers to the end of unpaired sentences:\n";
    outputRFile(counter, docText);
    
    rewriteFile(counter, docText);

    cout << "\n\nLook at the file! The numbers are added there!";
    cout << "\nThe contents of our file:\n";
    outputRFile(counter, docText);
}

string writeText(int& counter) { // ввод текста
    int ascii = 27; // ascii код комбінації клавіш Ctrl + [
    string text, line = " "; // теперь Ctrl + [ сработает !в любом месте строки!
    while (int(line[line.length() - 1]) != ascii) { // пока не нажато Ctrl + [ считываем текст
        getline(cin, line);
        counter++; // заодно считаем, сколько строк мы ввели
        text += line + '\n';
        if (line == "") line = " "; // для приема дублируищихся пустых строк
    }
    /*text.pop_back(); text.pop_back();*/ // другой вариант, как убрать
    text.erase(text.length() - 2, 2); // убираем \n (лишний абзац)
    return text;
}

void textToFile(string text) { // создание и запись в файл
    ofstream outFile("Text123.txt");
    outFile << text;
    outFile.close();
}

string* readFile(int counter) { // для считывания с файла
    ifstream inFile("Text123.txt"); // открываем файл для считывания
    /*if (!inFile) {
        cout << "Cannot open file :(\n";
    }*/
    string* docText = new string[counter]; // создаем массив для работы со строками
    int i = 0;
    while (!inFile.eof()) { // пока файл не закончился, считываем его
        getline(inFile, docText[i]);
        i++;
    }
    inFile.close(); // закрываем файл
    return docText;
}

void outputRFile(int counter, string* docText) { // вывод содержимого файла
    for (int i = 0; i < counter; i++) {
        cout << "\nString[" << i+1 << "]: " << docText[i];
    }
}

void plusDigit(int counter, string* docText) { // подсчет и добавление цифр в конец непарной строки
    int countDigit;
    for (int i = 0; i < counter; i += 2) { // проходимся по непарным строкам
        countDigit = 0;
        for (int j = 0; j < docText[i].length(); j++) {
            if (isdigit(docText[i][j])) {
                countDigit++; // считаем количество цифр в строке
            }
        }
        docText[i] += " count = "+ to_string(countDigit); // добавляем в конец строки количество цифр
    }
}

void rewriteFile(int counter, string* docText) { // перезапись файла с изменениями
    ofstream outFile("Text123.txt");
    for (int i = 0; i < counter - 1; i++) {
        outFile << docText[i] + "\n";
    }
    outFile << docText[counter - 1]; // от лишнего энтера в конце файла
    outFile.close();
}



//void addToFile(string);

/*
    cout << "\nIf you want to add something to the file print y";
    string yes;
    cin >> yes; cout<<endl;
    if (yes == "y") {
        text = writeText(counter);
        addToFile(text);
    }
*/

/*
void addToFile(string text) {
    ofstream outFile("Text123.txt", ios::app);
    outFile.open("Text123.txt", ios::app); outFile << text;
    outFile.close();
}
*/