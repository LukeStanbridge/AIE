using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ExercisesOnFiles
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 3: EXERCISES ON FILES***********\n");
            Console.ReadKey();

            ReadTextFile("words.txt");
            OrderedList("words.txt");
        }

        static void ReadTextFile(string readFile)
        {
            Console.WriteLine("Exercise 1: Alphabetise a File\n");
            Console.WriteLine("The file contains:\n");

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

        static void OrderedList(string sortFile)
        {
            Console.WriteLine("The file sorted alphabetically and stored in a text file:\n");
            string[] words = File.ReadAllLines(sortFile); // stores words from txt file into array
            Array.Sort(words); // sorts array alphabetically

            foreach (string word in words)
            {
                Console.WriteLine(word);
            }

            File.WriteAllLines("output.txt", words);

            Console.ReadKey();
        }
    }
}
