#include<iostream>

template <class T>
class pair {

    T a, b;

public:
    pair(T x, T y) {
        a = x;
        b = y;
    }

    T get_max(){
        return a > b ? a : b;
    }
};

int main() {

    pair<int> p1(2,5);
    std::cout << "Maximum of 2 and 5 is: " << p1.get_max() << std::endl;


    pair<char> p2('a','b');
    std::cout << "Maximum of 'a' and 'b' is: " << p2.get_max() << std::endl;

    pair<float> p3(3.14, 1.7);
    std::cout << "Maximum of 3.14 and 1.7 is: " << p3.get_max() << std::endl;
}
