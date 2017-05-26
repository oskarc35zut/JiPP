using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Complex
{
    public class Complex<T> where T : struct
    {

        public T real, imag;
        public Complex()
        {
        }
        public Complex(T i, T j)
        {
            real = i;
            imag = j;
        }




        public static Complex<T> operator +(Complex<T> i, Complex<T> j)
        {
            return new Complex<T>((dynamic)i.real+ (dynamic)j.real, (dynamic)i.imag + (dynamic)j.imag);
        }

        public static Complex<T> operator -(Complex<T> i, Complex<T> j)
        {
            return new Complex<T>((dynamic)i.real - (dynamic)j.real, (dynamic)i.imag - (dynamic)j.imag);
        }

        public static Complex<T> operator *(Complex<T> i, Complex<T> j)
        {
            return new Complex<T>((dynamic)i.real * (dynamic)j.real, (dynamic)i.imag * (dynamic)j.imag);
        }

        public static Complex<T> operator /(Complex<T> i, Complex<T> j)
        {
            try
            {
                return new Complex<T>((dynamic)i.real / (dynamic)j.real, (dynamic)i.imag / (dynamic)j.imag);
            }
            catch (Exception)
            {

                throw;
            }
            
        }
    }
}
