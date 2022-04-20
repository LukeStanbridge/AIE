using System;

namespace Task1_Exercise1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 1: INTRODUCTORY EXERCISES***********\n");          
            
            // Calls function
            AddNumbers();
        }

        static void AddNumbers()
        {
            Console.WriteLine("Exercise 1: Adding Two Numbers\n");

            float numX;
            float numY;

            // Enter first number as string, check to see if it's a valid input(a number) then convert to a float and store in numX
            Console.WriteLine("Enter first number: ");
            string numberAsString1 = Console.ReadLine();          
            while (!float.TryParse(numberAsString1, out numX))
            {
                Console.WriteLine("Invalid input, please enter a number!");
                numberAsString1 = Console.ReadLine();
            }
            Console.WriteLine();

            // Enter second number as string, check to see if it's a valid input(a number) then convert to a float and store in numY
            Console.WriteLine("Enter second number: ");
            string numberAsString2 = Console.ReadLine();          
            while (!float.TryParse(numberAsString2, out numY))
            {
                Console.WriteLine("Invalid input, please enter a number!");
                numberAsString2 = Console.ReadLine();
            }
            Console.WriteLine();

            // Calculates the sum of the two user entered numbers and converts it to an int
            float floatSum = numX + numY;
            int intSum = (int)floatSum;

            // Prints the sum of the two numbers and the floor of the sum for the user
            Console.WriteLine("The sum of " + numX + " + " + numY + " is: " + floatSum + "\n");
            Console.WriteLine("The floor of " + floatSum + " is: " + intSum + "\n");

            Console.ReadKey();
        }
    }
}
