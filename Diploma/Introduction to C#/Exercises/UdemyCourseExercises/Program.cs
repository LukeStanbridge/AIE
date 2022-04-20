using System;

namespace UdemyCourseExercises
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Square[] squares = new Square[10];

            //for (int i = 0; i < 10; i++)
            //{
            //    squares[i] = new Square(i + 1);
            //    Console.WriteLine("{0}, {1}", squares[i].Side, squares[i].Area);
            //}

            //Taxpayer[] taxpayer = new Taxpayer[3];           

            //for (int i = 0; i < taxpayer.Length; i++)
            //{
            //    taxpayer[i] = new Taxpayer();
            //    Console.WriteLine("Enter person #{0} Social Security Number", i + 1);
            //    taxpayer[i].SocialSecurityNumber = Console.ReadLine();
            //    Console.WriteLine("Enter person #{0} yearly income", i + 1);
            //    taxpayer[i].YearlyGrossIncome = double.Parse(Console.ReadLine());
            //}

            //for(int i = 0;i < taxpayer.Length;i++)
            //{
            //    Console.WriteLine("Tax payer #{0}, SSN = {1}, Income = {2}, Tax Owed = {3}", i + 1, taxpayer[i].SocialSecurityNumber, taxpayer[i].YearlyGrossIncome, taxpayer[i].TaxOwed);
            //}

            Job job1 = new Job("wash windows", 5, 15);
            Console.WriteLine("{0}, {1} hours, ${2}, ${3}", job1.JobDescription, job1.JobTime, job1.RateCharged, job1.TotalFee);
            Job job2 = new Job("take out trash", 2, 12.50);
            Console.WriteLine("{0}, {1} hours, ${2}, ${3}", job2.JobDescription, job2.JobTime, job2.RateCharged, job2.TotalFee);
            Job job3 = job1 + job2;
            Console.WriteLine("{0}, {1} hours, ${2}, ${3}", job3.JobDescription, job3.JobTime, job3.RateCharged, job3.TotalFee);

            Console.ReadKey();
        }
    }
}
