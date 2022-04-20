using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Interfaces
{
    interface IThrowable
    {
        float Drag
        {
            get;
        }

        void Throw(Vector3 throwPower);
    }
}
