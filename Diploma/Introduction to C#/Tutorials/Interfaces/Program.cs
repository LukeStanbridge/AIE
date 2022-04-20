using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Interfaces
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Make some GmaeObjects
            Ball ball = new Ball();
            Brick brick = new Brick();

            Person person = new Person();
            Person person1 = new Person();
            person.Name = "Gary";
            person1.Name = "Trent";         
            person.Log();
            person1.Log();

            Console.ReadKey();

            // Colection of throwable objects
            List<IThrowable> throwables = new List<IThrowable>();
            throwables.Add(brick);
            throwables.Add(ball);

            // Collection of bouncable objects
            List<IBouncable> bouncables = new List<IBouncable>();
            bouncables.Add(ball);
            //bouncables.Add(brick); // Brick is not bouncable!
        }
    }
}
