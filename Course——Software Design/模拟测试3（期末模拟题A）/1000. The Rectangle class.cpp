class Rectangle
{
  private:
    double width, height;
  public:
    Rectangle();
    Rectangle(double width, double height);
    double getWidth();
    double getHeight();
    void setWidth(double width);
    void setHeight(double height);
    double getArea();
    double getPerimeter();

};
Rectangle::Rectangle()
{
    width = height = 1;
}
Rectangle::Rectangle(double width, double height)
{
    this->width =width;
    this->height = height;
}
double Rectangle::getWidth()
{
    return width;
}
double Rectangle::getHeight()
{
    return height;
}
void Rectangle::setWidth(double width)
{
    this->width = width;
}
void Rectangle::setHeight(double height)
{
    this->height = height;
}
double Rectangle::getArea()
{
    return height*width;
}
double Rectangle::getPerimeter()
{
    return 2*(height+width);
}                

int main()
{
    Rectangle a;
    Rectangle b(2,3);
    cout << a.getWidth() << ' ' << a.getHeight() << endl;
    cout << b.getWidth() << ' ' << b.getHeight() << endl;
    a.setHeight(12);
    a.setWidth(11);
    cout << a.getWidth() << ' ' << a.getHeight() << endl;
    cout << a.getArea() << ' ' << a.getPerimeter() << endl;
    return 0;
}