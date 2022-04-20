using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sorting
{
    internal class Program
    {
        public int swapCount = 0;
        public int comparisonCount = 0;
        void Main()
        {
            //Define our data 
            int[] arrayToBeSorted = new int[]{14,65,63,1,54,89,84,9,98,57,71,18,21,84,69,28,11,83,13,42,64,58,78,82,13,9,96,14,39,89,40,32,51,85,48,40,23,15,94,93,35,81,1,9,43,39,15,17,97,52};

            //Print the unsorted array 
            Console.WriteLine("Unsorted");
            printArray(arrayToBeSorted);

            BubbleSort(arrayToBeSorted);

            //Print the sorted array
            Console.WriteLine("\nSorted");
            printArray(arrayToBeSorted);

            Console.WriteLine("Number of swaps: " + swapCount);
            Console.WriteLine("Number of comparisons: " + comparisonCount);

            Console.ReadLine();
        }
        
        //iterates through each element from index 0 to n, and outputs it 
        void printArray(int[] array)
        {
            //Prints the array and formats it into 10 columns and puts two new lines at the end
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write("{0},\t", array[i]);
                if (i % 10 == 9)
                {
                    Console.WriteLine();
                }
            }
            Console.WriteLine();
            Console.WriteLine();
        }
        
        //sorts through the algorithm and arranges values in ascending order
        void BubbleSort(int[] array)
        {
            //Bail for single element or invalid indices 
            if (array.Length <= 1) return;

            //Track if list is sorted 
            bool sorted = false; //set to false to ensure the while loop starts up 
            while (!sorted)
            {
                sorted = true;

                for (int i = 0; i < array.Length - 1; ++i)
                {
                    if (array[i] > array[i + 1])
                    {
                        int tmp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = tmp;
                        sorted = false;
                        swapCount++;
                    }
                }
            }
        }

        void Comparison(int x, int y)
        {
            comparisonCount++;
            if (x > y)
            {
                return;
            }
        }
    }
}
