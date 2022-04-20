using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExercisesOnClasses
{
    internal class Program
    {
        // Base Class - https://www.geeksforgeeks.org/c-sharp-program-to-illustrate-the-above-concept/
        public class Person
        {
            public string name;
            public string phoneNumber;
            public string emailAddress;

            public Person(string name, string phoneNumber, string emailAddress)
            {
                this.name = name;
                this.phoneNumber = phoneNumber;
                this.emailAddress = emailAddress;
            }
            public virtual void SayGreeting()
            {
                Console.WriteLine("Hello, I'm " + name + ", Phone Number: " + phoneNumber + ", Email Address: " + emailAddress);
            }
        }

        // Subclass
        public class Doctor : Person
        {
            public string doctorSalary;

            public Doctor(string name, string phoneNumber, string emailAddress, string salary) : base(name, phoneNumber, emailAddress)
            {
                doctorSalary = salary;
            } 

            public override void SayGreeting()
            {
                Console.WriteLine("Hello, I'm Dr " + name + ", I earn $" + doctorSalary + " a year!!");
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 3: EXERCISES ON CLASSES***********\n");
            Console.ReadKey();

            Console.WriteLine("Exercise 1: Greetings\n");

            // Creating instance
            Person p = new Person("Gary", "12345678", "gary@email.com");
            Person d = new Doctor("Bevan", "87654321", "drBevan@email.com", "5,000,000");

            p.SayGreeting();

            Console.WriteLine("-----------------------------------");

            d.SayGreeting();

            Console.ReadKey();         
        }
    }
}
