#include<iostream>


class PersonInsideBank {

    int personsInsideBank;

public: 
    PersonInsideBank() {
        personsInsideBank = 0;
    }

    PersonInsideBank(int n) {
        personsInsideBank = n;
    }
    
    void operator ++ () {
        ++personsInsideBank;
    }

    void operator -- () {
        --personsInsideBank;
    }

    int status() {
        return personsInsideBank;
    }

};

int main() {

    PersonInsideBank pib(0);
    ++pib;
    ++pib;
    ++pib;

    std::cout << "Perons inside bank are: " << pib.status() << std::endl;

    --pib;
    --pib;

    std::cout << "Perons inside bank are: " << pib.status() << std::endl;
    return 0;
}