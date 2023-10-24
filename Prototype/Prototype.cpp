#include <iostream>
using namespace std;
class Person;

// Prototype
class PersonPrototype{
public:
    virtual Person* clone(Person* person) = 0;
};

// Implements a clone method
class Person : public PersonPrototype{
    string name;
    int age;
    string rollno;
public:
    Person(string n, int a, string r)
    {
        name = n;
        age = a;
        rollno = r;
    }
    Person* clone(Person* person)
    {
        Person* newPerson = new Person(person->name, person->age, person->rollno);
        return newPerson;
    }
    void display()
    {
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<rollno<<endl;
    }
};

int main() {
    Person* p1 = new Person("John", 25, "20022A007");
    Person* p2 = p1->clone(p1);
    cout<<"Original:"<<endl;
    p1->display();
    cout<<"---------------"<<endl;
    cout<<"Clone:"<<endl;
    p2->display();
}