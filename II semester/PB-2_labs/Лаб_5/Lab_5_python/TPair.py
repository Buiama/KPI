class TPair:
    def __init__(self, first: int, second: int):
        self.first = first
        self.second = second

    def get_first(self):
        return self.first

    def set_first(self, value: int):
        self.first = value

    def get_second(self):
        return self.second

    def set_second(self, value: int):
        self.second = value

    first1 = property(get_first, set_first)
    second2 = property(get_second, set_second)

    def ink(self):
        self.second += 1
        self.transfer(self.updated())

    def dec(self):
        self.second -= 1
        self.transferBack(self.updated())

    def updated(self):
        return self.second

    def transfer(self, tran: int):
        if self.second > (tran - 1):
            self.first += self.second // tran
            self.second %= tran

    def transferBack(self, tranB: int):
        if self.second < 0:
            self.first -= 1
            self.second += tranB
        if self.first < 0:
            self.first = 0
            self.second = 0

    def printT(self):
        print(self.first, " ", self.second)
