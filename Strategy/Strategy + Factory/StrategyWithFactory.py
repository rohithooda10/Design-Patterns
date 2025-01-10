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

class PaymentStrategyFactory:
    def get_strategy(self, name: str, balance: int):
        if name == "PayPal":
            return PayPal(balance)
        else:
            return CreditCard(balance)
    

class PaymentManager:
    def pay(self, strategy: PaymentStrategy, amount):
        if strategy.check_balance(amount):
            strategy.pay(amount)

if __name__ == "__main__":
    balance = 1000
    bill = 500
    strategy = "CreditCard"
    factory = PaymentStrategyFactory()
    payment_strategy = factory.get_strategy(strategy, balance)
    payment_manager = PaymentManager()
    payment_manager.pay(payment_strategy, bill)