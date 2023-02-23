/*Implement the Employee and derived classes as shown in images/exercise3.png.
In the Employee hierarchy, getPay() is implemented differently in each subcla-
ss and must be a virtual method. Provide implementation for getPay() for each 
derived class.*/

#include <iostream>
#include <string>

using namespace std;

class Employee{
protected:
    string name;
    float pay;

public:
    Employee(string n = "John", float p = -1) : name(n) ,pay(p){}

    virtual float getPay(){} // can also be made into a pure virtual function. Look that up if you're curious
};

class SalariedEmployee : public Employee{
public:
    SalariedEmployee(string n = "John", float salary = 0){
        name = n;
        pay = salary; 
    }

    void setSalary(float p){ pay = p; }

    float getPay() const { return pay; }
};

class HourlyEmployee : public Employee{
private:
    float workingHours;
public:
    HourlyEmployee(string n = "John", float wage = 0, float wh = 0){
        name = n;
        pay = wage;
        workingHours = wh;
    }

    void setWage(float wage){ pay = wage; }
    void setWorkingHours(float wh){ workingHours = wh; }

    float getPay() const { return pay*workingHours; }
};

class HourlyEmployee : public Employee{
private:
    float commisionRate;
    float VolumeOfSales;
public:
    HourlyEmployee(string n = "John", float basePay = 0, float c = 0, float v = 0){
        name = n;
        pay = basePay;
        commisionRate = c;
        VolumeOfSales = v;
    }

    void setBasePay(float base){ pay = base; }
    void setCommisionRate(float c){ commisionRate = c; }
    void setVolumeOfSales(float v){ VolumeOfSales = v; }

    float getPay() const { return pay + VolumeOfSales*commisionRate; }
};