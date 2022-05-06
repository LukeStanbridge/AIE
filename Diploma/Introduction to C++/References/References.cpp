// References.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//int main()
//{
//    // EXERCISE 1
//    /*int variable = 16;
//    float variable1 = 17;
//    std::cout << variable << std::endl;
//    int& reference = variable;
//    std::cout << reference << std::endl;
//    int& reference1 = variable;
//    std::cout << reference1 << std::endl;
//    int& reference2 = reference;
//    std::cout << reference2 << std::endl;*/
//    // int to float doesnt work
//    /*int& reference3 = variable1;
//    std::cout << reference3 << std::endl;*/
//
//    // EXERCISE 2
//    /*int var1 = 10;
//    int var2 = 20;
//    std::cout << var1 << std::endl << var2 << std::endl;
//    Function(var1, var2);
//    std::cout << var1 << std::endl << var2 << std::endl;*/

// EXERCISE 3
struct Person
{
    int age;
    float height;
    char initials;
};

void Function(/*const*/Person& p)
{
    p.age = 34;
    p.height = 210.34f;
    p.initials = 'K';
}

int main()
{
    Person p1;
    p1.age = 32;
    p1.height = 195.4f;
    p1.initials = 'L';

    // before
    std::cout << p1.age << std::endl << p1.height << std::endl << p1.initials << std::endl;
    std::cout << std::endl;

    Function(p1);

    //after
    std::cout << p1.age << std::endl << p1.height << std::endl << p1.initials << std::endl;
    std::cout << std::endl;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
