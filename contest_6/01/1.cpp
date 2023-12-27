#include <math.h>

class Shape{
public:
    int a, b, c;
    Shape(int c): c(c){}
    Shape(int a, int b): a(a), b(b){}
    Shape(int a, int b, int c): a(a), b(b), c(c){}
    virtual double getPerimeter() = 0;
};

class Rectangle: public Shape{
    public:
    Rectangle(int a, int b): Shape(a, b){}
    double getPerimeter() override {
        return (a+b)*2;
    }
};

class Circle: public Shape{
    public:
    Circle(int c): Shape(c){}
    double getPerimeter() override {
        return 2*M_PI*c;
    }
};

class Triangle: public Shape{
    public:
    Triangle(int a, int b, int c): Shape(a, b, c){}
    double getPerimeter() override {
        if (a + b > c && a + c > b && b + c > a) {
            return a + b + c;
        }
        else {
            return 0;
        }
    }
};