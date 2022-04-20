using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace AIE_xx_SaveContactV2
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
                if (!string.IsNullOrWhiteSpace(name)) sw.WriteLine("Name: " + name);
                if (!string.IsNullOrWhiteSpace(email)) sw.WriteLine("Email: " + email);
                if (!string.IsNullOrWhiteSpace(phone)) sw.WriteLine("Phone: " + phone);
            }
        }
        public void DeSerialise(string filename)
        {
            // Load contact details from text file 
            using (StreamReader sr = File.OpenText(filename))
            {      
                name = sr.ReadLine();
                email = sr.ReadLine();
                phone = sr.ReadLine();                              
            }
        }
        public void Print()
        {
            if (name != null) Console.WriteLine(name);
            if (email != null) Console.WriteLine(email);
            if (phone != null) Console.WriteLine(phone);
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}
