using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextAdventure
{
    /// <summary>
    /// The base exit class used for all room exits
    /// The default behavior is to allow the player to move between rooms by using the Go verb, but can easily be extended for locks, puzzles and traps
    /// </summary>
    internal class Exit : BaseObject
    {
        public Room Destination { get; private set; }
        public Exit(string name, string description, Room destination)
        {
            Name = name;
            Description = description;
            Destination = destination;
        }
        public override bool ProcessInput(Game game, UserInput input)
        {
            if (input.Target.Equals(Name, StringComparison.OrdinalIgnoreCase))
            {
                if (input.Verb == Verb.Go)
                {
                    Console.WriteLine($"You move {Name.ToLower()}...\n");
                    game.CurrentRoom = Destination;
                    game.CurrentRoom.ProcessInput(game, new UserInput("look"));
                    return true;
                }
                else if (input.Verb == Verb.Look)
                {
                    Console.WriteLine($"You peer at the {Name} exit");
                    Console.WriteLine($"{Description}");
                    return true;
                }
            }
            return false;
        }
    }
}
