#include <iostream>
#include <set>
using namespace std;

// Observer
class Observer{
public:
    virtual void notify() = 0;
};

// Concrete observer - implements notify function
class ConcreteObserver: public Observer{
    string name;
public:
    ConcreteObserver(string n)
    {
        name = n;
    }
    void notify()
    {
        cout<<"I, "<<name<<" is notifed"<<endl;
    }
};

// Notifier subject
class Subject{
    set<Observer*> observers;
public:
    void updateStatus()
    {
        notifyObservers();
    }
    void attach(Observer* observer)
    {
        observers.insert(observer);
    }
    void detach(Observer* observer)
    {
        observers.erase(observer);
    }
    void notifyObservers()
    {
        for(auto& obs: observers)
        {
            obs->notify();
        }
    }
};

int main() {
    Subject* order = new Subject();
    Observer* customer = new ConcreteObserver("Customer");
    Observer* delivery = new ConcreteObserver("Delivery");
    order->attach(customer);
    order->attach(delivery);
    order->updateStatus();
    order->detach(delivery);
    cout<<"After detaching..."<<endl;
    order->updateStatus();
}