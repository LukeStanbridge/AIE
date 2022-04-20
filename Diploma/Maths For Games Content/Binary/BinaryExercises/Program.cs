using System;

namespace Binary
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 31;
            int b = 13;
            int c = 0;

            c = ~a;
            Console.WriteLine(c);
            Console.ReadKey();
        }
    }
}
