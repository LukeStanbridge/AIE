// Loops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //// Exercise 1
    //for (int i = 100; i > 0; i-=2)
    //{
    //    std::cout << "loop iteration " << i << std::endl;
    //}
    //return 0;

    //// Exercise 2
    //for (int i = 1; i < 101; i++) 
    //{
    //    if (i % 3 == 0 && i % 5 == 0)
    //    {
    //        std::cout << "FizzBuzz" << std::endl;
    //    }
    //    else if (i % 5 == 0)
    //    {
    //        std::cout << "Buzz" << std::endl;
    //    }
    //    else if (i % 3 == 0)
    //    {
    //        std::cout << "Fizz" << std::endl;
    //    }
    //    else
    //    {
    //        std::cout << i << std::endl;
    //    }
    //}

    // Exercise 3 and 4
    int sum = 0;
    int i = 0;

    /*for (int i = 999; i > 0; i--) 
    {
        if (i % 3 == 0 || i % 5 == 0) 
        {
            sum += i;
        }
    }*/

    while (i < 1000)
    {       
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
        i++;
    }

    // answer is 233168
    std::cout << sum;
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
