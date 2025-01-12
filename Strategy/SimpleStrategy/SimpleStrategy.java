import java.util.*;

interface PaymentStrategy {
    boolean verify(int amount);
    boolean pay(int amount);
}

class PayPal implements PaymentStrategy{
    int balance;
    public PayPal(int b)
    {
        this.balance = b;
    }
    @Override
    public boolean verify(int amount){
        System.out.println("Verified by PayPal");
        return balance - amount >= 0;
    }
    @Override
    public boolean pay(int amount)
    {
        System.out.println("Paid by PayPal");
        this.balance -= amount;
        return true;
    }
}

class CreditCard implements PaymentStrategy{
    int balance;
    public CreditCard(int b)
    {
        this.balance = b;
    }
    @Override
    public boolean verify(int amount){
        System.out.println("Verified by CreditCard");
        return balance - amount >= 0;
    }
    @Override
    public boolean pay(int amount)
    {
        System.out.println("Paid by CreditCard");
        this.balance -= amount;
        return true;
    }
}

class PaymentManager{
    PaymentStrategy strategy;
    public PaymentManager(PaymentStrategy s)
    {
        this.strategy = s;
    }
    public boolean processPayment(int amount)
    {
        if(this.strategy.verify(amount))
            return this.strategy.pay(amount);
        return false;
    }
}

class Main {
    public static void main(String[] args)
    {
        PaymentStrategy strategy = new PayPal(1000);
        PaymentManager manager = new PaymentManager(strategy);
        manager.processPayment(100);
    }
}
