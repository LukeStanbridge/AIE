using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    public class Person : ILoggable
    {
        string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public void Log()
        {
            Console.WriteLine("My name is " + name + " and I am a person");
        }
    }
}
