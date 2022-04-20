using System;
using System.Diagnostics;

namespace Timing_Tutorial
{
    internal class Program
    {
        static void Main(string[] args)
        {
         
        }
    }

    public class Timer
    {
        Stopwatch stopwatch = new Stopwatch();
        private long currentTime = 0;
        private long lastTime = 0;

        private float deltaTime = 0.005f;

        public Timer()
        {
            stopwatch.Start();
        }

        public void Reset()
        {
            stopwatch.Reset();
        }

        // get time in seconds  
        public float Seconds
        {
            get { return stopwatch.ElapsedMilliseconds / 1000.0f; }
        }

        public float GetDeltaTime()
        {
            lastTime = currentTime;
            currentTime = stopwatch.ElapsedMilliseconds;
            deltaTime = (currentTime - lastTime) / 1000.0f;
            return deltaTime;
        }
    }

    // Calculate FPS
    class Game
    {
        Timer gameTime = new Timer();

        private float timer = 0;
        private int fps = 1;
        private int frames;

        private float deltaTime; 
 
 
        public void Update()
        {
            deltaTime = gameTime.GetDeltaTime();

            timer += deltaTime;
            if (timer >= 1)
            {
                fps = frames;
                frames = 0;
                timer -= 1;
            }
            frames++;

            // insert game logic here 
        }
    }
}
