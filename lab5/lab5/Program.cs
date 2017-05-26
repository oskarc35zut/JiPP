using System;
using System.Collections.Generic;
using System.Linq;
using Complex;
using System.Text;
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
    class Rownanie : IRownanie
    {
        List<int> dane_we;
        List<Complex<float>> zespolona;

        float d, pd, md;

        public Rownanie()
        {
            zespolona = new List<Complex<float>>();
            dane_we = new List<int>();

            for (int i = 0; i < 3; i++)
            {
                dane_we.Add(new int());
            }

            for (int i = 0; i < 6; i++)
            {
                zespolona.Add(new Complex<float>());
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

        public void podaj_dane()
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

        public void formatuj_rownanie()
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

        void oblicz_d()
        {
            d = (float)(Pow(dane_we[1], 2) - ((4 * dane_we[0]) * dane_we[2]));

        }

        float mnsqrt()
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

        void oblicz_pierwiastki()
        {

            oblicz_d();
            if (d > 0)
            {
                zespolona[0].real = (((-(float)dane_we[1] + pd) / (2 * (float)dane_we[0])));
                zespolona[0].imag = 0;

                zespolona[1].real = (((-(float)dane_we[1] - pd) / (2 * (float)dane_we[0])));
                zespolona[1].imag = 0;
            }
            else if (d == 0)
            {
                zespolona[0].real = (((-(float)dane_we[1] + pd) / (2 * (float)dane_we[0])));
                zespolona[0].imag = 0;
            }
            else
            {
                pd = (float)Sqrt(Abs(d));

                zespolona[0].real = ((-(float)dane_we[1]) / (2 * (float)dane_we[0]));
                zespolona[1].real = (zespolona[0].real);

                zespolona[0].imag = (-pd / 2 / (float)dane_we[0]);
                zespolona[1].imag = (-(zespolona[0].imag));
            }

        }

        void dodaj()
        {

            zespolona[2] = zespolona[0] + zespolona[1];

        }

        void odejmij()
        {

            zespolona[3] = zespolona[0] - zespolona[1];

        }

        void pomnoz()
        {

            zespolona[4] = zespolona[0] * zespolona[1];

        }

        void podziel()
        {

            zespolona[5] = zespolona[0] / zespolona[1];

        }

        void formatuj_zesp()
        {
            for (int i = 0; i < 6; i++)
            {
                if (zespolona[i].imag >= i) Write("Z = {0}+{0}*i\n", zespolona[i].real, zespolona[i].imag);
                else Write("Z = {0}{0}*i\n", zespolona[i].real, zespolona[i].imag);
            }
        }

        public void wyswietl_wynik()
        {
            Write("\n\n");
            formatuj_rownanie();

            if (dane_we[0] == 0)
            {
                if (dane_we[1] != 0)
                {
                    Write("\nx1v = {0}\n", zespolona[0].real);
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
                Write("\nx1v = {0}\n", zespolona[0].real);
                Write("x2v = {0}\n", zespolona[1].real);
                Write("sr = {0}\n", zespolona[2].real);
                Write("rr = {0}\n", zespolona[3].real);
                Write("ilr = {0}\n", zespolona[4].real);
                Write("irr = {0}\n", zespolona[5].real);
            }
            else if (d < 0)
            {
                Write("\nx1v = {0}\n", zespolona[0].real);
                Write("x2v = {0}\n", zespolona[1].real);
                Write("x1u = {0}\n", zespolona[0].imag);
                Write("x2u = {0}\n", zespolona[1].imag);
                Write("sr = {0}\n", zespolona[2].real);
                Write("su = {0}\n", zespolona[2].imag);
                Write("rr = {0}\n", zespolona[3].real);
                Write("ru = {0}\n", zespolona[3].imag);
                Write("ilr = {0}\n", zespolona[4].real);
                Write("ilu = {0}\n", zespolona[4].imag);
                Write("irr = {0}\n", zespolona[5].real);
                Write("iru = {0}\n", zespolona[5].imag);

                formatuj_zesp();

                modul();
                Write("\nmod = {0}\n", md);
            }
            else if (d == 0)
            {
                Write("x1v = {0}\n", zespolona[0].real);
            }

            mnsqrt();

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
            md = (float)Sqrt(Pow(zespolona[j].real, 2) + Pow(zespolona[j].imag, 2));
        }
    }





    class Program
    {
        static void Main(string[] args)
        {
            Rownanie test = new Rownanie();

            WriteLine("\n# KONIEC #");
            Console.ReadKey();
        }
    }
}
