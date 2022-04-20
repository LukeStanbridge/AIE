using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextAdventure
{
    internal class BaseObject
    {
        /// <summary>
        /// The generic name for this object
        /// </summary>
        public virtual string Name { get; protected set; } = String.Empty;
        /// <summary>
        /// The generic description for this object (i.e. used by the look verb)
        /// </summary>
        public virtual string Description { get; protected set; } = String.Empty;
        /// <summary>
        /// Processes user input and prints out information and/or modifies gamestate
        /// Override this method to provide custom behaviour
        /// </summary>
        /// <returns>Returns true if the input was accepted or false otherwise, use to prevent other interested parties from processing the input afterwards</returns>
        public virtual bool ProcessInput(Game game, UserInput input)
        {
            return false;
        }
    }
}
