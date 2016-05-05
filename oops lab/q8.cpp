#include<iostream>


class Company {

    int employees;

public: 
    Company() {
        employees = 0;
    }

    Company(int n) {
        employees = n;
    }
    
    Company operator + (Company &c) {
        int n = this-> employees + c.noOfEmployees();
        return Company(n);
    }

    Company operator - (Company &c) {
        int n = this-> employees - c.noOfEmployees();
        return Company(n);
    }

    int noOfEmployees() {
        return employees;
    }

};

int main() {

    Company c1(7), c2(3);

    Company c3 = c1 + c2;

    std::cout << "Employees inside company c3 are: " << c3.noOfEmployees() << std::endl;

    Company c4 = c1 - c2;

    std::cout << "Employees inside company c4 are: " << c4.noOfEmployees() << std::endl;
    
    return 0;
}