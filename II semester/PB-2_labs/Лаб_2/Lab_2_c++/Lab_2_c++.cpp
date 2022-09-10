#include "Functions.h"

int main()
{
    setlocale(LC_ALL, "russian");
    /*
    * Время лучше вводить по шаблону [ЧЧ:ММ], но можно попробовать и по-другому,
    * Программа отвалидирует, что подходит, а что нет
    * 
    * По условию нам нужно разделить переговоры на дневные (6:00-20:00) и ночные,
    * Поэтому оператор будет уходить два раза в день на обед (в 6:00 и 20:00))
    * Например, если разговор начнется до 6:00, а закончится после,
    * то запись прервется на долю секунды и начнется снова.
    * (5:44-8:25 -> 5:44-6:00 и 6:00-8:25)
    * Собеседники не заметят разрыва, ведь это произойдет очень быстро)
    */
    cout << "Hello World!\n";
    string fileName = "MainFile.dat";
    string filenameDay = "Day.dat";
    string filenameNight = "Night.dat";
    int counter = 0;
    int dayCounter, nightCounter;
    string again;
    do {
        writeText(counter, fileName, again);

        TTalk* docText = readFile(counter, fileName);
        cout << "\nFrom Main binary file:" << endl;
        output(counter, docText);

        dayCounter = 0, nightCounter = 0;
        writeDayNightFile(filenameDay, filenameNight, docText, counter, dayCounter, nightCounter);

        TTalk* docDay = readFile(dayCounter, filenameDay);
        cout << "\nFrom Day binary file:" << endl;
        output(dayCounter, docDay);

        TTalk* docNight = readFile(nightCounter, filenameNight);
        cout << "\nFrom Night binary file:" << endl;
        output(nightCounter, docNight);

        cout << "\n\nDo you want to add something? [Y/N]: "; cin >> again; cin.ignore();
    } while (again[0] == 'y' || again[0] == 'Y' || again[0] == '1' || again[0] == '+');
}