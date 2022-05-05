// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //// EXERCISE 3
    //int data[10];
    //for (int i = 9; i >= 0; i--)
    //{
    //    data[i] = i + 1;
    //    std::cout << data[i] << std::endl;
    //}

    //// EXERCISE 4
    //const int size = 5;
    //int numbers[size];
    // 
    // *Edit* - use a for loop to store numbers
    //std::cout << "Enter 5 numbers: " << std::endl;
    //std::cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4];
    //std::cout << std::endl;

    //for (int i = 4; i >= 0; i--) {
    //    std::cout << numbers[i] << std::endl;
    //}

    //// EXERCISE 5
    //const int size = 10;
    //int numbers[size];
    //int small = 0;
    //int large = 0;
    // 
    // *Edit* - use a for loop to store numbers
    //std::cout << "Enter 10 numbers: " << std::endl;
    //std::cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4] >> numbers[5] >> numbers[6] >> numbers[7] >> numbers[8] >> numbers[9];
    //std::cout << std::endl;

    //small = numbers[0];
    //large = numbers[0];

    //for (int i = 0; i < size; i++) 
    //{      
    //    if (numbers[i] < small)
    //    {
    //        small = numbers[i];
    //    }
    //    if (numbers[i] > large)
    //    {
    //        large = numbers[i];
    //    }       
    //}

    //std::cout << "Largest number is: " << large << std::endl;
    //std::cout << "Smallest number is: " << small << std::endl;

    //// EXERCISE 6
    //const int size = 3;
    //int myArray[size][size];
    //int val = 1;

    //for (int i = 0; i < size; i++)
    //{
    //    for (int j = 0; j < size; j++)
    //    {
    //        myArray[i][j] = val++;
    //    }
    //}

    //for (int i = 0; i < size; i++)
    //{
    //    for (int j = 0; j < size; j++)
    //    {
    //        std::cout << myArray[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}

    //// EXERCISE 7
    //const int rowSize = 29;
    //const int colSize = 5;
    //int days[rowSize][colSize];
    //int val = 1;
    //int row, col, sum;

    //// initialize array with values
    //for (int i = 0; i < rowSize; i++)
    //{
    //    for (int j = 0; j < colSize; j++)
    //    {
    //        days[i][j] = val;
    //        val++;
    //    }
    //}

    //// print values in array
    //for (int i = 0; i < rowSize; i++)
    //{
    //    for (int j = 0; j < colSize; j++)
    //    {
    //        std::cout << days[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}

    //// sum of the rows
    //for (row = 0; row < rowSize; row++)
    //{
    //    sum = 0;
    //    for (col = 0; col < colSize; col++)
    //    {
    //        sum += days[row][col];
    //    }
    //    std::cout << "Sum of elements of Row: " << row + 1 << " is " << sum << std::endl;
    //}

    //// sum of the columns
    //for (col = 0; col < colSize; col++)
    //{
    //    sum = 0;
    //    for (row = 0; row < rowSize; row++)
    //    {
    //        sum += days[row][col];
    //    }
    //    std::cout << "Sum of elements of Column: " << col + 1 << " is " << sum << std::endl;
    //}

    //// EXERCISE 8
    //const int size = 5;
    //int characters[size];
    //int playerChoice = 0;

    //// initialize health of 5 characters to 100
    //for (int i = 0; i < size; i++)
    //{
    //    characters[i] = 100;
    //    //std::cout << "Character " << (i + 1) << " HP - " << characters[i] << " " << std::endl;
    //}

    //// Damage different characters in party
    //for (int i = 0; i < size; i++)
    //{
    //    std::cout << "Enter a number from 1 - 5 which will be the character that is attacked by a monster: " << std::endl;
    //    std::cin >> playerChoice;
    //    playerChoice--;
    //    if (characters[playerChoice] > 0) 
    //    {
    //        characters[playerChoice] -= 1 + (rand() % 40); // deal a random amount of damage
    //    }
    //    else
    //    {
    //        std::cout << "Cannot attack, character already dead" << std::endl;
    //    }
    //    std::cout << "\n";
    //}

    //std::cout << "\n";

    //// Print final values of party
    //for (int i = 0; i < size; i++)
    //{
    //    std::cout << "Character " << (i + 1) << " HP - " << characters[i] << " " << std::endl;
    //}

    // Exercise 9
    const int dragons = 3;
    const int days = 7;
    int food[dragons][days];
    float totalAverage = 0;
    float individualAverage = 0;
    int small = 0;
    int large = 0;
    int least = 0;
    int most = 0;

    // initialize array with values
    srand(time(0));
    for (int i = 0; i < dragons; i++)
    {
        for (int j = 0; j < days; j++)
        {
            food[i][j] = rand() % 40 + 1;
        }
    }

    // print values in array
    for (int i = 0; i < dragons; i++)
    {
        for (int j = 0; j < days; j++)
        {
            std::cout << food[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // print total average of all dragons
    for (int i = 0; i < dragons; i++)
    {
        for (int j = 0; j < days; j++)
        {
            totalAverage += food[i][j];
        }       
    }
    totalAverage = (totalAverage / (dragons * days));
    std::cout << "\nThe average amount of food eaten by all dragons together is: " << totalAverage << "kgs\n" << std::endl;

    // print total average of all dragons
    for (int i = 0; i < dragons; i++)
    {
        individualAverage = 0;
        for (int j = 0; j < days; j++)
        {
            individualAverage += food[i][j];
        }
        individualAverage = (individualAverage /  days);
        std::cout << "The average amount of food eaten by dragon number " << i + 1 << " is: " << individualAverage << "kgs\n" << std::endl;
    } 

    // print smallest and largest amount of food eaten
    small = 41;
    large = 0;

    for (int i = 0; i < dragons; i++)
    {
        for (int j = 0; j < days; j++)
        {
            if (food[i][j] < small)
            {
                least = (i + 1);
                small = food[i][j];
            }
            if (food[i][j] > large)
            {
                most = (i + 1);
                large = food[i][j];               
            }
        }
    }

    std::cout << "Largest amount of food is " << large << "kgs, eaten by dragon " << most << std::endl;
    std::cout << "\nSmallest amount of food is " << small << "kgs, eaten by dragon " << least << std::endl;
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
