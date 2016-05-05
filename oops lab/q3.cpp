#include<stdio.h>
#include<iostream>


inline int add(int a, int b) {
	return a + b;
}


inline int sub(int a, int b) {
	return a - b;
}


inline int mult(int a, int b) {
	return a * b;
}


inline double div(int a, int b) {
	return (double) a / b;
}


inline int mod(int a, int b) {
	return a % b;
}

int main() {

    int x, y;
    std::cout << "Enter first number" << std::endl;
    std::cin >> x;
    std::cout << "Enter second number" << std::endl;
    std::cin >> y;
  
    std::cout << "Addition operation : " << add(x, y) << std::endl;
    std::cout << "Subtraction operation : " << sub(x, y) << std::endl;
    std::cout << "Multiplication operation : " << mult(x, y) << std::endl;
    std::cout << "Division operation : " << div(x, y) << std::endl;
    std::cout << "Modulus operation : " << mod(x, y) << std::endl;
    
    return 0;
}