'''
https://leetcode.com/problems/simple-bank-system/description/
'''

class Bank:

    def __init__(self, balance: List[int]):
        self.balance = balance
        self.arr = []
        self.arr.append(self.balance)

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if(0<account2<=len(self.arr[0]) and 0<account1<=len(self.arr[0]) and self.arr[0][account1-1] >= money):
            self.arr[0][account2-1] += money
            self.arr[0][account1-1] -= money
            return True
        return False

    def deposit(self, account: int, money: int) -> bool:
        if(0<account<=len(self.arr[0])):
            self.arr[0][account-1] += money
            return True
        return False

    def withdraw(self, account: int, money: int) -> bool:
        if(0<account<=len(self.arr[0]) and self.arr[0][account-1] >= money):
            self.arr[0][account-1] -= money
            return True
        return False
        


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
