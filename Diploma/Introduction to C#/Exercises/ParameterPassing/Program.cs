using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParameterPassing
{
    public class IntHolder
    {
        public int i;
    }
    internal class Program
    {
        static void Foo(IntHolder x)
        {
            x = new IntHolder();
        }
        static void Main(string[] args)
        {
            IntHolder y = new IntHolder();
            y.i = 5;

            Foo(y);

            Console.WriteLine(y.i);
            Console.ReadKey();

        }
    }
}
