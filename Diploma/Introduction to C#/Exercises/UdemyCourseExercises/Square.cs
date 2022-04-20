using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UdemyCourseExercises
{
    class Square
    {
        private int area;
        private int sidelength;

        // Constructor to assign the side length and calls fuction to calc area
        public Square(int length)
        {
            this.sidelength = length;
            CalcArea();
        }

        // Private function to claculate area
        private void CalcArea()
        {
            area = sidelength * sidelength;
        }

        // Read only properties to get squre's side length and area
        public int Side
        {
            get { return sidelength; }
        }
        public int Area
        {
            get { return area; }
        }
    }
}
