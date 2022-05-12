// Text Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string.h>

int main()
{
    int choice = 0;
    std::string append;

    std::string fileName("MyLog.txt");
    std::fstream file;  
    file.open(fileName, std::ios::out);
    file << "Hello world" << std::endl;

    std::cout << "Would you like to display(1), write(2), clear(3) or quit(4) the file: ";
    std::cin >> choice;

    if (!file)
    {
        std:: cout << "Error in creating file!!!";
        return 0;
    }
    else
    {
        if (choice == 1)
        {
            std::cout << file.rdbuf() << std::endl;
        }
        else if (choice == 2)
        {
            
        }
        else if (choice == 3)
        {

        }
        else
        {

        }
    }

    file.close();

    return 0;
}

