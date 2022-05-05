// Character Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <regex>

int main()
{
    //// EXERCISE 1, 2, 3
    //// print full name
    //const int people = 5;
    //const int names = 2;
    //std::string fullNames[people][names];

    //for (int i = 0; i < people; i++)
    //{
    //    std::cout << "Enter first name, press enter, then enter last name..." << std::endl;
    //    for (int j = 0; j < names; j++)
    //    {          
    //        std::cin >> fullNames[i][j];
    //    }      
    //}
    //std::cout << std::endl;

    //// print names 
    //for (int i = 0; i < people; i++)
    //{
    //    for (int j = 0; j < names; j++)
    //    {
    //        std::cout << fullNames[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}
    //std::cout << std::endl;

    //// print names in reverse
    //for (int i = 0; i < people; i++)
    //{
    //    for (int j = 1; j >= 0; j--)
    //    {
    //        reverse(fullNames[i][j].begin(), fullNames[i][j].end());
    //        std::cout << fullNames[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}
    //return 0;

    // EXERCISE 4
    const std::regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[-+_!@#$%^&*.,?]).+$");

    std::string userName, password;
    std::cout << "Enter username: " << std::endl;
    std::cin >> userName; 
    std::cout << "Enter password: " << std::endl;
    std::cin >> password;

    while (!(regex_match(password, pattern) && password.length() >= 8 && !password.empty()))
    {
        std::cout << "Please enter a Valid Password: " << std::endl;
        std::cin >> password;
    }
    std::cout << "Password Accepted" << std::endl;
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
