using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Interfaces
{
    class GameObject
    {
        public Vector3 position;

        public Vector3 velocity;

        void Update(float deltaTime)
        {
            position = position + (velocity * deltaTime);
        }
    }
}
