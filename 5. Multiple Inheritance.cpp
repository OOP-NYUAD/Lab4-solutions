/*Similar to multi-level inheritance, there is also multiple inheritance.
This allows one class (say class C) to inherit from classes A and B. which 
is a subtly differnet from inheriting from B which inherits from A*/

/*This is the same file copied over from 4, but with some tweaks*/
#include <iostream>

using namespace std;

class A{
    int varA, varB;

public:
    A(){
        cout << "Constructor for A was called here.\n";
    }

    int getA() const{ return varA; }
    int getB() const{ return varB; }

    void setA(int a){ varA = a; }
    void setB(int b){ varB = b; }
};

// Note that this is just a class now. Doesn't inherit from anything
class B{
public:
    B(){
        cout << "Constructor for B was called here.\n";
    }
};

// this class inherits directly from both A and B
class C : public A, public B{
public:
    C(){
        cout << "Constructor for C was called here.\n";
    }
};

/*Let's make a class D that also inherits from A and B but in 
a different order.*/
class D : public B, public A{
public:
    D(){
        cout << "Constructor for D was called here.\n";
    }
};

int main(){
    cout << "First experiment\n";
    C obj1;
    // After the creation of the object, note what happens on the console
    // also note the order.
    // A->B->C.
    cout << "\nSecond Experiment\n";
    // Now let's try an object D and note the order.
    D obj2;
    // B->A->D

    /* this is the case because it follows the same order as the class
    inheritence decleration. In the case of C, it inherited first from
    A then from B, so A->B->C.
    
    In the case of D, it inherited from B first, then A, so B->A->D.*/

    /*aside from this same rules as earlier still apply. This is to say,
    C and D objects have access to protected memebrs of A and B. They also
    have access to public memebrs of A, i.e.*/

    obj1.setA(2); // is allowed
    obj2.setB(4); // is also allowed
    return 0;
}