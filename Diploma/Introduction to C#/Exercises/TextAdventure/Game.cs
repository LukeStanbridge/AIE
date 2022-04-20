using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextAdventure
{
    internal class Game
    {
        public Room CurrentRoom { get; set; }
        public void Setup()
        {
            Room room = new Room(String.Join("\n", "A peanut",
                                                   "A tiger",
                                                   "A door"));
            Room northRoom = new Room("You are now in the north room");
            northRoom.Exits.Add(new Exit("South", "A plain door", room));

            room.Exits.Add(new Exit("North, A plain door labelled 'Exit'", northRoom));

            CurrentRoom = room;
        }
        public void Run()
        {
            CurrentRoom.ProcessInput(this, new UserInput("look"));
            do
            {
                Console.WriteLine("What next?");
                UserInput userInput = new UserInput(Console.ReadLine() ?? "");
                Console.WriteLine();
                if (!CurrentRoom.ProcessInput(this, userInput))
                {
                    if (userInput.Verb == Verb.Quit)
                    {
                        Console.WriteLine("Goodbye!");
                        break;
                    }                   
                }
            } while (true);

            CurrentRoom.ProcessInput(this, new UserInput("go"));
            do
            {
                Console.WriteLine("Go to the peanut, tiger or door?");
                UserInput userInput = new UserInput(Console.ReadLine() ?? "");
                Console.WriteLine();
                if (!CurrentRoom.ProcessInput(this, userInput))
                {
                    if (userInput.Verb == Verb.Quit)
                    {
                        Console.WriteLine("Goodbye!");
                        break;
                    }
                }
            } while (true);
        }
    }
}
