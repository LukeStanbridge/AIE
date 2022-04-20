using System;

namespace Task2_Exercise2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 2: EXERCISES ON ARRAYS***********\n");
            Console.WriteLine("Exercise 2: Sorting an Array (Descending)\n");
            Console.ReadKey();

            // Initialises array of numbers
            int[] sortArray1 = { 4, 3, 2, 1, 0, };
            int[] sortArray2 = { 4, 3, 4, 3, 4 };
            int[] sortArray3 = { 1, 8, 9, 4, 0, 6, 7, 5 };

            // Calls function and passes in array
            SortDescending(sortArray1);
            SortDescending(sortArray2);
            SortDescending(sortArray3);
        }

        static void SortDescending(int[] numbers)
        {
            Console.Write("The array { ");
            // Prints original array before sorting
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.Write(numbers[i] + " ");
            }
            Console.Write("} sorted in descending order - { ");

            // Sorts and prints array after sorting in descending order
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
            Console.WriteLine("}\n");
            Console.ReadKey();
        }


    }
}