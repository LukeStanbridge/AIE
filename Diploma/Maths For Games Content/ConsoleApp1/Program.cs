using System;
using System.Numerics;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Exercise1A(10));

            float root = Exercise1B3(1, 2, 3);
            if (float.IsNaN(root))
            {

            }

            Console.WriteLine(Exercise1C(1, 2, 3));

            //Vector3 p1 = new Vector3(1, 2, 3);
            //Vector3 p2 = new Vector3(4, 5, 6);
            //float v = Exercise1D(p1, p2);

            Console.WriteLine(TraingleSides(6, 8, 9));
            Console.ReadKey();
            
        }

        static float Exercise1A(float x)
        {
            float y = (x * x) + (2 * x) - 7;
            return y;
        }

        static float? Exercise1B(float a, float b, float c)
        {
            float d = ((b * b) - (4 * a * c));
            float x1, x2;
            
            if (d < 0)
            {
                return null;
            }
            else
            {
                x1 = (float)((-b + Math.Sqrt(d)) / (2 * a));
                x2 = (float)((-b - Math.Sqrt(d)) / (2 * a));
                return x1;
            }                
        }

        static (float x1, float x2)? Exercise1B2(float a, float b, float c)
        {
            float d = ((b * b) - (4 * a * c));
            float x1, x2;

            if (d < 0)
            {
                return null;
            }
            else
            {
                x1 = (float)((-b + Math.Sqrt(d)) / (2 * a));
                x2 = (float)((-b - Math.Sqrt(d)) / (2 * a));
                return (x1, x2);
            }
        }

        static float Exercise1B3(float a, float b, float c)
        {
            float d = ((b * b) - (4 * a * c));
            float x1, x2;

            if (d < 0)
            {
                return float.NaN;
            }
            else
            {
                x1 = (float)((-b + Math.Sqrt(d)) / (2 * a));
                x2 = (float)((-b - Math.Sqrt(d)) / (2 * a));
                return x1;
            }
        }

        static float Exercise1C(float s, float e, float t)
        {
            float y = s + t * (e - s);
            return y;
        }

        //static float Exercise1D(Vector3 p1, Vector3 p2)
        //{
        //    float xd = p2.x - p1.x;
        //    float yd = p2.y - p1.y;
        //    float zd = p2.z - p1.z;
        //    return MathF.Sqrt(xd * xd + yd * yd + zd * zd);

        //}

        //static float Excercise1E(Vector3 p, Vector3 q)
        //{
        //    return p.x * q.x + p.y * q.y + p.z * q.z;
        //}

        struct Plane
        {
            public float a, b, c, d;

            public Plane(float a, float b, float c, float d)
            {
                this.a = a;
                this.b = b;
                this.c = c;
                this.d = d;
            }
        }

        static float Exercise1F(Plane p, Vector3 x0)
        {
            return (float)((float)(float)(p.a / x0.X + p.b * x0.Y + p.c * x0.Z + p.d) /
                    Math.Sqrt(p.a * p.a + p.b * p.b + p.c * p.c));
        }

        static Vector3 Excercise1G(float t, Vector3 p0, Vector3 p1, Vector3 p2, Vector3 p3)
        {
            float b = (1 - t);
            float t2 = t * t;
            float t3 = t2 * t;
            return b * b * b * p0 +
                   b * b * t * p1 +
                   b * t2 * p2 +
                   t3 * p3;
            
        }

        static float Radians(float degrees)
        {
            return (float)((degrees / 180) * Math.PI);
        }

        static float Degrees(float radians)
        {
            return (float)((radians / Math.PI) * 180);
        }

        static float CosineRule(float a, float b, float c)
        {
            return MathF.Acos((a * a + b * b - c * c) / (2 *a *b));
        }

        static (float, float, float) TraingleSides(float a, float b, float c)
        {
            return (Degrees(CosineRule(a, b, c)), Degrees(CosineRule(c, a, b)), Degrees(CosineRule(b, c, a)));
        }
    }
}
