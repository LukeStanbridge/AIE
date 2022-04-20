using System;

namespace Task1_Exercise2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 1: INTRODUCTORY EXERCISES***********\n");
            
            // Calls function
            Fibonacci();           
        }

        static void Fibonacci()
        {
            Console.WriteLine("Exercise 2: Fibonacci\n");
            Console.WriteLine("How long do you want your fibonacci sequence to be?");
            
            int fibLength = 0;
            bool valid = false;

            // While loop to check if user input is valid input(a number).
            // Also checks within the number range(stop users spamming massive numbers into the program)
            while (!valid)
            {
                string nLength = Console.ReadLine();
                while (!int.TryParse(nLength, out fibLength))
                {
                    Console.WriteLine("Invalid input, please enter a number!");
                    nLength = Console.ReadLine();
                }
                if (fibLength < 1 || fibLength > 20)
                {
                    Console.WriteLine("Number has to be between 1 and 20!");
                }
                else
                {
                    valid = true;
                }
            }

            // Creates necessary variables and a for loop to calculate the fibonacci sequence
            // Prints the results based on the user entered number
            Console.Write("The Fibonacci Sequence for a length of {0} is: ", fibLength);
           
            int a = -1;
            int b = 1;
            int c = 0;
           
            for (int i = 0; i < fibLength; i++)
            {
                c = a + b;
                Console.Write(c + " ");
                a = b;
                b = c;
            }
            Console.ReadKey();
        }
    }
}
