#include<iostream>

class student {

    int roll;
    char name[20];


friend std::istream& operator>> (std::istream &in, student &s) {
    std::cout << "Enter the roll number of student" << std::endl;
    in >> s.roll;
    std::cout << "Enter the name of student" << std::endl;
    in >> s.name;
    return in; 
}

friend std::ostream& operator<< (std::ostream &out, student &s) {
    std::cout << "The roll number of student: ";
    out << s.roll;
    std::cout << "\nThe name of student: ";
    out << s.name << std::endl;
    return out; 
}


};

int main() {

    student s;

    std::cin >> s;
    std::cout << s;

}
