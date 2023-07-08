#include <iostream>
using namespace std;
// what is oops
// Programming things revolving around Objects
// what is a Object?
// object is a entity that have state/properties and a behavior
// ex-dog-->have 4 legs ,barks ,sleeps and eat(behaviour)
// wants to make your own data type
// --------------------------------------------------------------
// READ padding and grredy algo question
// class temp{
//     int x;
//     int y;
//     char j;
// } whys its size is coming->12?? ans should be 9 na
// by defualt all are private its only access inside the class can be accessed
class Animal
{
private:
    int weight;

public:
    // by default constructor is ther we have overidden it
    Animal()
    {
        cout << "construction of Animal called " << endl;
        this->weight = 0;
        this->age = 0;
    }
    
    // parameterised constructor call
    Animal(int weight)
    {
        this->weight = weight;
        cout << "parameterized one" << endl;
        cout << "weight: " << this->weight << endl;
    }

    Animal(int weight, string name)
    {
        this->weight = weight;
        this->name = name;
        cout << "parameterized one" << endl;
        cout << "weight: " << this->weight << endl;
        cout << "name: " << this->name << endl;
    }

    // copy constructor
    Animal(Animal &obj)
    { // should be call be refrence only else it will go in infinite loop by call by value
        this->weight = obj.weight;
        this->name = obj.name;
        cout << "i am inside the copy constructor" << endl;
    }

    // destructor
    ~Animal(){
        cout << "i am inside the destructor" << endl;
    }

    // state
    int age;
    string name;

    // behaviours
    void eat()
    {
        cout << "eat" << endl;
    }

    void sleep()
    {
        cout << "sleep" << endl;
    }

    void speak()
    {
        cout << "speak" << endl;
    }
    void setterweight(int weight)
    {
        // weight = wt;
        this->weight = weight;
        // or
        // (*this).weight=weight;
        // this is (a pointer to current object)
    }
    int getterweight()
    {
        // cout<<"weight: "<<weight<<endl;
        return weight;
    }

    void print()
    {
        cout << "weight: " << this->weight << endl;
        cout << "name: " << this->name << endl;
        cout<<"age: " << this->age << endl;
    }
};

int main()
{
    //     cout << "size of empty class is " << sizeof(Animal) << endl;
    //     // why 1 ???
    //     // ans->if zero then it means its existence is not ther so inorder to make it existence gave the minimum possible memory i.e 1 byte --> 8 bits
    //     // obj creation
    //     //  obj is instance of an class and class is blueprint an object
    //     Animal obj;
    //     obj.name = "LION";
    //     obj.age = 10;
    //     cout << "size of obj is " << sizeof(obj) << endl;
    //     cout << "age of obj is " << obj.age << endl;
    //     cout << "name of obj is " << obj.name << endl;
    //     obj.eat();
    //     obj.sleep();
    //     obj.speak();
    //     obj.setterweight(100);
    //     obj.getterweight();
    //     // dot operator
    //     // obj.age = 10;
    //     // obj.name = "<NAME>";
    //     // cout<<"age of obj is "<<obj.age<<endl;
    //     // cout<<"name of obj is "<<obj.name<<endl;

    //     //when need to set or get the private property
    //     obj.setterweight(100);
    //     int x=obj.getterweight();
    //     cout<<"weight"<<x<<endl;

    //     //dynamic memory
    //     Animal *obj1 = new Animal;
    //     // obj1->name = "LION";
    //     // the data structure created by new is stored in the Heap and the start pointer of that heap is stored in stack
    //     (*obj1).name="lion";
    //     // or like ->=(*).
    //     obj1->age = 10;
    //     cout << "size of obj1 is " << sizeof(obj1) << endl;
    //     cout << "age of obj1 is " << obj1->age << endl;
    //     cout << "name of obj1 is " << obj1->name << endl;
    //     obj1->eat();
    //     obj1->sleep();
    //     obj1->speak();
    //     obj1->setterweight(1100);
    //    int j=obj1->getterweight();
    //    cout<<j<<endl;
    // obj1->age = 10;
    // obj1->name = "<NAME>";
    // cout<<"age of obj1 is "<<obj1->age<<endl;
    // cout<<"name of obj1 is "<<obj1->name<<endl;
    //     Animal parametrizedone(25);
    //     Animal* c=new Animal(100);
    // //all same except actual size
    //     cout<<"size of c is "<<sizeof(c)<<endl;
    //     cout<<"size of parametrizedone is "<<sizeof(parametrizedone)<<endl;
    //     cout<<"size of c is "<<sizeof(*c)<<endl;
    //     cout<<"size of parametrizedone is "<<sizeof(parametrizedone)<<endl;
    //     cout<<"size of c is "<<sizeof(c->age)<<endl;
    //     cout<<"size of parametrizedone is "<<sizeof(parametrizedone.age)<<endl;
    //     cout<<"size of c is "<<sizeof(c->name)<<endl;
    //     cout<<"size of parametrizedone is "<<sizeof(parametrizedone.name)<<endl;
    // Animal hello(25, "Tommy");
    // Animal temp(125, "Temp");
    // initialized in the constructor best practice
    //  cout<<hello.name<<" "<<hello.getterweight()<<endl;
    // Animal temp11 = hello; // copy constructor is called
    // Animal temp2(temp11);  // other way to call copy constructor
Animal *h=new Animal();
h->age=122;
delete h;// manually delete for dynamic alloc
    return 0;
}

//desctructor to empty
//if static then auto matically done
//else in dynmic need to do it manually
