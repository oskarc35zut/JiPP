using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    public class Complex<T> where T : struct
    {

        public T Real, Imaginary;
        public Complex()
        {
        }
        public Complex(T i, T j)
        {
            Real = i;
            Imaginary = j;
        }




        public static Complex<T> operator +(Complex<T> i, Complex<T> j)
        {
            return new Complex<T>((dynamic)i.Real+ (dynamic)j.Real, (dynamic)i.Imaginary + (dynamic)j.Imaginary);
        }

        public static Complex<T> operator -(Complex<T> i, Complex<T> j)
        {
            return new Complex<T>((dynamic)i.Real - (dynamic)j.Real, (dynamic)i.Imaginary - (dynamic)j.Imaginary);
        }

        public static Complex<T> operator *(Complex<T> i, Complex<T> j)
        {
            return new Complex<T>((dynamic)i.Real * (dynamic)j.Real, (dynamic)i.Imaginary * (dynamic)j.Imaginary);
        }

        public static Complex<T> operator /(Complex<T> i, Complex<T> j)
        {
            try
            {
                return new Complex<T>((dynamic)i.Real / (dynamic)j.Real, (dynamic)i.Imaginary / (dynamic)j.Imaginary);
            }
            catch (Exception)
            {

                throw;
            }
            
        }
    }
}
