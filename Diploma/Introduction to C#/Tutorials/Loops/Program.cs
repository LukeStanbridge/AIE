using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Loops
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int count = 0;

            while (count < 3)
            {
                count++;
                Console.WriteLine("The loop has run " + count + " times.");
            }
            Console.ReadKey();

            for (int counter = 3; counter >= 1; counter -= 2)
            {
                Console.WriteLine("The loop has run " + counter + " times.");
                if (counter == 2)
                {
                    break;
                }
            }
            Console.WriteLine("The loop is now finished.");
            Console.ReadKey();
        }
    }
}
