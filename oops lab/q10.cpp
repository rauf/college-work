#include<iostream>

class friendfunc2;

class friendfunc1 {

    int a, b;
public:

    friendfunc1(int x, int y) {
        a = x;
        b = y;
    }
    
    friend double avg(friendfunc1 &f1, friendfunc2 &f2);
};


class friendfunc2 {

    int c, d, e;
public:

    friendfunc2(int x, int y, int z) {
        
        c = x;
        d = y;
        e = z;
    }
    
  friend double avg(friendfunc1 &f1, friendfunc2 &f2);  
};


double avg(friendfunc1 &f1, friendfunc2 &f2) {
    
    return (double)(f1.a + f1.b + f2.c + f2.d + f2.e) / 5;
}


int main() {

    friendfunc1 f1(1, 2);
    friendfunc2 f2(3, 4, 7);

    std::cout << "The average is " << avg(f1, f2) << std::endl;

    return 0;
}