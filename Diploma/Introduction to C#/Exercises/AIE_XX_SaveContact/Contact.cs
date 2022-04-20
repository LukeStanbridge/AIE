using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace AIE_XX_SaveContact
{
    internal class Contact
    {
        public string name = "";
        public string email = "";
        public string phone = "";
        public Contact()
        {
        }
        public Contact(string name, string email, string phone)
        {
            this.name = name;
            this.email = email;
            this.phone = phone;
        }
        public void Serialise(string filename)
        {
            // Creates contacts folder to save files to
            var fileInfo = new FileInfo(filename);
            Directory.CreateDirectory(fileInfo.Directory.FullName);

            // Save contact details to text file
            using (StreamWriter sw = File.CreateText(filename))
            {
                sw.WriteLine(name);
                sw.WriteLine(email);
                sw.WriteLine(phone);
            }
        }
        public void DeSerialise(string filename)
        {
            // Load contact details from text file 
            using(StreamReader sr = File.OpenText(filename))
            {
                name = sr.ReadLine();
                email = sr.ReadLine();
                phone = sr.ReadLine();
            }
        }
        public void Print()
        {
            Console.WriteLine($"{name}");
            Console.WriteLine($"{email}");
            Console.WriteLine($"{phone}");
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}
