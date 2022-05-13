// Text Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int choice = 0;
    std::string append;

    std::fstream file("MyLog.txt");

    file.open("MyLog.txt", std::ios::in | std::ios::out | std::ios::app);

    if (!file.is_open())
    {
        std::cout << "error while opening file" << std::endl;
    }
    else
    {
        std::cout << "file opened successfully" << std::endl;
        std::cout << "writing to a file" << std::endl;

        file << "This is bulshit" << std::endl;

        file.seekg(0);
        std::cout << "reading from a file" << std::endl;
        std::string line;

        while (file.good())
        {
            getline(file, line);
            std::cout << line << std::endl;
        }
    }
    
    /*std::cout << "Would you like to display(1), write(2), clear(3) or quit(4) the file: ";
    std::cin >> choice;

    if (choice == 1)
    {
        if (file.is_open())
        {
            std::cout << file.rdbuf();
        }
    }
    else if (choice == 2)
    {
        if (file.is_open())
        {
            std::cout << "Appending something to the end of the file: ";          
            file << "morn";
            file.seekg(0);
        }
    }
    else if (choice == 3)
    {

    }
    else
    {

    }*/

    file.close();
    return 0;
}

