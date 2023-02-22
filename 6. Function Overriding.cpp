/*When inheriting classes, we are bound to get some conflicts with function names.
Since derived classes inevitably share some characteristics with their parent
classes, they in all liklihood have slightly different implementations of the
same functionality. For example: a "Surgeon" class inherits from a "Doctor" class,
the Doctor class might have a print function that prints the information about the
doctor's credentials and overall prior experience, but the surgeon class will also
specifiy what kind of surgeon they are. So they will have different print functions
cpp allows us to override ineherited function to make them specific to our needs*/


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

    /*Defined a print function that makes sense for the A class*/
    void print() const{ 
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
    B obj(1, 2);
    cout << "class B's print():\n";
    obj.print(); // object B's print will be called by default.


    // we can also refer back to the inherited print() by
    // specifying the scope.
    cout << "\nclass A's print():\n";
    obj.A::print();

    return 0;
}