using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LoopsExercise
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int count = 0;
            int score = 0;
            int score2 = 0;

            while (count < 10 && score < 100)
            {
                count++;
                Console.WriteLine("The loop has run " + count + " times.");
                score += 20;
                Console.WriteLine("The while loop score is: " + score);
            }
            Console.ReadKey();

            for (int i = 1; i < 21; i++)
            {
                if (score2 >= 100)
                {
                    break;
                }

                Console.WriteLine("The loop has run " + i + " times.");
                score2 += 20;
                Console.WriteLine("The for loop score is: " + score2);
            }
            Console.ReadKey();
        }
    }
}
