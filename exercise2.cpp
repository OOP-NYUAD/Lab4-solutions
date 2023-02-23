/*Create a class called Vehicle to store common information about a vehicle 
like number of wheels, color, fuel type, max speed etc. Create 3 derived c-
lasses named Truck, Car and Van and add personalized fields like 
size_of_containers for Truck, number_of_doors for Car and no_of_boxes for 
the Van class. Implement print method in each derived class to print compl-
ete vehicle information.*/

#include <iostream>
#include <string>

using namespace std;

class Vehicle{
protected:
    int numWheels;
    int maxSpeed;
    string color;
    string fuelType;

public:
    Vehicle(int n = 4, int m = 200, string c = "White", string f = "95") : numWheels(n), maxSpeed(m), color(c), fuelType(f){}

    void print(){
        cout    << "Number of wheels: " << numWheels << '\n'
                << "Max Speed: "        << maxSpeed  << '\n'
                << "Color: "            << color     << '\n'
                << "Fuel Type: "        << fuelType  << '\n'; 
    }
};

class Truck : public Vehicle{
private:
    int size_of_containers;
public:
    Truck(int n = 4, int m = 200, string c = "White", string f = "95", int s = 100) : size_of_containers(s) {
        numWheels = n; 
        maxSpeed  = m; 
        color     = c; 
        fuelType  = f; 
    }

    void print(){
        cout    << "Number of wheels: "   << numWheels << '\n'
                << "Max Speed: "          << maxSpeed  << '\n'
                << "Color: "              << color     << '\n'
                << "Fuel Type: "          << fuelType  << '\n'
                << "Size of Containers: " << size_of_containers << '\n'; 
    }
};

class Car : public Vehicle{
private:
    int number_of_doors;
public:
    Car(int n = 4, int m = 200, string c = "White", string f = "95", int s = 4) : number_of_doors(s) {
        numWheels = n; 
        maxSpeed  = m; 
        color     = c; 
        fuelType  = f; 
    }

    void print(){
        cout    << "Number of wheels: " << numWheels << '\n'
                << "Max Speed: "        << maxSpeed  << '\n'
                << "Color: "            << color     << '\n'
                << "Fuel Type: "        << fuelType  << '\n'
                << "Number of doors: "  << number_of_doors << '\n';
    }
};

class Van : public Vehicle{
private:
    int no_of_boxes;
public:
    Van(int n = 4, int m = 200, string c = "White", string f = "95", int s = 2) : no_of_boxes(s) {
        numWheels = n; 
        maxSpeed  = m; 
        color     = c; 
        fuelType  = f; 
    }

    void print(){
        cout    << "Number of wheels: " << numWheels << '\n'
                << "Max Speed: "        << maxSpeed  << '\n'
                << "Color: "            << color     << '\n'
                << "Fuel Type: "        << fuelType  << '\n'
                << "Number of Boxes: "  << no_of_boxes << '\n';
    }
};