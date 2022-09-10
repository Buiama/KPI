a = int(input("a = "))  # вводимо початкові значення
b = int(input("b = "))
c = int(input("c = "))


def nsd(x, y):  # створюємо функцію по алгоритму Евкліда
    while x != 0 and y != 0:
        if x > y:
            x %= y
        else:
            y %= x
    return x + y  # повертаємо НСД з уведених значень


print(nsd(nsd(a, b), c))  # виводимо результат
