#include<iostream>

int noOfVowels(char *str) {

    int count = 0;

    for (int i = 0; *(str + i) != '\0'; i++) {

        if ( *(str + i) == 'a' || *(str + i) == 'A' ||
            *(str + i) == 'e' || *(str + i) == 'E' ||
            *(str + i) == 'i' || *(str + i) == 'I' ||
            *(str + i) == 'o' || *(str + i) == 'O' ||
            *(str + i) == 'u' || *(str + i) == 'U' )
            ++count;
    }

    return count;
}


int main() {

    char str[100];
    std::cout << "Enter a string" << std::endl;
    std::cin.getline(str, 100);
    std::cout << "No of vowels are " << noOfVowels(str) << std::endl;
}
