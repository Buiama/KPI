from TPair import TPair


class TMoney(TPair):
    def __init__(self, first: int, second: int):
        super().__init__(first, second)

    def printT(self):
        if self.second < 10:
            print(f'Price per minute: {self.first}.0{self.second}')
        else:
            print(f'Price per minute: {self.first}.{self.second}')

    def updated(self):
        return 100
