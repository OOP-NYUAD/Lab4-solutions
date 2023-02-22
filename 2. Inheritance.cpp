/*Inheritance is supported in cpp by class derivations. It allows derived/children
classes to have the same properties as their parent classes.*/
#include <iostream>

using namespace std;

class A{
/*we are introducing a new access modifer. _Protected_. This means the
below members are accessible by children/derived classes, but are private
for all other intents and purposes.*/
protected:
    int varA, varB;

public:
    A(){} // constructors do nothing for now (later tutorial)

    void setA(int a) { varA = a; }
    void setB(int b) { varB = b; }

    int getA() const{ return varA; }
    int getB() const{ return varB; }
};

/*We have created a base class A, now we will create a derived class B. Now class
B will extend class A. it will add */

class B : public A{
    public:
    B(){} // constructors do nothing for now (later tutorial)

    int getProd() const {
        return varA * varB; // note that class B can access protected members of A directly
    }
};

int main(){
    B obj;

    /*Note that this object of class B will inherit all the public functions
    of A. Including the setters.*/

    obj.setA(5);    // setA and setB are member functions of
    obj.setB(10);   // A, not B, but they can be called nonetheless
                    // since B inherited from A

    cout << obj.getProd() << '\n';
    return 0;
}