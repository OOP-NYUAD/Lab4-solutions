/*Maybe you haven't noticed in that last cpp file, so I will point out:
we haven't defined constructors for either C nor B, but we still someh-
ow were able to construct a C object even though we have only have the
one constructor in A defined. Why is that?

Basically, it is beacuse in that last file, we relied on the constructor
of A to get the job done. In actuality, all the constructors were called.
B and C have "implicit constructors" which are provided by the compiler
these do nothing aside from allocating the space for the variables (in
the previous case, just two integers for A and nothing for B and C).

Let's show you what I mean when I say all of the constructors are called:

We'll copy the last file but make a few tweaks:*/

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

class B : public A{
    // this class doesn't do anything.
    // but it has a simple constructor that prints something
public:
    B(){
        cout << "Constructor for B was called here.\n";
    }
};

class C : public B{
    // also doesn't do anything, but the claim I am making is
    // that this class has the getters and setters from A.

    // this class also has a simple constructor that prints something
public:
    C(){
        cout << "Constructor for C was called here.\n";
    }
};

int main(){
    C obj;
    // After the creation of the object, note what happens on the console
    // also note the order.

    /* If you noticed, the order is hierarchical. Meaning that the "oldest"
    constructor is called first, then the ones below it.*/ 
    return 0;
}