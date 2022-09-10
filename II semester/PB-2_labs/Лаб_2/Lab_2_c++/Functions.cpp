#include "Functions.h"


void writeText(int& counter, string fileName, string again) {
    TTalk b;
    string yn = "y";
    string number, start, end;
    ofstream outFile;
    if (again == "") outFile.open(fileName, ios::binary); // случай, если нужно дозаписать файл
    else outFile.open(fileName, ios::binary | ios::app);
    while (yn[0] == 'y' || yn[0] == 'Y' || yn[0] == '1' || yn[0] == '+') {
        cout << "Number: "; getline(cin, number);
        cout << "Start: "; getline(cin, start);
        cout << "End: "; getline(cin, end);
        if (validLetters(number) && validLetters(start) && validLetters(end)) {

            validSpaces(number); validSpaces(start); validSpaces(end);
            validDuplicates(number); validDuplicates(start); validDuplicates(end);

            if (find(start) && find(end)) {
                validTime(start, b.hs, b.ms);
                validTime(end, b.he, b.me);
                if (b.hs > 23 || b.ms > 59 || b.he > 23 || b.me > 59) {
                    cout << " акое-то странное у вас врем€!)" << endl;
                }
                else if (number.length() > 33) {
                    cout << "я проверил все номера мира, при любом вводе. “аких длинных не существует!" << endl;
                }
                else {
                    strcpy_s(b.number, number.c_str());
                    int tmpH, tmpM; //temporary hours/minutes
                    int dBreakH = 6, dBreakM = 0;  // Day break hours/minutes
                    int nBreakH = 20, nBreakM = 0; // Night break hours/minutes

                    // рассматриваем на брейках, чтобы не мешали последующим услови€м
                    if (b.hs < dBreakH && b.he == nBreakH && b.me == nBreakM) {
                        setTime(b.hs, b.ms, dBreakH, dBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(dBreakH, dBreakM, nBreakH, nBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    else if (b.hs < dBreakH && b.he == dBreakH && b.me == dBreakM) {
                        setTime(b.hs, b.ms, dBreakH, dBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    else if (b.he == b.hs && b.me == b.ms) {
                        setTime(b.hs, b.ms, b.he, b.me, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    else if (b.hs < nBreakH && b.he == dBreakH && b.me == dBreakM) {
                        setTime(b.hs, b.ms, nBreakH, nBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(nBreakH, nBreakM, dBreakH, dBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    else if (b.hs < nBreakH && b.he == nBreakH && b.me == nBreakM) {
                        setTime(b.hs, b.ms, nBreakH, nBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    else if (b.he < dBreakH && b.hs == dBreakH && b.ms == dBreakM) {
                        tmpH = b.he; tmpM = b.me;
                        setTime(b.hs, b.ms, nBreakH, nBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(nBreakH, nBreakM, tmpH, tmpM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }

                    // проход через два брейка
                    else if (tooLongCondition(b.hs, b.he, b.ms, b.me, dBreakH, dBreakM, nBreakH, nBreakM)) {
                        tmpH = b.he; tmpM = b.me;
                        setTime(b.hs, b.ms, dBreakH, dBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(dBreakH, dBreakM, nBreakH, nBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(nBreakH, nBreakM, tmpH, tmpM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    // полный оборот часов между 6:00 и 20:00
                    else if (b.he >= dBreakH && b.hs < nBreakH && (b.hs > b.he || (b.hs == b.he && b.ms > b.me))) {
                        tmpH = b.he; tmpM = b.me;
                        setTime(b.hs, b.ms, nBreakH, nBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(nBreakH, nBreakM, dBreakH, dBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(dBreakH, dBreakM, tmpH, tmpM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }

                    // проход через один брейк
                        // дневной брейк [0:00; 6:00) и [6:00; 20:00)
                    else if (b.hs < dBreakH && b.he >= dBreakH) {
                        tmpH = b.he; tmpM = b.me;
                        setTime(b.hs, b.ms, dBreakH, dBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(dBreakH, dBreakM, tmpH, tmpM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    // ночной брейк [0:00; 20:00) и [20:00; 24:00);(или) полный оборот часов между 6:00 и 20:00
                    else if (b.hs < nBreakH && b.he >= nBreakH || b.hs >= dBreakH && b.hs < nBreakH && b.he < dBreakH) {
                        tmpH = b.he; tmpM = b.me;
                        setTime(b.hs, b.ms, nBreakH, nBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(nBreakH, nBreakM, tmpH, tmpM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                    // полный оборот с 20:00 до 6:00-20:00
                    else if (b.hs > nBreakH && b.he > dBreakH && b.he < nBreakH) {
                        tmpH = b.he; tmpM = b.me;
                        setTime(b.hs, b.ms, dBreakH, dBreakM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));

                        setTime(dBreakH, dBreakM, tmpH, tmpM, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }

                    else {
                        setTime(b.hs, b.ms, b.he, b.me, b, counter);
                        outFile.write((char*)&b, sizeof(TTalk));
                    }
                }
            }
            else cout << "¬рем€ точно введено по шаблону?" << endl;
        }
        else cout << "¬рем€/номер телефона не должны содержать букв)" << endl;

        cout << "\nContinue? [Y/N]: "; cin >> yn; cin.ignore();
    }
    outFile.close();
}

bool validLetters(string data) { // если есть буквы, то не подходит
    for (int i = 0; i < data.length(); i++) {
        if (isalpha(data[i])) return false;
    }   
    return true;
}

void validSpaces(string& data) { // убираем все пробелы
    for (int i = 0; i < data.length(); i++) {
        if (isspace(data[i])) {
            data.erase(i, 1);
            i--;
        }
    }
}

void validDuplicates(string& data) { // убираем лишние повтор€ющиес€ символы
    for (int i = 1; i < data.length(); i++) {
        if (!isdigit(data[i - 1]) && !isdigit(data[i])) {
            data.erase(i, 1);
            i--;
        }
    }
}

bool find(string line) { // провер€ем, есть ли ':' во времени
    if (line.length() < 3) return false; 
    for (int i = 1; i < line.length() - 1; i++) {// не первый и не последний символ
        if (line[i] == ':') return true;
    }
    return false;
}

void validTime(string time, int& hours, int& minutes) { // раздел€ем на часы и минуты
    string h, m;
    int ind = time.find(':');
    h = validNumbers(time.substr(0, ind));
    m = validNumbers(time.substr(ind + 1));
    hours = stoi(h);
    minutes = stoi(m);
}

string validNumbers(string time) { // убираем все лишнее
    for (int i = 0; i < time.length(); i++) {
        if (!isdigit(time[i])) {
            time.erase(i, 1);
            i--;
        }
    }
    return time;
}

void setTime(int hs, int ms, int he, int me, TTalk& b, int& counter) { // сохран€ем отвалидированные данные
    string start, end;
    start = timeToString(hs, ms);
    strcpy_s(b.start, start.c_str());
    end = timeToString(he, me);
    strcpy_s(b.end, end.c_str());
    b.hs = hs; b.ms = ms; b.he = he; b.me = me;
    cout << b.number << ' ' << b.start << ' ' << b.end << endl;
    counter++;
}

string timeToString(int hours, int minutes) { // превращаем в правильную строку
    string time;
    if (minutes < 10) time = to_string(hours) + ":0" + to_string(minutes);
    else time = to_string(hours) + ":" + to_string(minutes);
    return time;
}

// сборник условий с одинаковым действием
bool tooLongCondition(int hs, int he, int ms, int me, int dBreakH, int dBreakM, int nBreakH, int nBreakM) {
    if (hs < dBreakH && he >= nBreakH) return true; // до 6:00 и после 20:00
    else if (hs < dBreakH && (hs > he || hs == he && ms > me)) return true; // полный оборот часов до 6:00
    else if (hs == dBreakH && ms == dBreakM && hs > he) return true;
    else if (he >= nBreakH && (hs > he || hs == he && ms > me)) return true; // полный оборот часов после 20:00
    else return false;
}


TTalk* readFile(int counter, string fileName) { // читаем файл в массив
    TTalk b;
    int i = 0;
    cout << "counter = " << counter << endl;//!ToDo прибрать
    ifstream inFile(fileName, ios::binary);
    TTalk* docText = new TTalk[counter];

    while (inFile.read((char*)&b, sizeof(TTalk))) {
        docText[i] = b;
        i++;
    }

    inFile.close();
    return docText;
}


void output(int counter, TTalk* arr) { // выводим содержание файла, который записали в массив
    for (int i = 0; i < counter; i++) {
        cout << arr[i].number << " " << arr[i].start << " " << arr[i].end << endl;
    }
}

// по условию создаем два файла с дневными/ночными разговорами
void writeDayNightFile(string fileD, string fileN, TTalk* arr, int counter, int& countD, int& countN) {
    int dBreakH = 6, dBreakM = 0;
    int nBreakH = 20, nBreakM = 0;
    ofstream outFileDay(fileD, ios::binary);
    ofstream outFileNight(fileN, ios::binary);
    for (int i = 0; i < counter; i++) {
        // проверка на дневной файл
        if (arr[i].hs >= dBreakH && (arr[i].he < nBreakH || arr[i].he == nBreakH && arr[i].me == nBreakM)) {
            // пришлось разделить условие, чтобы оно не было слишком длинным
            if (arr[i].he > arr[i].hs || arr[i].he == arr[i].hs && arr[i].me >= arr[i].ms) {
                outFileDay.write((char*)&arr[i], sizeof(TTalk));
                countD++;
            }
            else {
                outFileNight.write((char*)&arr[i], sizeof(TTalk));
                countN++;
            }
        }
        else {
            outFileNight.write((char*)&arr[i], sizeof(TTalk));
            countN++;
        }
    }
    outFileDay.close();
    outFileNight.close();
}