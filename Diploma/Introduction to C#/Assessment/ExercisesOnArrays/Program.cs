using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExercisesOnArrays
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Create arrays for adding and sorting numbers
            int[] sumArray1 = { 0, 1, 2, 3};
            int[] sumArray2 = { 2, 4, 8, 16, 32, 64, };
            int[] sumArray3 = { 33, 74, 52, 9 };

            int[] sortArray1 = { 4, 3, 2, 1, 0, };
            int[] sortArray2 = { 4, 3, 4, 3, 4 };
            int[] sortArray3 = { 1, 8, 9, 4, 0, 6, 7, 5 };

            Console.WriteLine("***********APPENDIX 2: EXERCISES ON ARRAYS***********\n");
            Console.ReadKey();

            // Call functions for adding and sorting the arrays I created
            SumOfArray(sumArray1);
            SumOfArray(sumArray2);
            SumOfArray(sumArray3);
            
            SortDescending(sortArray1);
            SortDescending(sortArray2);
            SortDescending(sortArray3);
        }

        static void SumOfArray(int[] numbers)
        {
            Console.WriteLine("Exercise 1: Sum of Array\n");
            
            // For loop that adds every number in array to the variable "sum" and returns the total
            int sum = 0;

            for (int i = 0; i < numbers.Length; i++)
            {
                sum += numbers[i];
            }

            Console.WriteLine("The sum of the array numbers is: " + sum + "\n");
            Console.ReadKey();
        }

        static void SortDescending(int[] numbers)
        {
            Console.WriteLine("Exercise 2: Sorting an Array (Descending)\n");
       
            int temp;

            for (int i = 0; i < numbers.Length; i++)
            {
                for (int j = i + 1; j < numbers.Length; j++)
                {
                    if (numbers[j] > numbers[i])
                    {
                        temp = numbers[i];
                        numbers[i] = numbers[j];
                        numbers[j] = temp;
                    }
                }
                Console.Write(numbers[i] + " ");
            }
            Console.WriteLine("\n");
            Console.ReadKey();
        }
    }
}
