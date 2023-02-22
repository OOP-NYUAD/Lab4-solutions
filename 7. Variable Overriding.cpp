/*Just like you can override functions, you can override variables*/
#include <iostream>
#include <string>

using namespace std;

class A{
protected:
    int varA, varB;
    string classSpecifier;

public:
    A(){
        classSpecifier = "This is class A\n";
    }

    int getA() const{ return varA; }
    int getB() const{ return varB; }

    void setA(int a){ varA = a; }
    void setB(int b){ varB = b; }

    /*Defined a print function that makes sense for the A class*/
    void print() const{ 
        cout << "variable A = " << varA << '\n'
            << "variable B = " << varB << '\n'
            << classSpecifier;
    }
};

class B : public A{
private:
    int prod;
    string classSpecifier; // same variable name
    // this class doesn't do anything.
    // but it has a simple constructor that prints something
public:
    B(int a = 0, int b = 0){
        varA = a;
        varB = b;
        prod = a*b;
        classSpecifier = "This is class B\n";
    }


    // for class B, this print makes a bit more sense since we also
    // need information about the product.
    void print() const{ 
        cout << "variable A = " << varA << '\n'
            << "variable B = " << varB << '\n'
            << "Their product is = " << prod << '\n'
            << classSpecifier;
    }

    /*This is an example of function overriding. B already inherited
    a print from A but we overrode that here*/
};

int main(){
    B obj(1, 2);
    cout << "class B's print():\n";
    obj.print(); // object B's print will be called by default.


    // we can also refer back to the inherited print() by
    // specifying the scope.
    cout << "\nclass A's print():\n";
    obj.A::print();

    return 0;
}