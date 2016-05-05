#include<stdio.h>
#include<iostream>

class c_polygon {

public:
    virtual double area() {
        std::cout << "Not implemented";
        return 0;
    }

};

class c_rectangle: public c_polygon {
    
    double length;
    double breadth;

public:
    c_rectangle(double l, double b) {
        length = l;
        breadth = b;
    }
    
    double area() {
        return length * breadth;
    }
    
};

class c_triangle: public c_polygon {
    
    double base;
    double height;

public:
    c_triangle(double b, double h) {
        base = b;
        height = h;
    }
    
    double area(){
        return 0.5 * base * height;
    }
    
};


int main() {

    c_polygon *pol = new c_rectangle(2,5);

    std::cout << "Area of rectangle is: " << pol->area() << std::endl;

    pol = new c_triangle(3,7);

    std::cout << "Area of traigle is: " << pol->area() << std::endl;

    return 0;
}