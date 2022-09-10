from TTime import TTime
from TMoney import TMoney


class TStorage:
    def __init__(self, time: TTime, money: TMoney):
        self.time = time
        self.money = money
        self.result = calculate(time, money)
        #  self.total += self.result

    def getRes(self):
        return self.result

    def setRes(self, value: float):
        self.result = value


def calculate(a: TTime, b: TMoney):
    minutes = a.first1 * 60 + a.second2
    price = b.first1 + b.second2 * 0.01
    return minutes * price
