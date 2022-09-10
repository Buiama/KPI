# Press Shift+F10 to execute it or replace it with your code.

m = float(input("M = |ccc.ddd| = "))  # введемо число М у заданому вигляді ccc.ddd у форматі флоат
x = int(m)  # обчислення цілої частини
k = round((m - x) * 1000)  # обчислення дробової частини
y = k + x / 1000  # зведення до фінального числа
print(y)  # вивід результату


# s = round((m - int(m)) * 1000) + int(m) / 1000    # все в одній формулі
# print(s)
