using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FunctionsExercise
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Game game = new Game();
            game.score = 100;
            game.Start();
        }
    }

    class Game
    {
        public int score = 0;

        public int AddToScore(int add)
        {
            score += add;
            return score;
        }
        public void Start()
        {
            //for (int i = 0; i < 3; i++) PrintScore(25);
            PrintScore(10);
            PrintScore(20);
            PrintScore(30);
        }
        void PrintScore(int add)
        {
            Console.WriteLine($"The score is: {AddToScore(add)}");
            Console.ReadLine();
        }
    }
}
