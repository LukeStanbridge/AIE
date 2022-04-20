using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LearningVariables
{
    internal class Program
    {
        static void Main()
        {
            string greeting = "Hello, user! The game's start condition is: ";
            bool gameStarted = false;
            string hungry = "Time for lunch? ";
            bool lunchTime = true;
            string displayGameState = greeting + gameStarted;
            string displayLunchTime = hungry + lunchTime;
            Console.WriteLine(displayGameState);
            Console.WriteLine(displayLunchTime);

            gameStarted = true;
            lunchTime = false;
            displayGameState = greeting + gameStarted;
            displayLunchTime = hungry + lunchTime;
            Console.WriteLine(displayGameState);
            Console.WriteLine(displayLunchTime);
            Console.ReadKey();
        }
    }
}
