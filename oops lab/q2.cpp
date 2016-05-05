#include<iostream>


int reverseNo (int n) {

	int reverse = 0;

	while(n > 0) {
		int last = n % 10;
		reverse *= 10;
		reverse += last;
		n /= 10;
	}
	return reverse;
}

void reverseNoWRT(int n) {

	std::cout << "\nFunction without return type called" << std::endl;
	int reverse = 0;

	while(n > 0) {
		int last = n % 10;
		reverse *= 10;
		reverse += last;
		n /= 10;
	}
	std::cout<< "The reversed no. is " << reverse << std::endl;
}

int main() {

    int n;
    std::cout << "Enter a number" << std::endl;
    std::cin >> n;
    std::cout << "Reversed number is : " << reverseNo(n) << std::endl;
    reverseNoWRT(n);
}