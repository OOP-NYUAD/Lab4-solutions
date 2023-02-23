/*Use Student class definition from the last lab and include a “GradeBook” class 
reference as a friend of Student class. GradeBook class can access the students’
private information like id, name, age, etc. Create an array of Student to inst-
antiate a few objects in main method and print private student information via 
friend Gradebook class.*/

#include <iostream>
#include "Student.h" // I ammended the Student.h file

using namespace std;

class GradeBook{
public:
    GradeBook(){} // we don't really need a constructor

    // print function takes in a stuent object and prints its information
    void print(const Student &s) const{
        cout << "ID: "      << s.netID
             << " Name: "   << s.name
             << " Age: "    << s.age << endl; // as you can see, direct referencing is allowed now
    }

};

int main(){
    GradeBook g;
    Student arr[3];

    arr[0].SetID("0");
    arr[0].SetName("Mo");
    arr[0].SetAge(19);

    arr[1].SetID("1");
    arr[1].SetName("Ro");
    arr[1].SetAge(20);

    arr[2].SetID("2");
    arr[2].SetName("Lo");
    arr[2].SetAge(21);


    for(int i = 0; i < 3; i++) g.print(arr[i]);

    return 0;
}