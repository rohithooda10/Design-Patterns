from abc import ABC, abstractmethod

class PaymentStrategy(ABC):
    balance: int
    
    @abstractmethod
    def check_balance(sel, amount) -> bool:
        pass

    @abstractmethod
    def pay(self, amount):
        pass

class PayPal(PaymentStrategy):
    balance: int
    def __init__(self, balance):
        self.balance = balance

    def check_balance(self, amount):
        print("Verification being done by PayPal")
        if self.balance - amount < 0:
            return False
        return True

    def pay(self, amount):
        print("Paid by PayPal")
        self.balance -= amount

class CreditCard(PaymentStrategy):
    balance: int
    def __init__(self, balance):
        self.balance = balance

    def check_balance(self, amount):
        print("Verification being done by Credit Card")
        if self.balance - amount < 0:
            return False
        return True

    def pay(self, amount):
        print("Paid by Credit Card")
        self.balance -= amount

class PaymentManager:
    strategy: PaymentStrategy
    def __init__(self, payment_strategy: PaymentStrategy):
        self.strategy = payment_strategy
    def verify(self, amount):
        self.strategy.check_balance(amount)
    def pay(self, amount):
        if self.strategy.check_balance(amount):
            self.strategy.pay(amount)

if __name__ == "__main__":
    balance = 1000
    bill = 500
    strategy = "CreditCard"

    if strategy == "CreditCard":
        payment_strategy = CreditCard(balance)
    else:
        payment_strategy = PayPal(balance)
        
    payment_manager = PaymentManager(payment_strategy)
    
    payment_manager.pay(bill)