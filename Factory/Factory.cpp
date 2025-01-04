#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual void setDimension(int a, int b) = 0;
};

class Square: public Shape {
    int side;
public:
    double area(){
        return side * side;
    }
    void setDimension(int a, int b){
        side = a;
    }
};

class Rectangle: public Shape{
    int l, h;
public:
    double area(){
        return l * h;
    }
    void setDimension(int a, int b){
        l = a;
        h = b;
    }
};

class ShapeFactory{
public:
    Shape* createShape(string shape)
    {
        if(shape == "Square") return new Square();
        else return new Rectangle();
    }
};

int main()
{
    Shape* shape1, *shape2;
    ShapeFactory* shapeFactory = new ShapeFactory();
    shape1 = shapeFactory->createShape("Square");
    shape2 = shapeFactory->createShape("Rectangle");
    shape1->setDimension(5, 5);
    shape2->setDimension(5, 7);
    cout<< shape1->area()<<endl;;
    cout<< shape2->area()<<endl;
    return 0;
}