using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    interface IBouncable
    {
        float BounceEnergy
        {
            get;
        }

        void Bounce();
    }
}
