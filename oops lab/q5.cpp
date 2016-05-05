#include<iostream>
#include<string.h>

class pntr_obj {

    int roll_no;
    char name[20];
public:
    void set_data (int r, const char *n) {
        roll_no = r;
        strncpy(name, n, sizeof(name)-1);
        name[sizeof(name)-1] = '\0';
    }

    void print() {
        std::cout << "Roll no: " << this->roll_no << std::endl;
        std::cout << "Name: " << this->name << std::endl;
    }

};


int main() {

    pntr_obj p1;
    p1.set_data(1,"abdul");
    p1.print();
    std::cout << "\n";


    pntr_obj p2;
    p2.set_data(2,"abdullah");
    p2.print();
    std::cout << "\n";


    pntr_obj p3;
    p3.set_data(3,"minnat");
    p3.print();
    std::cout << "\n";

    return 0;
}