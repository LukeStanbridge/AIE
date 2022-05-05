// Recursive Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <string>

//void printDirectory(std::string directory, int depth) {
//    HANDLE hFind;
//    WIN32_FIND_DATAA data;
//
//    std::string padding(" ");
//    padding.resize(depth + 1);
//
//    std::string searchPath = directory + "\\*";
//
//    hFind = FindFirstFileA(searchPath.c_str(), &data);
//    if (hFind != INVALID_HANDLE_VALUE) {
//        do {
//            // don't process the '.' or '..' entries
//            if (strcmp(data.cFileName, ".") == 0 || strcmp(data.cFileName, "..") == 0)
//                continue;
//
//            std::cout << padding << data.cFileName << std::endl;
//
//            if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
//                printDirectory(directory + "\\" + data.cFileName, depth + 1);
//            }
//        } while (FindNextFileA(hFind, &data));
//        FindClose(hFind);
//    }
//}
//
//void main()
//{
//    printDirectory("C:\\Users\\bridg\\Desktop\\Introduction to C++\\2-Variables", 0);
//}

//// Exercise 1
//void printFibonacci(int n)
//{
//    static int n1 = 0, n2 = 1, n3;
//    if (n > 0) {
//        n3 = n1 + n2;
//        n1 = n2;
//        n2 = n3;
//        std::cout << n3 << " ";
//        printFibonacci(n - 1);
//    }
//}
//int main()
//{
//    int n;
//    std::cout << "Enter the number of elements: ";
//    std::cin >> n;
//    std::cout << "Fibonacci Series: ";
//    std::cout << "0 " << "1 ";
//    printFibonacci(n - 2);  //n-2 because 2 numbers are already printed    
//    return 0;
//}

//// Exercise 2
//int calculatePower(int, int);
//
//int main()
//{
//    int base, powerRaised, result;
//
//    std::cout << "Enter base number: ";
//    std::cin >> base;
//
//    std::cout << "Enter power number(positive integer): ";
//    std::cin >> powerRaised;
//
//    result = calculatePower(base, powerRaised);
//    std::cout << base << "^" << powerRaised << " = " << result;
//
//    return 0;
//}
//
//int calculatePower(int base, int powerRaised)
//{
//    if (powerRaised != 0)
//        return (base * calculatePower(base, powerRaised - 1));
//    else
//        return 1;
//}

int count = 0;

// Exercise 3
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << std::endl;
    count++;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    std::cout << "\nThe amount of moves to solve the Tower of Hanoi is: " << count;
    return 0;
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
