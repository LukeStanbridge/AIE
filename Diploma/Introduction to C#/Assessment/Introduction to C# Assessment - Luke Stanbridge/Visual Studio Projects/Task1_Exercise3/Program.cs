using System;

namespace Task1_Exercise3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 1: INTRODUCTORY EXERCISES***********\n");

            // Calls function
            FizzBuzz();
        }

        static void FizzBuzz()
        {
            Console.WriteLine("Exercise 3: FizzBuzz\n");
            Console.WriteLine("How long do you want your FizzBuzz sequence to be?");

            int fizzBuzzLength = 0;
            bool valid = false;

            // While loop to check if user input is valid input(a number).
            // Also checks within the number range(stop users spamming massive numbers into the program)
            while (!valid)
            {
                string nLength = Console.ReadLine();
                while (!int.TryParse(nLength, out fizzBuzzLength))
                {
                    Console.WriteLine("Invalid input, please enter a number!");
                    nLength = Console.ReadLine();
                }
                if (fizzBuzzLength < 1 || fizzBuzzLength > 30)
                {
                    Console.WriteLine("Number has to be between 1 and 30!");
                }
                else
                {
                    valid = true;
                }               
            }
            Console.WriteLine();

            // For loop to print out either the number, "Fizz", "Buzz" or "FizzBuzz" in the required scenarios
            for (int i = 1; i <= fizzBuzzLength; i++)
            {
                if (i % 3 == 0 && i % 5 == 0)
                {
                    Console.WriteLine("FizzBuzz");
                }
                else if (i % 3 == 0)
                {
                    Console.WriteLine("Fizz");
                }
                else if (i % 5 == 0)
                {
                    Console.WriteLine("Buzz");
                }
                else
                {
                    Console.WriteLine(i);
                }
            }
            Console.ReadKey();
        }
    }
}
