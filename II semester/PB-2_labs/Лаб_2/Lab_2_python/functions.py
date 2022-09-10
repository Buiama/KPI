import pickle


def writeText(name, a, count):
    yn = "y"
    if a == '':  # случай, если нужно дозаписать файл
        outFile = open(name, 'wb')
    else:
        outFile = open(name, 'ab')
    while yn[0] == 'y' or yn[0] == '1' or yn[0] == '+':
        talkT = {
            "number": getNumber(),
            "start": getTime(),
            "end": getTime()
        }
        setStart(talkT, talkT["start"])
        setEnd(talkT, talkT["end"])

        # разбиение на брейках + полный оборот часов
        if talkT["hs"] < 6 and talkT["he"] == 20 and talkT["me"] == 0:
            setTime(talkT["start"], "6:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("6:00", "20:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["hs"] < 6 and talkT["he"] == 6 and talkT["me"] == 0:
            setTime(talkT["start"], talkT["end"], talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["hs"] == talkT["he"] and talkT["me"] == talkT["ms"]:
            setTime(talkT["start"], talkT["end"], talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["hs"] < 20 and talkT["he"] == 6 and talkT["me"] == 0:
            setTime(talkT["start"], "20:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("20:00", "6:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["hs"] < 20 and talkT["he"] == 20 and talkT["me"] == 0:
            setTime(talkT["start"], talkT["end"], talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["he"] < 6 and talkT["hs"] == 6 and talkT["ms"] == 0:
            tmpE = talkT["end"]
            setTime(talkT["start"], "20:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("20:00", tmpE, talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif longCondition(talkT["hs"], talkT["he"], talkT["ms"], talkT["me"]):
            tmpE = talkT["end"]
            setTime(talkT["start"], "6:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("6:00", "20:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("20:00", tmpE, talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["he"] >= 6 and talkT["hs"] < 20 and (
                talkT["hs"] > talkT["he"] or talkT["hs"] == talkT["he"] and talkT["ms"] > talkT["me"]):
            tmpE = talkT["end"]
            setTime(talkT["start"], "20:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("20:00", "6:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("6:00", tmpE, talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["hs"] < 6 <= talkT["he"]:
            tmpE = talkT["end"]
            setTime(talkT["start"], "6:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("6:00", tmpE, talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["he"] >= 20 > talkT["hs"] or 20 > talkT["hs"] >= 6 > talkT["he"]:
            tmpE = talkT["end"]
            setTime(talkT["start"], "20:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("20:00", tmpE, talkT)
            pickle.dump(talkT, outFile)
            count += 1
        elif talkT["hs"] > 20 > talkT["he"] > 6:
            tmpE = talkT["end"]
            setTime(talkT["start"], "6:00", talkT)
            pickle.dump(talkT, outFile)
            count += 1

            setTime("6:00", tmpE, talkT)
            pickle.dump(talkT, outFile)
            count += 1
        else:
            setTime(talkT["start"], talkT["end"], talkT)
            pickle.dump(talkT, outFile)
            count += 1

        yn = input('\nContinue? [Y/N]: ').lower()
    outFile.close()
    return count


def getNumber():  # ввод номера
    number = input("Number: ")
    number = validDuplicates(number)
    if len(number) < 1 or len(number) > 33 or validLetters(number):  # проверка на валидность
        print('This number does not exist, please, try again')
        number = getNumber()
        return number
    return number


def validDuplicates(data):  # убираем дубликаты, которые не являются цифрами
    ind = 1
    for i in range(1, len(data)):
        if not data[ind - 1].isdigit() and not data[ind].isdigit():
            data = data[:ind] + data[(ind + 1):]
            ind -= 1  # со счетчиком фор в питоне особо не поработаещь,
        ind += 1  # поэтому выкручиваемся как можем
    return data


def validLetters(data):  # проверка на наличие букв
    for i in data:
        if i.isalpha():
            return True
    return False


def getTime():  # ввод времени начала/конца
    time = input("Start/End: ")
    time = validSpaces(time)
    time = validDuplicates(time)
    if len(time) < 3 or len(time) > 5 or validLetters(time) or time.find(':') == -1:  # проверка на правильный ввод
        print('Time entered incorrectly, please, try again')
        time = getTime()
        return time
    if time.find(':') == 0 or time.find(':') == len(time) - 1:
        print('Time entered incorrectly, please, try again')
        time = getTime()
        return time
    hours = time[:time.find(':')]
    minutes = time[time.find(':') + 1:]
    hours = validTime(hours)
    minutes = validTime(minutes)

    if int(hours) > 23 or int(minutes) > 59:
        print('Time entered incorrectly, please, try again')
        time = getTime()
        return time

    if int(minutes) < 10 and minutes[0] != '0' and len(minutes) < 2:  # делаем "красивое" время
        time = hours + ':0' + minutes
    else:
        time = hours + ':' + minutes

    return time


def validSpaces(data):  # убираем все пробелы
    ind = 1
    for i in range(1, len(data)):
        if data[ind].isspace():
            data = data[:ind] + data[(ind + 1):]
            ind -= 1
        ind += 1
    return data


def validTime(time):  # оставляем только цифры
    tmpT = "".join(c for c in time if c.isdecimal())
    return tmpT


def setStart(struct, time):  # записываем часы и минуты начала
    struct["hs"] = getHours(time)
    struct["ms"] = getMinutes(time)


def setEnd(struct, time):  # записываем часы и минуты конца
    struct["he"] = getHours(time)
    struct["me"] = getMinutes(time)


def getHours(time):  # получаем часы
    hours = int(validTime(time[:time.find(':')]))
    return hours


def getMinutes(time):  # получаем минуты
    minutes = int(validTime(time[time.find(':') + 1:]))
    return minutes


def setTime(start, end, struct):  # устанавливаем время
    struct["start"] = start
    struct["end"] = end
    setStart(struct, start)
    setEnd(struct, end)
    print(struct["number"], struct["start"], struct["end"])


def longCondition(hs, he, ms, me):  # сборник условий
    if hs < 6 and he >= 20:
        return True
    elif hs < 6 and (hs > he or hs == he and ms > me):
        return True
    elif hs == 6 and ms == 0 and hs > he:
        return True
    elif he >= 20 and (hs > he or hs == he and ms > me):
        return True
    else:
        return False


def readFile(name, count):  # читаем файл в массив
    file = open(name, 'rb')
    doc = []
    for i in range(0, count):
        doc.append(pickle.load(file))
    return doc


def output(arr, count):  # выводим содержание файла, который записали в массив
    for i in range(0, count):
        print(arr[i]["number"] + " " + arr[i]["start"] + " " + arr[i]["end"])


# по условию создаем два файла с дневными/ночными разговорами
def writeDayNightFile(name_day, name_night, doc, count):
    outFileDay = open(name_day, 'wb')
    outFileNight = open(name_night, 'wb')
    countD = 0
    countN = 0
    for i in range(0, count):
        if doc[i]["hs"] >= 6 and (doc[i]["he"] < 20 or doc[i]["he"] == 20 and doc[i]["me"] == 0):
            if doc[i]["he"] > doc[i]["hs"] or doc[i]["he"] == doc[i]["hs"] and doc[i]["me"] >= doc[i]["ms"]:
                pickle.dump(doc[i], outFileDay)
                countD += 1
            else:
                pickle.dump(doc[i], outFileNight)
                countN += 1
        else:
            pickle.dump(doc[i], outFileNight)
            countN += 1
    outFileDay.close()
    outFileNight.close()
    return countD, countN
