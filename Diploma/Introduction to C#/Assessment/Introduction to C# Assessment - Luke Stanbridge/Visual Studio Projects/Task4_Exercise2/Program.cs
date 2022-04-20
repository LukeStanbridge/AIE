using System;

namespace Task4_Exercise2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***********APPENDIX 4: EXERCISES ON CLASSES***********\n");

            Console.WriteLine("Exercise 2: Text Adventure\n");
            
            // Creates an multi dimension array of rooms(3x3)
            Room[,] map = new Room[3, 3];           

            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    map[row, col] = new Room();
                }
            }

            // Creates an instance of player, enemy and power up
            Player p = new Player(1, 1, 20, 20, 10);
            Enemy e = new Enemy(2, 0, 10, 27, 6);
            PowerUp pu = new PowerUp(0, 1, 10);

            // Assigns the array location and adds an object to that room
            map[1, 1].AddGameObject(p);
            map[2, 0].AddGameObject(e);
            map[0, 1].AddGameObject(pu);                     

            // Prints out the rooms and any objects that have been added to the rooms
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    map[row, col].Draw();
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }

        public class Room
        {
            // Creates the array for objects to placed in the room
            GameObject[] objects = new GameObject[3];

            // Function to check position of objects array is null then set as object being passed in (e.g. a player)
            public void AddGameObject(GameObject gmObj)
            {
                for (int i = 0; i < objects.Length; i++)
                {
                    if (objects[i] == null)
                    {
                        objects[i] = gmObj;
                    }
                }
            }

            public void RemoveGameObject(GameObject gmObj)
            {
                // Locates object to be removed in array and sets it to null 
                for (int i = 0; i < objects.Length; i++)
                {
                    if (objects[i] == gmObj)
                    {
                        objects[i] = null;
                    }
                    break;
                }

                // Moving Objects left most Index
                for (int i = objects.Length - 1; i > 0; i--)
                {
                    int j = i - 1;
                    while (j >= 0)
                    {
                        if (objects[j] == null)
                        {
                            // Swap Objects
                            objects[j] = objects[i];
                            objects[i] = null;
                        }
                        j--;
                    }
                }
            }

            public void Draw()
            {
                if (objects[0] == null)
                {
                    Console.Write("_");
                }
                else
                {
                    objects[0].Draw();
                }               
            }
        }

        public abstract class GameObject
        {
            public GameObject(int x, int y)
            {
                xPosition = x;
                yPosition = y;
            }

            protected int xPosition { get; set; }
            protected int yPosition { get; set; }
            public virtual void Draw()
            {
                Console.Write("8---D");
            }
        }

        public abstract class Character : GameObject
        {
            public Character(int x, int y, int at, int hp, int df) : base (x, y)
            {
                attack = at;
                healthPoints = hp;
                defense = df;
            }

            protected int attack { get; set; }
            protected int healthPoints { get; set; }
            protected int defense { get; set; }

            public bool IsAlive()
            {
                return true;
            }
        }

        public class PowerUp : GameObject
        {
            public PowerUp(int x, int y, int extraHp) : base (x, y)
            {
                defense += extraHp;
            }
            protected int defense { get; set; }
            public override void Draw()
            {
                Console.Write("?");             
            }
        }

        public class Player : Character
        {
            public Player(int x, int y, int at, int hp, int df) : base (x, y, at, hp, df)
            {
                attack = at;
                healthPoints = hp;
                defense = df;
            }
            public override void Draw()
            {
                Console.Write("X");
            }
        }

        public class Enemy : Character
        {
            public Enemy(int x, int y, int at, int hp, int df) : base (x, y, at, hp, df)
            {
                attack = at;
                healthPoints = hp;
                defense = df;
            }
            public override void Draw()
            {
                if (healthPoints > 10)
                {
                    Console.Write("O");
                }
                else
                {
                    Console.Write("o");
                }
            }
        }
    }
}
