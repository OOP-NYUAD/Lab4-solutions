/*Sometimes, we want to ensure that we override certain functions. 
To specifiy this, we declare them as virtual functions. This is to say
that the code executed must belong to the derived class. This is essential
when using pointers.

NOTE: when declaring pointers to objects, the pointer can be a "pointer to
base class object" and still be used to point at a derived class object. Doing
this howver, will force the pointer to refer to all the base class's member
functions. To make sure not to do this we declare virtual functions.*/

#include <iostream>

using namespace std;

class A{
protected:
    int varA, varB;

public:
    A(){}

    int getA() const{ return varA; }
    int getB() const{ return varB; }

    void setA(int a){ varA = a; }
    void setB(int b){ varB = b; }

    // normal print()
    // void print() const{ 
    //     cout << "variable A = " << varA << '\n'
    //         << "variable B = " << varB << '\n';
    // }

    /*Defined a virtual print function*/
    virtual void print() const{ 
        cout << "variable A = " << varA << '\n'
            << "variable B = " << varB << '\n';
    }
};

class B : public A{
private:
    int prod;
    // this class doesn't do anything.
    // but it has a simple constructor that prints something
public:
    B(int a = 0, int b = 0){
        varA = a;
        varB = b;
        prod = a*b;
    }


    // for class B, this print makes a bit more sense since we also
    // need information about the product.
    void print() const{ 
        cout << "variable A = " << varA << '\n'
            << "variable B = " << varB << '\n'
            << "Their product is = " << prod << '\n';
    }

    /*This is an example of function overriding. B already inherited
    a print from A but we overrode that here*/
};

int main(){
    B obj(2, 3);
    A *ptr = &obj; // this is allowed. A pointer to B object is allowed if B inherits from A.
    
    ptr->print(); // no virtual function is defined now. What will be printed?
    // go above and uncomment the virtual function and try again

    return 0;
}