using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Introductory_Exercises
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 1: INTRODUCTORY EXERCISES***********\n");
            Console.ReadKey();
            //AddNumbers();
            Fibonacci();
            //FizzBuzz();
        }

        static void AddNumbers()
        {
            Console.WriteLine("Exercise 1: Adding Two Numbers\n");

            // Enter first number as string, check to see if it's a valid input(a number) then convert to a float and store in numX
            Console.WriteLine("Enter first number: ");
            string numberAsString1 = Console.ReadLine();

            float numX;

            while (!float.TryParse(numberAsString1, out numX))
            {
                Console.WriteLine("Invalid input, please enter a number!");
                numberAsString1 = Console.ReadLine();
            }

            numX = float.Parse(numberAsString1);
            Console.WriteLine();

            // Enter second number as string, check to see if it's a valid input(a number) then convert to a float and store in numY
            Console.WriteLine("Enter second number: ");
            string numberAsString2 = Console.ReadLine();

            float numY;

            while (!float.TryParse(numberAsString2, out numY))
            {
                Console.WriteLine("Invalid input, please enter a number!");
                numberAsString2 = Console.ReadLine();
            }

            numY = float.Parse(numberAsString2);
            Console.WriteLine();

            // Calculates the sum of the two user entered numbers
            float sum = numX + numY;

            // Prints the sum of the two numbers and the floor of the sum
            Console.WriteLine("The sum of " + numX + " + " + numY + " is: " + sum + "\n");
            Console.WriteLine("The floor of " + sum + " is: " + Math.Floor(sum) + "\n");

            Console.ReadKey();
        }

        static void Fibonacci()
        {
            Console.WriteLine("Exercise 2: Fibonacci\n");
            Console.WriteLine("How long do you want your fibonacci sequence to be?");

            float fibLength = 0;
            bool valid = false;
            
            // While loop to check if user input is valid input(a number) and within the number range(stop users spamming massive numbers into the program)
            while (!valid)
            {                
                string nLength = Console.ReadLine();
                while (!float.TryParse(nLength, out fibLength))
                {
                    Console.WriteLine("Invalid input, please enter a number!");
                    nLength = Console.ReadLine();
                }
                if (fibLength < 0 || fibLength > 20)
                {
                    Console.WriteLine("Number has to be between 1 and 20! No big bigBoi.chonk files allowed");
                }
                else
                {
                    valid = true;
                }
            }
            
            int a = 0;
            int b = 1;
            int c = 0;

            Console.Write("The Fibonacci Sequence for a length of {0} is: 0 1 ", fibLength);

            for (int i = 2; i < fibLength; i++)
            {
                c = a + b;
                Console.Write(c + " ");
                a = b;
                b = c;
            }
            Console.WriteLine("\n");
            Console.ReadKey();              
        }
        static void FizzBuzz()
        {
            Console.WriteLine("Exercise 3: FizzBuzz\n");
            Console.WriteLine("How long do you want your FizzBuzz sequence to be?");
            string nLength = (Console.ReadLine());

            float fizzBuzzLength;

            while (!float.TryParse(nLength, out fizzBuzzLength))
            {
                Console.WriteLine("Invalid input, please enter a number!");
                nLength = Console.ReadLine();
            }

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
