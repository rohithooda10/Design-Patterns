// Factory Method
#include <iostream>
using namespace std;

class IFoodItem{
public:
    virtual void getAppetizer() = 0;
    virtual void getMain() = 0;
    virtual void getDessert() = 0;
};
class IndianFoodItem:public IFoodItem
{
public:
    void getAppetizer(){
        cout<<"Paneer Tikka"<<endl;
    }
    void getMain(){
        cout<<"Paneer Kadai"<<endl;
    }
    void getDessert(){
        cout<<"Gulab Jamun"<<endl;
    }
};
class ItalianFoodItem:public IFoodItem
{
public:
    void getAppetizer(){
        cout<<"Pasta"<<endl;
    }
    void getMain(){
        cout<<"Pizza"<<endl;
    }
    void getDessert(){
        cout<<"Wine"<<endl;
    }
};
// Factory
class IFoodFactory{
public:
    virtual IFoodItem* createFactory() = 0;
};

// Indian Factory
class IndianFoodFactory:public IFoodFactory{
public:
    IFoodItem* createFactory()
    {
        return new IndianFoodItem();
    }
};

// Italian Factory
class ItalianFoodFactory:public IFoodFactory{
public:
    IFoodItem* createFactory()
    {
        return new ItalianFoodItem();
    }
};

int main() {
    string cusine;
    cout<<"Enter cusine type:";
    cin>>cusine;
    IFoodFactory* factory;
    if(cusine == "Indian")
        factory = new IndianFoodFactory();
    else if(cusine == "Italian")
        factory = new ItalianFoodFactory();
    
    IFoodItem* foodItem = factory->createFactory();
    
    foodItem->getAppetizer();
    foodItem->getMain();
    foodItem->getDessert();
    
    delete factory;
}