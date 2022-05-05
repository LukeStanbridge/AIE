// 2-Variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //std::cout << "Hello World!\n";

    //int number = 15;
    //std::cout << number << "\n";

    //number = 12;
    //std::cout << number << "\n";

    //number = 16;
    //std::cout << number << "\n";

    //number = 325;
    //std::cout << number << "\n";

    //int firstNumber = 3;
    //int secondNumber = 5;
    //int sumOf = firstNumber + secondNumber;
    //std::cout << sumOf << "\n";

    //float aNumber = 6;
    //float anotherNumber = 7;
    //float total = aNumber + anotherNumber;
    //std::cout << total << "\n";

    //int userNumber;
    //std::cout << "Enter a number?" << std::endl;
    //std::cin >> userNumber;
    //std::cout << "The number you entered was: " << userNumber << std::endl;

    //// A)
    //int numberA = 5;

    //numberA = 9;
    //numberA = 11;
    //numberA = 14;
    //// guess = 14
    //std::cout << "A) " << numberA << std::endl;

    //// B)
    //int numberB = 10;
    //numberB = 9;

    //int thingB = 55;
    //thingB = 22;
    //// guess = 9
    //std::cout << "B) " << numberB << std::endl;

    //// C)
    //int numberC = 3;
    //numberC = 7;
    //numberC = 1;

    //int somethingC = 23;
    //somethingC = 21;

    //numberC = somethingC;
    //// guess = 21
    //std::cout << "C) " << numberC << std::endl;

    //// D)
    //int numberD = 1;
    //int somethingD = 3;

    //numberD = somethingD;
    //// guess = 3
    //std::cout << "D) " << somethingD << std::endl;

    //// E)
    //int x = 13;

    //x = x / 2;
    //// guess = 6
    //std::cout << "E) " << x << std::endl;

    //// F)
    //float y = 13;

    //y = y / 2;
    //// guess = 6.5
    //std::cout << "F) " << y << std::endl;

    //// Celsius to Fahrenheit)
    //std::cout << "\n<<Celsius to Fahrenheit>>" << std::endl;
    //float degCelsius = 78.0f;
    //float degFahrenheit = 0.0f; // Modify this variable below.

    //std::cout << "Enter a temp in degrees celsius: " << std::endl;
    //std::cin >> degCelsius;

    //// <Your work goes here>
    //degFahrenheit = (degCelsius * (9.0/5.0)) + 32;

    //std::cout << "Celsius:    " << degCelsius << std::endl;
    //std::cout << "Fahrenheit: " << degFahrenheit << std::endl;

    //// Area of a Rectangle)
    //std::cout << "\n<<Area of a Rectangle>>" << std::endl;
    //float rectWidth = 0.0f;  // Modify this variable below.
    //float rectHeight = 0.0f; // Modify this variable below.
    //float rectArea = 0.0f;   // Modify this variable below.

    //// <Your work goes here>
    //std::cout << "Enter rectangle width: " << std::endl;
    //std::cin >> rectWidth;
    //std::cout << "Enter rectangle height: " << std::endl;
    //std::cin >> rectHeight;
    //rectArea = (rectWidth*rectHeight);
    //
    //std::cout << "H: " << rectHeight << " , W: " << rectWidth << std::endl;
    //std::cout << "Area: " << rectArea << std::endl;

    //// Average of Five)
    //std::cout << "\n<<Average of Five>>" << std::endl;
    //float a, b, c, d, e;    // Modify these variables below.
    //float avg;              // Modify this variable below.
    //avg = a = b = c = d = e = 0.0f; // Initialize all to zero.

    //// <Your work goes here>
    //std::cout << "Enter 5 numbers: " << std::endl;
    //std::cin >> a >> b >> c >> d >> e;
    //avg = (a + b + c + d + e) / 5;
    //
    //std::cout << a << "," << b << "," << c << "," << d << "," << e << std::endl;
    //std::cout << "avg: " << avg << std::endl;

    //// Number Swap)
    //std::cout << "\n<<Number Swap>>" << std::endl;
    //int x1 = 13;
    //int y1 = 24;
    //int temp;

    //std::cout << "Enter 2 numbers: " << std::endl;
    //std::cin >> x1 >> y1;

    //// <Your work goes here>
    //temp = x1;
    //x1 = y1;
    //y1 = temp;

    //std::cout << "x is " << x1 << std::endl;
    //std::cout << "y is " << y1 << std::endl;

    // Fun Facts for Your Age)

    int age = 0;

    // <Your work can go here.>
    std::cout << "Enter your age: " << std::endl;
    std::cin >> age;

    // <You must add more lines to output to the terminal>
    std::cout << "Howdy! You are " << age << " years old!" << std::endl;
    int months = age * 12;
    std::cout << "You have been alive for " << months << " months.";

    // Conforming to Conventions)

    int age1; // age
    int bulletCount; // bullet_count
    float dogYears; // dog_years
    int qty; // qty
    float shieldValue; // shield_value
    float defenseMatrixCooldown; // defense_matrix_cooldown
    int redArmorValue; // red_armour_value
    float redArmorRatio; // red_armour_ratio
    int happiness; // happiness
    int gandhiAggression; // gandhi_aggression

    // The Right Tool for the Job)

    int num;        // integer
    float num2;     // single precision floating point
    char letter;    // single character
    double num3;    // a double precision floating point
    long double num4; // 
    bool question;  // stors either true or false
    void;           // represents the absence of type
    int arr[5];     // array with 5 memory locations
    int* ptr;       // symbolic representaion of addresses

    // Number Swap)
    std::cout << "\n<<Number Swap>>" << std::endl;
    int x1 = 13;
    int y1 = 24;

    std::cout << "Enter 2 numbers: " << std::endl;
    std::cin >> x1 >> y1;

    // <Your work goes here>
    x1 = x1 ^ y1;
    y1 = x1 ^ y1;
    x1 = x1 ^ y1;

    std::cout << "x is " << x1 << std::endl;
    std::cout << "y is " << y1 << std::endl;

    std::cin.get();
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
