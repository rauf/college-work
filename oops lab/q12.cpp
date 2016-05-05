#include<iostream>

template <class T>
T min(T a, T b) {
    return a < b ? a : b;
}

int main() {

    std::cout << "Minimum of 3 and 6 is : " << min(3, 6) << std::endl;
    std::cout << "Minimum of 'a' and 's' is : " << min('a', 's') << std::endl;
    std::cout << "Minimum of 1.73 and 3.14 is : " << min(1.73, 3.14) << std::endl;

    return 0;
}