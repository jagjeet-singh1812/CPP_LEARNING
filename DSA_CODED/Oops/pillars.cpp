#include <bits/stdc++.h>
#define ll long long
using namespace std;
// sab moh maya sab abstraction hai
//----------------------------------------------------------------
// Encapsulation
// -->capulation/wrapping of data members and member functions
// --> used for data hiding
// class->> is by default encapulastion
// perfect encapulastion--> if all data members are private so for accessing we use getter and setter function
// used for security point of view
// implementation hinding
// Reusable Entity
//----------------------------------------------------------------------

//perfect encapsulation 
class Animal
{
private:
    int age;
    int weight;

public:
    void eat()
    {
        cout << "i am eating " << endl;
    }
    int getage(){//getter
        return this->age;
    }
    void setage(int age){//setter
        this->age=age;
    }
    int getweight(){//getter
        return this->age;
    }
    void setweight(int age){//setter
        this->age=age;
    }
};




//inheritance 
//sons inhert from the--> father 
//so super/parent/base class properties are inherit by sub/child/derived class
//-----------------------------------------------------


class parentclass{

public:
    int age;
    int weight;
    void eat()
    {
        cout << "i am eating " << endl;
    }
};

//public here is a mode of inheritance 
class child:public parentclass{

};



//protected member is accessed inside class and inside its derived class

//for understanding the mode inheritance refer chart-diagram 

//private member of parent class is not accessible in any way 

//types of inheritance is 
//1.single  --> above example 
//2.multi-level --> 
//3.hierarchical --> 
//4.multiple  -->
//5.hybrid -->

int main()
{
    // Animal a;
    // a.eat();
    child a;
    a.eat();
    return 0;
}

