// Constants.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//char choice;
//int flag;
//long date, time;
float gallons;
float litres;
float conversion = 3.78533;

//void function()
//{
//	static int called = 0;
//	called++;
//	std::cout << "I have been called " << called << " times" << std::endl;
//	return;
//}

float gallonConversion(float convert)
{
	litres = conversion * convert;
	std::cout << "When converted to litres this is " << litres << "L";
	return litres;
}

int main()
{
	/*for (int i = 0; i < 10; i++)
	{
		function();
	}*/

	std::cout << "Enter amount of gallons to be converted: ";
	std::cin >> gallons;
	gallonConversion(gallons);

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}



//double factor;
//double watts()
//{
//
//}
//double thrust()
//{
//
//}

// 1. Local variable is declared inside a function whereas global variable is declared outside the function
// Need to answer  question 3


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
