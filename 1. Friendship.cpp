/*Friend classes have access to the private and protected members of another class.
This is typically not used as a method of access mediation, I can't really think of
an instance where friend classes are a requirement so don't ask. Here's the syntax:
*/
#include <iostream>

using namespace std;

class A{
    int varA, varB;

    friend class B; // here we declared the existence of a friend class B (defined below)
public:
    A(int a = 0, int b = 0) : varA(a), varB(b){} // I forgot that this syntax exists lol

    int getA() const { return varA; }
    int getB() const { return varB; }

    /*This however, does not work in reverse. Just becase B is a friend of A, does
    not mean that A is a friend of B, meaning A cannot access private members of A*/

    // look here
    // int getProd(B obj) { return obj.prod; }  // this is not allowed.
                                                // uncomment and see what the error is.
};

/*Since this is a friend class of A, it can access private and protected memebers of A.
It can do this directly, and doesn't have to rely on accessors and mutators.*/
class B{
    int prod;

public:
    B(A obj){
        prod = obj.varA * obj.varB; // direct accessing is allowed.
    }

    int getProd() const{ return prod; }
};

int main(){
    A obj1(2, 3);
    cout << obj1.getA() << ' ' << obj1.getB() << '\n';

    B obj2(obj1);
    cout << obj2.getProd() << '\n';
    return 0;
}