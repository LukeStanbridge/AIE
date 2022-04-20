using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IfStatementExercise
{
    internal class Program
    {
        static void Main()
        {
            bool playerAlive = true;       

            if (playerAlive)
            {
                Console.WriteLine("The player is still alive");
                
            }
            else
            {
                Console.WriteLine("The player has died");    
            }

            int invulnerabilityTimer = 5;
            invulnerabilityTimer -= 1;

            if (invulnerabilityTimer > 0)
            {            
                if (playerAlive)
                {
                    invulnerabilityTimer--;
                    Console.WriteLine("The player is invulnerable");
                }
            }
            else if(invulnerabilityTimer == 0)
            {
                Console.WriteLine("The player is now vulnerable to damage");
            }
            else if (invulnerabilityTimer < 0)
            {
                invulnerabilityTimer = 0;
            }

            Console.ReadKey();
        }
    }
}
