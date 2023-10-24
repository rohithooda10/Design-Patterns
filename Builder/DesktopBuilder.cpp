// Builder Design Pattern
#include <iostream>
using namespace std;

// Product
class Desktop{
public:
    string ram;
    string processor;
    string os;
    string keyboard;
};

// Builder, forces each builder to implements these methods
class DesktopBuilder{
public:
    virtual void buildRam() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildOs() = 0;
    virtual void buildKeyboard() = 0;
    virtual Desktop* getDesktop() = 0;
};

// Builder for Dell desktops
class DellBuilder: public DesktopBuilder{
    Desktop* desktop = new Desktop();
public:
     void buildRam()
     {
         desktop->ram = "Dell Ram";
     }
     void buildProcessor()
     {
         desktop->processor = "Dell Processor";
     }
     void buildOs()
     {
         desktop->os = "Dell Os";
     }
     void buildKeyboard()
     {
         desktop->keyboard = "Dell Keyboard";
     }
     Desktop* getDesktop()
     {
         return desktop;
     }
         
};

// Builder for Hp desktops
class HpBuilder:public DesktopBuilder{
    Desktop* desktop = new Desktop();
public:
     void buildRam()
     {
         desktop->ram = "Hp Ram";
     }
     void buildProcessor()
     {
         desktop->processor = "Hp Processor";
     }
     void buildOs()
     {
         desktop->os = "Hp Os";
     }
     void buildKeyboard()
     {
         desktop->keyboard = "Hp Keyboard";
     }
     Desktop* getDesktop()
     {
         return desktop;
     }
};

// Create the product, can be done in client as well, this is nice separation of concern
class Director{
    Desktop* desktop = new Desktop();
public:
    void construct(DesktopBuilder* builder)
    {
        builder->buildRam();
        builder->buildProcessor();
        builder->buildOs();
        builder->buildKeyboard();
        desktop = builder->getDesktop();
    }
    Desktop* getDesktop()
    {
        return desktop;
    }
};

int main() {
    string brand;
    cout<<"Which desktop you want:";
    cin>>brand;
    
    // Create director
    Director* director = new Director();
    
    // Create builder
    DesktopBuilder* builder;
    
    // Choose builder based on input
    if(brand == "Dell")
        builder = new DellBuilder();
    else builder = new HpBuilder();
    
    // Construct the product
    director->construct(builder);
    // Get the finished product
    Desktop* desktop = director->getDesktop();
    
    // Display product
    cout<<desktop->ram<<endl;
    cout<<desktop->processor<<endl;
    cout<<desktop->os<<endl;
    cout<<desktop->keyboard<<endl;
}
