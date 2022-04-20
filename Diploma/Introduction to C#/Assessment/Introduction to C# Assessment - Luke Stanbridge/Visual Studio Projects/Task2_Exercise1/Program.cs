using System;

namespace Task2_Exercise1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 2: EXERCISES ON ARRAYS***********\n");
            Console.WriteLine("Exercise 1: Sum of Array\n");
            Console.ReadKey();

            // Initialises array of numbers
            int[] sumArray1 = { 0, 1, 2, 3 };
            int[] sumArray2 = { 2, 4, 8, 16, 32, 64, };
            int[] sumArray3 = { 33, 74, 52, 9 };
            
            // Calls function and passes in array
            PrintArray(sumArray1);
            PrintArray(sumArray2);
            PrintArray(sumArray3);           
        }

        // Function that uses a for loop to add every number in array to the variable "sum", then returns that value
        static int SumOfArray(int[] numbers)
        {                     
            int sum = 0;

            for (int i = 0; i < numbers.Length; i++)
            {
                sum += numbers[i];
            }
            return sum;           
        }

        // Function that calls the SumOfArray function then prints out the contents of the array and its sum 
        static void PrintArray(int[] numbers)
        {
            int sumOfArray = SumOfArray(numbers);

            Console.Write("The sum of the array { ");
            for (int i = 0;i < numbers.Length;i++)
            {
                Console.Write(numbers[i] + " ");
            }
            Console.Write("} is: " + sumOfArray + "\n\n");
            Console.ReadKey();
        }
    }
}
