using System;

namespace AdventureGame
{
    internal class Program
    {
        public class Room
        {
            GameObject[] objects = new GameObject[3];
            public void AddGameObject(GameObject gmObj)
            {
                 for(int i = 0; i < objects.Length; i++)
                {
                    if(objects[i] == null)
                    {
                        objects[i] = gmObj;
                    }
                }
            }

            public void RemoveGameObject(GameObject gmObj)
            {
                for (int i = 0; i < objects.Length; i++)
                {
                    if (objects[i] == gmObj)
                    {
                        objects[i] = null;
                    }
                    break;
                }

                //Moving Objects Leftmost Index
                for (int i = objects.Length - 1; i > 0; i--)
                {
                    int j = i - 1;
                    while(j >= 0)
                    {
                        if (objects[j] == null)
                        {
                            //Swap Objects
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

        public class GameObject
        {
            int xPosition;
            int yPosition;
            public virtual void Draw()
            {

            }
        }

        public class Character : GameObject
        {
            protected int attack;
            protected int healthPoints;
            protected int defence;
            public bool IsAlive()
            {
                return true;
            }
        }

        public class PowerUp : GameObject
        {
            public override void Draw()
            {
                Console.Write("?");
            }
        }
        public class Player : Character
        {
            public Player()
            {

            }
            public override void Draw()
            {
                Console.Write("X");
            }
        }


        public class Enemy : Character
        {
            public Enemy(int at, int hp, int df)
            {
                this.attack = at;
                this.healthPoints = hp;
                this.defence = df;
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

        static void Main(string[] args)
        {
            Room[,] map = new Room[3, 3];

            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    map[row, col] = new Room();
                }
            }

            // Creates an instance
            Player p = new Player();
            Enemy e = new Enemy(10, 27, 6);
            PowerUp pu = new PowerUp();

            map[1, 1].AddGameObject(p);
            map[2, 0].AddGameObject(e);
            map[0, 1].AddGameObject(pu);



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
    }
}
