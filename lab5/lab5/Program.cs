using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using static System.Console;
using static System.Math;


namespace lab5
{
    interface IRownanie
    {
        

        void podaj_dane();
        void wyswietl_wynik();
        void formatuj_rownanie();
    }

    abstract class ARownanie : IRownanie
    {
        protected float d, pd, md;

        protected List<int> dane_we;
        protected List<Complex> zespolona;

        public abstract void podaj_dane();
        public abstract void wyswietl_wynik();
        public abstract void formatuj_rownanie();


        protected virtual float mnsqrt()
        {
            return (float)Sqrt(d);
        }
    }


    class Rownanie : ARownanie, IRownanie
    {
        public Rownanie()
        {
            zespolona = new List<Complex>();
            dane_we = new List<int>();

            for (int i = 0; i < 3; i++)
            {
                dane_we.Add(new int());
            }

            for (int i = 0; i < 6; i++)
            {
                zespolona.Add(new Complex());
            }


            podaj_dane();
            oblicz_d();
            oblicz_pierwiastki();
            dodaj();
            odejmij();
            pomnoz();
            podziel();
            modul();
            wyswietl_wynik();
        }

        public override void podaj_dane()
        {
            char[] tmp = new char[] { 'a', 'b', 'c' };
            for (int i = 0; i < tmp.Length; i++)
            {
                WriteLine("Podaj {0}", tmp[i]);
                try
                {
                    dane_we[i] = Convert.ToInt32(ReadLine());
                }
                catch (Exception e)
                {
                    i--;
                    WriteLine("Blad! {0}", e.Message);
                }

            }
            tmp = null;
        }

        public override void formatuj_rownanie()
        {

            if (dane_we[0] > 1 || dane_we[0] < 0)
            {
                Write("{0}x^2", dane_we[0]);
            }
            else
            {
                if (dane_we[0] == 1)
                {
                    Write("x^2");
                }
                else
                {
                    if (dane_we[0] != 0)
                    {
                        Write("\n######\nformatuj_rownanie blad_a\n");
                    }
                }
            }
            if (dane_we[1] > 1)
            {
                Write("+{0}*x", dane_we[1]);
            }
            else
            {
                if (dane_we[1] < 0)
                {
                    Write("{0}*x", dane_we[1]);
                }
                else
                {
                    if (dane_we[1] == 1)
                    {
                        Write("+x");
                    }
                    else
                    {
                        if (dane_we[1] != 0)
                        {
                            Write("\n######\nformatuj_rownanie blad_b\n");
                        }
                    }
                }
            }
            if (dane_we[2] > 0)
            {
                Write("+{0}", dane_we[2]);
            }
            else
            {
                if (dane_we[2] < 0)
                {
                    Write("{0}", dane_we[2]);
                }
                else
                {
                    if (dane_we[2] == 1)
                    {
                        Write("{0}", dane_we[2]);
                    }
                    else
                    {
                        if (dane_we[2] != 0)
                        {
                            Write("\n######\nformatuj_rownanie blad_c\n");
                        }
                    }
                }
            }
            Write(" = 0\n");
        }

        protected void oblicz_d()
        {
            d = (float)(Pow(dane_we[1], 2) - ((4 * dane_we[0]) * dane_we[2]));

        }

        protected new float mnsqrt()
        {
            pd = 0;

            d = Abs(d);

            if (d > 0)
            {
                //obliczanie pierwiastka z d
                pd = d / 2;
                if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1))
                {
                    pd = (d / pd + pd) / 2;
                    if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1))
                    {
                        pd = (d / pd + pd) / 2;
                        if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1))
                        {
                            pd = (d / pd + pd) / 2;
                            if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1))
                            {
                                pd = (d / pd + pd) / 2;
                                if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1))
                                {
                                    pd = (d / pd + pd) / 2;
                                    if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1))
                                    {
                                        pd = (d / pd + pd) / 2;
                                        if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1))
                                        {
                                            pd = (d / pd + pd) / 2;// dokladnosc na poziomie 0.2
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return pd;
        }

       protected void oblicz_pierwiastki()
        {
            oblicz_d();
            if (d > 0)
            {
                zespolona[0] = new Complex((-(float)dane_we[1] + pd) / (2 * (float)dane_we[0]), 0);
                
                zespolona[1] = new Complex((-(float)dane_we[1] - pd) / (2 * (float)dane_we[0]), 0);
            }
            else if (d == 0)
            {
                zespolona[0] = new Complex((-(float)dane_we[1] + pd) / (2 * (float)dane_we[0]), 0);
                zespolona[1] = new Complex((-(float)dane_we[1] + pd) / (2 * (float)dane_we[0]), 0);
            }
            else
            {
                pd = (float)Sqrt(Abs(d));

                zespolona[0] = new Complex((-(float)dane_we[1]) / (2 * (float)dane_we[0]), (-pd / 2 / (float)dane_we[0]));
                zespolona[1] = new Complex((zespolona[0].Real), (-(zespolona[0].Imaginary)));

            }
        }

        private void dodaj()
        {

            zespolona[2] = zespolona[0] + zespolona[1];

        }

        private void odejmij()
        {

            zespolona[3] = zespolona[0] - zespolona[1];

        }

        private void pomnoz()
        {

            zespolona[4] = zespolona[0] * zespolona[1];

        }

        private void podziel()
        {

            zespolona[5] = zespolona[0] / zespolona[1];

        }

        public void formatuj_zesp()
        {
            for (int i = 0; i < zespolona.Count; i++)
            {
               if (zespolona[i].Imaginary >= i) Write("Z = {0}+{1}*i\n", zespolona[i].Real, zespolona[i].Imaginary);
               else Write("Z = {0}{1}*i\n", zespolona[i].Real, zespolona[i].Imaginary);
            }

            for (int i = zespolona.Count - 1; zespolona.Count > 0; i--)
            {
                zespolona.Remove(zespolona[i]);
            }
        }

        public override void wyswietl_wynik()
        { 
            Write("\n\n");
            formatuj_rownanie();

            if (dane_we[0] == 0)
            {
                if (dane_we[1] != 0)
                {
                    Write("\nx1v = {0}\n", zespolona[0].Real);
                }
                else if ((dane_we[1] == 0) && (dane_we[2] != 0))
                {
                    Write("rownanie jest sprzeczne!!!\n");
                }
                else if ((dane_we[1] == 0) && (dane_we[2] == 0))
                {
                    Write("rownanie jest tozsamosciowe\n");
                }
            }
            else if (d > 0)
            {
                Write("\nx1v = {0}\n", zespolona[0].Real);
                Write("x2v = {0}\n", zespolona[1].Real);
                Write("sr = {0}\n", zespolona[2].Real);
                Write("rr = {0}\n", zespolona[3].Real);
                Write("ilr = {0}\n", zespolona[4].Real);
                Write("irr = {0}\n", zespolona[5].Real);
            }
            else if (d < 0)
            {
                Write("\nx1v = {0}\n", zespolona[0].Real);
                Write("x2v = {0}\n", zespolona[1].Real);
                Write("x1u = {0}\n", zespolona[0].Imaginary);
                Write("x2u = {0}\n", zespolona[1].Imaginary);
                Write("sr = {0}\n", zespolona[2].Real);
                Write("su = {0}\n", zespolona[2].Imaginary);
                Write("rr = {0}\n", zespolona[3].Real);
                Write("ru = {0}\n", zespolona[3].Imaginary);
                Write("ilr = {0}\n", zespolona[4].Real);
                Write("ilu = {0}\n", zespolona[4].Imaginary);
                Write("irr = {0}\n", zespolona[5].Real);
                Write("iru = {0}\n", zespolona[5].Imaginary);

                modul();
                formatuj_zesp();

                
                Write("\nmod = {0}\n", md);
            }
            else if (d == 0)
            {
                Write("x1v = {0}\n", zespolona[0].Real);
            }





            base.mnsqrt();
            this.mnsqrt();

            if (pd > Sqrt(Abs(d)))
            {
                Write("\nDokladnosc pierwiastka wynosi: {0}", pd - Sqrt(Abs(d)));
            }
            else
            {
                Write("\nDokladnosc pierwiastka wynosi: {0}", Sqrt(Abs(d)) - pd);
            }
        }

        void modul()
        {
            int j = 0;
            md = (float)Sqrt(Pow(zespolona[j].Real, 2) + Pow(zespolona[j].Imaginary, 2));
        }
    }





    class Program
    {
        static void Main(string[] args)
        {
            Rownanie test = new Rownanie();

            WriteLine("\n\n\n# KONIEC #");
            Console.ReadKey();
        }
    }
}
