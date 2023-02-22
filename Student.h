#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    string netID;
    string name;
    int age;
public:
    Student() {}
    Student(string netID, string name, int age)
    {
        this->netID = netID;
        this->name = name;
        this->age = age;
    }

    // Getters
    string GetID() const { return netID; }
    string GetName() const { return name; }
    int GetAge() const { return age; }

    // Setters
    void SetID(string netID) { this->netID = netID; }
    void SetName(string name) { this->name = name; }
    void SetAge(int age) { this->age = age; }

    void print()
    {
        cout << "ID: " << netID
             << " Name: " << name
             << " Age: " << age << endl;
    }

    // this operator must be overloaded if std::sort() were to be used
    bool operator <(const Student &obj) const{
        return this->name < obj.name;
    }
};
