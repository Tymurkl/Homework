#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <cstring>
#include "Lecture9.h"
#include <limits>



int main() {
    std::cout <<"Task 1"<<std::endl;
    const int size = 10;
    int arr[size];

    std::cout << "Enter 10 numbers for the array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    translateArray(arr, size);

    std::cout << "Modified array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Task 2" << std::endl;
    const int leng=255;
    char te[leng];

    std::cout << "Enter something: ";
    std::cin.getline(te,leng);
    toUppercase(te,leng);
    std::cout << "Uppercase result: " << te << std::endl;

    std::cout << std::endl;

   std::cout <<"Task 3"<<std::endl;

    std::string text;
    std::cout << "Enter some Text: " << std::endl;
    std::cin >> text;
    if(isPalindrome(text))
    {
        std::cout << "The text is a palindrome" << std::endl;
    }
    else
    {
        std::cout << "The text is not a palindrome" << std::endl<<std::endl;
    }

    std::cout <<"Task 4"<<std::endl;

    const int maxLength = 1000;
    char input[maxLength];

    std::cout << "Enter a string: ";
    std::cin.getline(input, maxLength);

    int vowels = 0, consonants = 0;
    parseStringLetters(input, vowels, consonants);

    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;

    std::cout << "Task 5" << std::endl;
    const int mLength = 100;
    char str1[mLength];
    char str2[mLength];

    std::cout <<"string 1: ";
    std::cin.getline(str1, mLength);
    std::cout <<"string 2: ";
    std::cin.getline(str2, mLength);

    if(isEqual(str1, str2)){
        std::cout << "Equal" << std::endl;
    }
    else{
        std::cout << "Not equal" << std::endl;
    }
}



