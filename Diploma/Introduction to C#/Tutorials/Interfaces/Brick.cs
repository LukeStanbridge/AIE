using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Interfaces
{
    class Brick : GameObject, IThrowable
    {
        // IThrowable Implementation

        private float drag = 0.1f;

        public float Drag
        {
            get { return drag; }
        }

        public void Throw(Vector3 throwPower)
        {
            velocity = throwPower;
        }
    }
}
