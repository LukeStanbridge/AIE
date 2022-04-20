using System;
using System.Collections.Generic;

namespace Quiz
{
    internal class Program
    {       
        public static void Main(string[] args)
        {
            Console.WriteLine(IsIsogram("Algorism")); // should output true
            Console.WriteLine(IsIsogram("pasSword")); // should output false
            Console.WriteLine(IsIsogram("Consecutive")); // should output false

            Console.WriteLine(ToScottishScreaming("hello world")); // HELLE WERLD
            Console.WriteLine(ToScottishScreaming("Mr. Fox was very naughty")); // MR. FEX WES VERY NEEGHTY
            Console.WriteLine(ToScottishScreaming("Butterflies are beautiful!")); // BETTERFLEES ERE BEEETEFEL!

            Console.WriteLine(ValidateEmail("@gmail.com")); // expected: false
            Console.WriteLine(ValidateEmail("hello.gmail@com")); // expected: false
            Console.WriteLine(ValidateEmail("gmail")); // expected: false
            Console.WriteLine(ValidateEmail("hello@gmail")); // expected: false
            Console.WriteLine(ValidateEmail("hello@edabit.com")); // expected: true

            Console.ReadKey();
        }

        static bool IsIsogram(string word)
        {
            word = word.ToLower(); // Convert to lower case other wise the capital in "pasSword" appears different

            char[] arr = word.ToCharArray(); // store each character in word into an array

            Array.Sort(arr); // sorts array into alphabetical order
            for (int i = 0; i < word.Length - 1; i++) // loops through each letter in arr to check if two char's next to each other in the array are the same
            {
                if (arr[i] == arr[i + 1])
                {
                    return false;
                }
            }
            return true;
        }

        static string ToScottishScreaming(string word)
        {
            word = word.ToUpper();

            word = word.Replace('A', 'E');
            word = word.Replace('I', 'E');
            word = word.Replace('O', 'E');
            word = word.Replace('U', 'E');
            return word;
        }

        static bool ValidateEmail(string word)
        {
            char check1 = '.';
            char check2 = '@';
            if (word.Contains(check1) && word.Contains(check2) && word.IndexOf(check2) >= 1)
            {
                if (word.IndexOf(check1) > word.IndexOf(check2))
                {
                    return true;
                }               
            }
            return false;
        }
    }
}
