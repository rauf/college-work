#include<iostream>
#include<math.h>

class TwoD {
protected:
    double x, y;

public:

    TwoD(int a, int b) {
        x = a;
        y = b;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }
};

class ThreeD: public TwoD {

    double z;

public:

    ThreeD(int a, int b, int c) : TwoD(a, b) {
        z = c;
    }

    double getZ() {
        return z;
    }

    double distanceFrom(ThreeD ob) {
        double xd = ob.getX() - this->x;
        double yd = ob.getY() - this->y;
        double zd = ob.getZ() - this->z;

        return sqrt(pow(xd, 2) + pow(yd, 2) + pow(zd, 2));
    } 

};


int main() {

    ThreeD obj1(1,2,3);
    ThreeD obj2(4,6,7);

    std::cout << "The distance between two points are: " << obj1.distanceFrom(obj2) << std::endl;

}
