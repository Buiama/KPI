def str_func(str):  # створюємо функцію
    str_new = str.split()  # розбиваємо рядок на масив слів
    for i in range(len(str_new) - 1, -1, -1):
        if len(str_new[i]) != k:  # якщо підходить, то залишаємо, все інше видаляємо
            del str_new[i]
    print(' '.join(str_new))  # виводимо результат


str = input("Enter string: ")
k = int(input("Amount of letters in words: "))
str_func(str)


# Інший варінт(вручну)
#
# def clear(str):
#     for i in range(1, len(str)):
#         if not str[i - 1].isalpha() and not str[i].isalpha():
#             str.erase(i, 1)
#             i -= 1
#     return str
#
#
# def makesentence(str):
#     str.lstrip()
#     str.rstrip()
#     for i in range(len(str)):
#         if not str[i].isalpha():
#             str.replace(str[i], " ", 1)
#     return str
#
#
# def output(str):
#     for i in range(len(str)):
#         if len(str[i]) == k:
#             print(str[i])
#
#
# str1 = input("Your string: ")
# k = int(input("Amount of letters in words: "))
# clear(str)
# makesentence(str)
# res = str.split(" ")
# output(str)
