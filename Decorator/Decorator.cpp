// Product Interface
class FoodItem{
public:
    virtual string getDescription() = 0;
    virtual int getPrice() = 0;
};

// Products
class Pizza: public FoodItem{
    int price;
    string desc;
public: 
    Pizza(int p, string d)
    {
        price = p;
        desc = d;
    }
    string getDescription()
    {
        return desc;
    }
    int getPrice()
    {
        return price;
    }
};

class Burger: public FoodItem{
    int price;
    string desc;
public: 
    Burger(int p, string d)
    {
        price = p;
        desc = d;
    }
    string getDescription()
    {
        return desc;
    }
    int getPrice()
    {
        return price;
    }
};

// Decorator Interface
class Decorator: public FoodItem{
protected: 
    FoodItem* foodItem;
};

// Concrete decorator
class CheeseDecorator: public Decorator{
    int cheesePrice;
public:
    CheeseDecorator(FoodItem* item, int price)
    {
        foodItem = item;
        cheesePrice = price;
    }
    string getDescription()
    {
        return foodItem->getDescription() + " with extra cheese";
    }
    int getPrice()
    {
        return foodItem->getPrice() + cheesePrice;
    }
};

// Concrete decorator
class SauceDecorator: public Decorator{
    int saucePrice;
public:
    SauceDecorator(FoodItem* item, int price)
    {
        foodItem = item;
        saucePrice = price;
    }
    string getDescription()
    {
        return foodItem->getDescription() + " with extra sauce";
    }
    int getPrice()
    {
        return foodItem->getPrice() + saucePrice;
    }
};

int main() {
    FoodItem* pizza = new Pizza(100, "Marcoronni");
    FoodItem* burger = new Burger(80, "Paneer royale");
    
    pizza = new CheeseDecorator(pizza, 20);
    cout<<pizza->getDescription()<<endl;
    cout<<pizza->getPrice()<<endl;
    
    pizza = new SauceDecorator(pizza, 10);
    cout<<pizza->getDescription()<<endl;
    cout<<pizza->getPrice()<<endl;
    
    burger = new CheeseDecorator(burger, 20);
    cout<<burger->getDescription()<<endl;
    cout<<burger->getPrice()<<endl;
    
    burger = new SauceDecorator(burger, 10);
    cout<<burger->getDescription()<<endl;
    cout<<burger->getPrice()<<endl;
}