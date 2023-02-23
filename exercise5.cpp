/*Create a class called Polygon to maintain height and width of a polygon. 
Create an appropriate constructor for Polygon object. Create another class
called PrintPolygon to print the area of the polygon. Derive two classes 
Triangle and Rectangle from Polygon and PrintPolygon class to instantiate 
the shape and print the area. See images/exercise5.png */

#include <iostream>
#include <string>

using namespace std;

class Polygon{
protected:
    float width;
    float height;
    float area;

public:
    Polygon(int w = 0, int h = 0) : width(w), height(h){}

    float getWidth()  const{ return width;  }
    float getHeight() const{ return height; }

    void setWidth(float w) { width = w;  }
    void setHeight(float h){ height = h; }

    // this implementation makes wayy more sense
    void print(){
        cout << "Area of the polygon is: " << area << " units squared.\n"; 
    }
};


// this is a silly implementation.
/*it would make more sense if print() and the variable
area were members of Polygon, and we overwrite the variables
and hardcode print to print the area*/
// class PrintPolygon{
// public:
//     static void print(float a){
//         cout << "Area of the polygon is: " << a << " units squared.\n"; 
//     }
// };

/*We did it this way anyway so that you can learn about multiple inheritance*/

class Triangle : public Polygon{
public:
    Triangle(float b, float h){
        width = b;
        height = h;
        area = 0.5 * width * height;
    }

    /*
    if multiple inheritance were to be used, the exercise would be completed like so:
        float area() const{ return 0.5 * width * height; }

        void print() const{ PrintPolygon::print(area()); }
    */
};

class Rectangle : public Polygon{
public:
    Rectangle(float w, float h){
        width = w;
        height = h;
        area = width * height;
    }

    /*
    if multiple inheritance were to be used, the exercise would be completed like so:
        float area() const{ return width * height; }

        void print() const{ PrintPolygon::print(area()); }
    */
};

int main(){
    Rectangle r(2, 5);
    Triangle t(6.2, 4);

    r.print();
    t.print();

    return 0;
}