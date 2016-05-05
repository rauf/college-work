#include<stdio.h>
#include<iostream>

class Example {

public:
    static int createdObjects;
    static int destroyedObjects;
    static int currentObjects;
    
    Example () {
        ++createdObjects;
        ++currentObjects;
    }

    ~Example(){
        ++destroyedObjects;
        --currentObjects;
    }


};

int Example::createdObjects = 0;
int Example::destroyedObjects = 0;
int Example::currentObjects = 0;


int main() {

    Example ex;

    {
        Example ex1;
    }

    std::cout << "Current objects: " << ex.currentObjects << std::endl;
    std::cout << "Created objects: " << ex.createdObjects << std::endl;
    std::cout << "Destroyed objects: " << ex.currentObjects << std::endl;
    
    return 0;
}