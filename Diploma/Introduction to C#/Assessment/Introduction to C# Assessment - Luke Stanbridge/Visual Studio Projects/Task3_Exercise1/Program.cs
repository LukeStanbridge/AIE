using System;
using System.IO;
using System.Linq;

namespace Task3_Exercise1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 3: EXERCISES ON FILES***********\n");
            Console.WriteLine("Exercise 1: Alphabetize a File\n");
            Console.ReadKey();

            // Calls functions and passes in text file
            ReadTextFile("words2.txt");
            OrderedList("words2.txt");
        }

        // Function checks if file exists then reads and prints all lines
        static void ReadTextFile(string readFile)
        {           
            Console.WriteLine("The original text file contains:\n");

            if (File.Exists(readFile))
            {
                using (StreamReader file = new StreamReader(readFile))
                {
                    string ln;

                    while ((ln = file.ReadLine()) != null)
                    {
                        Console.WriteLine(ln);
                    }
                    file.Close();
                }
                Console.WriteLine();
                Console.ReadKey();
            }
        }

        // Function stores all words into string array, sorts array alphabetically and prints sorted array
        // Also writes alphabetically sorted words to a new text file
        static void OrderedList(string sortFile)
        {
            Console.WriteLine("The text file sorted alphabetically and stored in the output.txt file:\n");
            string[] words = File.ReadAllLines(sortFile);
            words = words.Skip(1).ToArray(); // Skips the first line of the array
            Array.Sort(words); 

            foreach (string word in words)
            {
                Console.WriteLine(word);
            }

            File.WriteAllLines("output2.txt", words);
            Console.ReadKey();
        }
    }
}
