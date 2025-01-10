// Simple Strategy

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

// Context
class PaymentManager{
    PaymentStrategy* strategy;
public:
    PaymentManager(PaymentStrategy* st)
    {
        strategy = st;
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
    PaymentStrategy* strategy;
    if(method == 1) 
        strategy = new CreditCardStrategy();
    else strategy = new PaypalStrategy();
    cout<<endl;
    PaymentManager* paymentManager = new PaymentManager(strategy);
    paymentManager->pay(100);
}