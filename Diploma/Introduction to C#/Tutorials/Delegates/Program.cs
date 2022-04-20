using System;

namespace Delegates
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // create a new list 
            ListWithChangedEvent list = new ListWithChangedEvent();

            // create a class that listens for when the list is changed 
            EventListener listener = new EventListener(list);

            list.Add("hello");
            list.Add("world");
            list.Add("bye");
            list.Clear();
            listener.Detatch();


            Console.ReadKey();
        }
    }
}
