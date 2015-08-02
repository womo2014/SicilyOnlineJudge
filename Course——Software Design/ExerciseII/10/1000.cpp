#include <iostream>
#include <cmath>
using namespace std;

class GeometricObject
{
public:
    GeometricObject() 
    {
        color = "white";
        filled = false;
    }
    GeometricObject(string color, bool filled)
    {
        this->color = color;
        this->filled = filled;
    }
 
    string getColor()
    { return color; }
 
    void setColor(string color)
    { this->color = color; }
 
    bool isFilled()
    { return filled; }
 
    void setFilled(bool filled)
    { this->filled = filled;}
 
    string toString()
    {
        return "Geometric object color "+color +
            " filled " + ((filled) ? "true" : "false");
    }
private:
    string color;
    bool filled;
};

class Triangle: public GeometricObject {
public:
    Triangle():GeometricObject()
    {
        side1 = side2 = side3 = 1.0;
    }
    Triangle(double side1, double side2, double side3):GeometricObject()
    {
        if ( side1 + side2 <= side3 ||
             side1 + side3 <= side2 ||
             side3 + side2 <= side1) {
            cout << "illegal sides!" << endl;
            this->side1 = this->side2 = this->side3 = 1.0;
        }
        else {
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
        }
    }
    double getSide1() 
    {
        return side1;
    }
    double getSide2()
    {
        return side2;
    }
    double getSide3()
    {
        return side3;
    }
    double getPerimeter()
    {
        return side1 + side2 + side3;
    }
    double getArea()
    {
        double p = (side1+side2+side3)/2;
        return sqrt(p*(p-side1)*(p-side2)*(p-side3));
    }


private:
    double side1, side2, side3;
};

int main()
{
    
}