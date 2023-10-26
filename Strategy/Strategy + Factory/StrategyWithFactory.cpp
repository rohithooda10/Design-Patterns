// Strategy + Factory
#include <iostream>
using namespace std;

// Strategy
class PaymentStrategy{
public:
    virtual void verify() = 0;
    virtual void pay(int amount) = 0;
};

// Concrete strategy
class CreditCardStrategy: public PaymentStrategy{
public:
    void verify()
    {
        cout<<"Credit card payment verified"<<endl;
    }
    void pay(int amount)
    {
        cout<<"Paid "<<amount<<" using credit card"<<endl;
    }
};

// Concrete strategy
class PaypalStrategy: public PaymentStrategy{
public:
    void verify()
    {
        cout<<"Paypal payment verified"<<endl;
    }
    void pay(int amount)
    {
        cout<<"Paid "<<amount<<" using paypal"<<endl;
    }
};

// Strategy Factory
class PaymentStrategyFactory{
public:
    PaymentStrategy* createStrategy(int method)
    {
        PaymentStrategy* strategy;
        if(method == 1) 
            strategy = new CreditCardStrategy();
        else strategy = new PaypalStrategy();
        return strategy;
    }
};

// Context
class PaymentManager{
    PaymentStrategy* strategy;
public:
    PaymentManager(PaymentStrategyFactory* paymentStrategyFactory, int method)
    {
        strategy = paymentStrategyFactory->createStrategy(method);
    }
    void pay(int amount)
    {
        strategy->verify();
        strategy->pay(amount);
    }
};

int main() {
    int method;
    cout<<"Enter payment method: 1. Credit card 2. Paypal - ";
    cin>>method;
    PaymentStrategyFactory* paymentStrategyFactory = new PaymentStrategyFactory();
    cout<<endl;
    PaymentManager* paymentManager = new PaymentManager(paymentStrategyFactory, method);
    paymentManager->pay(100);
}