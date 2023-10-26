#include <iostream>
using namespace std;

// Handler 
class Handler{
public:
    Handler* nextHandler;
    virtual void handle() = 0;
    virtual void setNextHandler(Handler* handler) = 0;
};

// Concrete handlers
class Manager: public Handler{
public:
    Handler* nextHandler;
    void handle()
    {
        cout<<"Request was handled by Manager"<<endl;
        if(nextHandler)
            nextHandler->handle();
    }
    void setNextHandler(Handler* handler)
    {
        nextHandler = handler;
    }
};

class HR: public Handler{
public:
    Handler* nextHandler;
    void handle()
    {
        cout<<"Request was handled by HR"<<endl;
        if(nextHandler)
            nextHandler->handle();
    }
    void setNextHandler(Handler* handler)
    {
        nextHandler = handler;
    }
};

class CTO: public Handler{
public:
    Handler* nextHandler;
    void handle()
    {
        cout<<"Request was handled by CTO"<<endl;
        if(nextHandler)
            nextHandler->handle();
    }
    void setNextHandler(Handler* handler)
    {
        nextHandler = handler;
    }
};

int main() {
    Handler* cto = new CTO();
    Handler* hr = new HR();
    Handler* manager = new Manager();
    manager->setNextHandler(hr);
    hr->setNextHandler(cto);
    cto->setNextHandler(NULL);
    manager->handle();
}