using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextAdventure
{
    /// <summary>
    /// The base room class, contains exits that link to other rooms as well as a basic description
    /// The default behaviour can be overriden using the ProcessInput(...) method
    /// Be sure to call base.ProcessInput(...) if you want default behaviour to still occur when custom behaviour has not been triggered
    /// </summary>
    internal class Room : BaseObject
    {
        public List<Exit> Exits { get; private set; } = new List<Exit>();
        public Room(string description)
        {
            Description = description;
        }
        /// <summary>
        /// Handles the look verb by printing a description of the room and it's exits
        /// </summary>
        protected bool Look(Game game, UserInput input)
        {
            if (input.Target == "" || input.Target == "room")
            {
                Console.WriteLine("Looking around the room you see:");
                Console.WriteLine(Description);
                Console.WriteLine();
                Console.WriteLine();
                if (Exits.Count > 0)
                {
                    Console.Write("Visible exits: ");
                    for (int i = 0; i < Exits.Count; i++)
                    {
                        Console.Write(Exits[i].Name);
                        if (i < Exits.Count - 1) Console.Write(", ");
                    }
                    Console.WriteLine();
                }
                else
                {
                    Console.WriteLine("There are no exits...");
                }
                return true;
            }
            return false;
        }

        protected bool Go(Game game, UserInput input)
        {
            if (input.Target == "" || input.Target == "room")
            {
                Console.WriteLine("Go to the peanut, tiger or door?");
                return true;
            }
            return false;
        }
        public override bool ProcessInput(Game game, UserInput input)
        {
            if (input.Verb == Verb.Look && Look(game, input))
            {
                return true;
            }
            // Handle input for any exits connected to this room
            foreach (Exit exit in Exits)
            {
                if (exit.ProcessInput(game, input))
                {
                    return true;
                }
            }
            return false;
        }
    }
}
