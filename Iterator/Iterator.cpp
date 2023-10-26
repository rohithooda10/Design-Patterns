#include <iostream>
using namespace std;

// Iterator
class Iterator{
public:
    virtual bool hasNext() = 0;
    virtual int first() = 0;
    virtual int next() = 0;
};

// Concrete Iterator
class NumIterator: public Iterator{
    vector<int> products;
    int curr;
public:
    NumIterator(vector<int> p)
    {
        products = p;
    }
    bool hasNext()
    {
        if(curr < products.size() - 1) return true;
        return false;
    }
    int first()
    {
        curr = 0;
        return products[curr];
    }
    int next()
    {
        if(hasNext())
        {
            curr++;
            return products[curr];
        }
        return -1;
    }
};

// Aggregator
class ProductManager
{
    vector<int> products;
public:
    void addProduct(int item)
    {
        products.push_back(item);
    }
    void removeProduct(int item)
    {
        int index = -1;
        for(int i = 0; i < products.size(); i++)
        {
            if(products[i] == item)
            {
                index = i;
                break;
            }
        }
        if(index == -1) return;
        int k = 0;
        for(int i = 0; i < products.size(); i++)
        {
            if(i != index)
                products[k++] = products[i];
        }
        products.pop_back();
    }
    Iterator* createIterator()
    {
        return new NumIterator(products);
    }
};

int main() {
    ProductManager* productManager = new ProductManager();
    productManager->addProduct(1);
    productManager->addProduct(2);
    productManager->addProduct(3);
    productManager->addProduct(4);
    Iterator* iterator = productManager->createIterator();
    cout<<iterator->first()<<endl;
    cout<<iterator->hasNext()<<endl;
    cout<<iterator->next()<<endl;
    cout<<iterator->next()<<endl;
    cout<<iterator->next()<<endl;
    cout<<iterator->next()<<endl;
    cout<<iterator->hasNext()<<endl;
}