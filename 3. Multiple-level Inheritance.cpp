/*Derived classes can be "stacked". Meaning that if B inherits from A, and C inherits
from B, then C inherits from A directly.*/
#include <iostream>

using namespace std;

class A{
    int varA, varB;

public:
    A(){}

    int getA() const{ return varA; }
    int getB() const{ return varB; }

    void setA(int a){ varA = a; }
    void setB(int b){ varB = b; }
};

class B : public A{
    // this class doesn't do anything.
};

class C : public B{
    // also doesn't do anything, but the claim I am making is
    // that this class has the getters and setters from A.
};

int main(){
    C obj;
    obj.setA(2);
    obj.setB(5);

    cout << "Sum is: " << obj.getA() + obj.getB() << '\n';
    return 0;
}