using System;

namespace Task4_Exercise1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 4: EXERCISES ON CLASSES***********\n");
            
            Console.WriteLine("Exercise 1: Greetings\n");
            Console.ReadKey();

            // Creating instance of person and doctor
            Person p = new Person("Gary", "12345678", "gary@email.com");
            Person d = new Doctor("Bevan", "87654321", "drBevan@email.com", "5,000,000");

            p.SayGreeting();

            Console.WriteLine("-----------------------------------");

            d.SayGreeting();

            Console.ReadKey();
        }

        // Base class
        public class Person
        {
            public string name;
            public string phoneNumber;
            public string emailAddress;

            // Stores string variables that are being passed from created instance in Main() to the variables created above
            public Person(string name, string phoneNumber, string emailAddress)
            {
                this.name = name;
                this.phoneNumber = phoneNumber;
                this.emailAddress = emailAddress;
            }
            // Greeting function for when an instance of a person is created
            public virtual void SayGreeting()
            {
                Console.WriteLine("Hello, I'm " + name + ", Phone Number: " + phoneNumber + ", Email Address: " + emailAddress);
            }
        }

        // Subclass
        public class Doctor : Person
        {
            private string salary;

            // Stores string variables(name, phone and email) in base class and salary in Doctor class 
            public Doctor(string name, string phoneNumber, string emailAddress, string salary) : base(name, phoneNumber, emailAddress)
            {
                this.salary = salary;
            }

            // Greeting function for when an instance of a doctor is created
            public override void SayGreeting()
            {
                Console.WriteLine("Hello, I'm Dr " + name + ", I earn $" + salary + " a year!!");
            }
        }
    }
}
