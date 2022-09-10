from random import randint
from TStorage import *


n = int(input("Enter the number of pairs: "))
arr = [None] * n
for i in range(n):
    b = TTime(randint(0, 23), randint(0, 59))
    c = TMoney(randint(0, 99), randint(0, 99))
    arr[i] = TStorage(b, c)
    print(f'\ni = {i + 1}:')
    b.printT()
    c.printT()
    print("To pay:", round(arr[i].getRes(), 2))

print()
a = TTime(5, 0)
a.printT()
a.ink()
a.printT()
a.dec()
a.dec()
a.printT()

print()
d = TMoney(0, 99)
d.printT()
# d.dec()
# d.printT()
d.ink()
d.ink()
d.printT()
