#include <cmath>
using namespace std;

class MyPoint
{
private:
    double x, y;
public:
    // The no-arg constructor that contruccts a point with coordinates(0,0)
    MyPoint()
    {
        x = y = 0;
    }
 
    MyPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
 
    //display the distance between two points in two-dimensional space.
    double distance(const MyPoint &point)
    {
        return sqrt((x-point.x)*(x-point.x) + (y-point.y)*(y-point.y));
    }
};
 
class ThreeDPoint : public MyPoint
{
private:
    double z;
public:
    // The no-arg constructor that contruccts a point with coordinates(0,0,0) 
    ThreeDPoint(): MyPoint()
    {
        z = 0;
    }
 
    ThreeDPoint(double x, double y, double z): MyPoint(x,y)
    {
        this->z = z;
    }
    double getZ() const
    {
        return z;
    }
 
    //display the distance between two points in Three-dimensional space.
    double distance(const ThreeDPoint &point)
    {
        return sqrt((getX()-point.getX())*(getX()-point.getX()) + (getY()-point.getY())*(getY()-point.getY()) + (z-point.z)*(z-point.z));
    }
};

int main()
{
    
}