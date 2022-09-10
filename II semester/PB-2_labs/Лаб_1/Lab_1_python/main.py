import keyboard


def WriteText():  # ввід тексту
    with open("Text1234.txt", 'wt', newline='\n') as file:  # at відкриваємо для запису
        print('Press Enter to go to the next line\nPress Ctrl + [ to end writing\n\nEnter your text:')
        text = ''
        while not (keyboard.is_pressed('space + [ + enter')):  # поки не натиснуто space + [ читаємо текст
            text += input() + '\n'  # запимуємо текст
        textNew = text[:-4]  # прибираємо зайві символи
        # якщо закінчуємо запис у тому ж рядку, то краще поставити -3
        file.write(textNew)  # заносимо до файлу


def ReadFile():  # считываем текст с файла читаємо текст з файлу
    file = open('Text1234.txt', 'rt')  # відкриваємо файл для читання
    text = file.read()
    file.close()  # закриваємо файл
    return text


def rowCounter(text):  # рахуємо кількість рядків у файлі
    if not text:
        count = 0
    else:
        count = 1
        for symbols in text:
            if symbols == '\n':
                count += 1
    return count


def sentence(count, text):  # додаємо в кінець кількість цифр у непарних рядках та записуємо до файлу
    text_digit = text.split('\n')  # робимо массив речень з тексту
    for i in range(0, count, 2):  # проходимося по непарних рядків
        counter = 0
        for j in range(len(text_digit[i])):  # проходимося по символам речень
            if text_digit[i][j].isdigit():  # рахуємо кількість цифр у рядку
                counter += 1
        text_digit[i] += " counter = " + str(counter)  # додаємо в кінець рядка
    text = "\n".join(text_digit)  # заносимо в одну змінну для запису у файл
    file = open('Text1234.txt', 'wt')  # відкриваємо файл для запису
    file.write(text)  # заносимо до файлу
    file.close()  # закриваємо файл
    return text


WriteText()  # ввід
print('Текст у вихідному файлі:')
textInFile = ReadFile()  # текст з файлу
print(textInFile)
countOfRow = rowCounter(textInFile)  # кількість рядків
print('\nКількість рядків у вихідному файлі:', str(countOfRow))

textFinal = sentence(countOfRow, textInFile)  # остаточний текст
print('\nФінальний текст у вихідному файлі:')
print(textFinal)

'''можна перевірити у самому файлі'''