using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Interfaces
{
    internal class Ball : GameObject, IThrowable, IBouncable
    {
        // IThrowable Implementation

        private float drag = 0.2f;

        public float Drag
        {
            get { return drag; }
        }

        public void Throw(Vector3 throwPower)
        {
            velocity = throwPower;
        }

        // IBouncable Implementation

        private float bounceEnergy = 0.8f;

        public float BounceEnergy
        {
            get { return bounceEnergy; }
        }

        public void Bounce()
        {
            velocity = velocity * -1; // Not quite how bouncing works
        }
    }
}
