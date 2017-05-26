#include "stdafx.h"
#include <math.h>
#include <complex>
#include <vector>
#include <iomanip>
#include "stdlib.h"
#include <iostream>


using namespace std;

struct urojona
{
	float x1u, x2u, su, ru, ilu, iru;
};

struct zespolona
{
	float x1r, x2r, sr, rr, ilr, irr;
	struct urojona u;
};

class Rownanie
{
private:

	vector<int> *dane_we;
	vector<complex<float>> *vzespolona;
	complex<float> *tmp;

	zespolona* z;
	int* Odane_old;
	float d, pd, md;

public:
	Rownanie()
	{
		z = new zespolona;
		Odane_old = new int[3];



		dane_we = new vector<int>;
		dane_we->push_back(NULL); //a
		dane_we->push_back(NULL); //b
		dane_we->push_back(NULL); //c

		vzespolona = new vector<complex<float>>;
		vzespolona->push_back(NULL); //x1
		vzespolona->push_back(NULL); //x2
		vzespolona->push_back(NULL); //suma
		vzespolona->push_back(NULL); //roznica
		vzespolona->push_back(NULL); //iloraz
		vzespolona->push_back(NULL); //iloczyn

		tmp = new complex<float>;

#pragma region test
		////a = ;

		////a->real(19);
		////a->imag(2);

		////Vzesp->push_back((complex<float>(5, 7)));

		////*zesp = Vzesp->at(0);

		////Vzesp->push_back();
#pragma endregion



		podaj_dane();
		oblicz_pierwiastki();
		oblicz_d();
		dodaj();
		odejmij();
		pomnoz();
		podziel();
		wyswietl_wynik();
	}
	~Rownanie()
	{
		delete(z);
		delete[] Odane_old;

		delete dane_we;
		delete vzespolona;
	}

private:

#pragma region Metody

	void podaj_dane()
	{


		printf("Podaj a b c\n");
		scanf_s("%d %d %d", &(dane_we->at(0)), &(dane_we->at(1)), &(dane_we->at(2)));
	}

	void formatuj_rownanie() {
		//========================================================================================================================

		if (dane_we->at(0)>1 || dane_we->at(0)<0)
		{
			printf("%d*x*x", dane_we->at(0));
		}
		else
		{
			if (dane_we->at(0) == 1)
			{
				printf("x*x");
			}
			else
			{
				if (dane_we->at(0) != 0)
				{
					printf("\n######\nformatuj_rownanie blad_a\n");
				}
			}
		}
		if (dane_we->at(1)>1)
		{
			printf("+%d*x", dane_we->at(1));
		}
		else
		{
			if (dane_we->at(1)<0)
			{
				printf("%d*x", dane_we->at(1));
			}
			else
			{
				if (dane_we->at(1) == 1)
				{
					printf("+x");
				}
				else
				{
					if (dane_we->at(1) != 0)
					{
						printf("\n######\nformatuj_rownanie blad_b\n");
					}
				}
			}
		}
		if (dane_we->at(2)>0)
		{
			printf("+%d", dane_we->at(2));
		}
		else
		{
			if (dane_we->at(2)<0)
			{
				printf("%d", dane_we->at(2));
			}
			else
			{
				if (dane_we->at(2) == 1)
				{
					printf("%d", dane_we->at(2));
				}
				else
				{
					if (dane_we->at(1) != 0)
					{
						printf("\n######\nformatuj_rownanie blad_c\n");
					}
				}
			}
		}
		printf(" = 0\n");
	}

	void oblicz_d() {
		d = (float)((dane_we->at(1) * dane_we->at(1)) - ((4 * dane_we->at(0))*dane_we->at(2)));
	}

	float mnsqrt()
	{
		pd = 0;

		d = fabsf(d);

		if (d > 0)
		{
			//obliczanie pierwiastka z d
			pd = d / 2;
			if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1)) {
				pd = (d / pd + pd) / 2;
				if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1)) {
					pd = (d / pd + pd) / 2;
					if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1)) {
						pd = (d / pd + pd) / 2;
						if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1)) {
							pd = (d / pd + pd) / 2;
							if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1)) {
								pd = (d / pd + pd) / 2;
								if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1)) {
									pd = (d / pd + pd) / 2;
									if ((d / pd - pd > 0.1) || (d / pd - pd < -0.1)) {
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

	void oblicz_pierwiastki() {

		oblicz_d();
		if (d>0)
		{
			(vzespolona->at(0)).real(((-(float)dane_we->at(1) + pd) / (2 * (float)dane_we->at(0))));
			(vzespolona->at(0)).imag(0);

			(vzespolona->at(1)).real(((-(float)dane_we->at(1) - pd) / (2 * (float)dane_we->at(0))));
			(vzespolona->at(1)).imag(0);
		}
		else if (d == 0)
		{
			(vzespolona->at(0)).real(((-(float)dane_we->at(1) + pd) / (2 * (float)dane_we->at(0))));
			(vzespolona->at(0)).imag(0);
		}
		else
		{
			pd = sqrtf(fabsf(d));

			(vzespolona->at(0)).real((-(float)dane_we->at(1)) / (2 * (float)dane_we->at(0)));
			(vzespolona->at(1)).real((vzespolona->at(0)).real());
			
			(vzespolona->at(0)).imag(-pd / 2 / (float)dane_we->at(0));
			(vzespolona->at(1)).imag(-((vzespolona->at(0)).imag()));

			//z->x1r = ((-(float)dane_we->at(1)) / (2 * (float)dane_we->at(0)));
			//z->x2r = z->x1r;

			//z->u.x1u = -pd / 2 / (float)dane_we->at(0);
			//z->u.x2u = -z->u.x1u;
		}

	}

	void dodaj() {

		vzespolona->at(2) = vzespolona->at(0) + vzespolona->at(1);
		

		//(vzespolona->at(0)).real((-(float)dane_we->at(1)) / (2 * (float)dane_we->at(0)));
		//(vzespolona->at(1)).real((vzespolona->at(0)).real());

		//(vzespolona->at(0)).imag(-pd / 2 / (float)dane_we->at(0));
		//(vzespolona->at(1)).imag(-((vzespolona->at(0)).imag()));

		

		//if (d>0)
		//{


		//	(vzespolona->at(2)).real(((vzespolona->at(0)).real() + (vzespolona->at(1)).real()));
		//	//z->sr = z->x1r + z->x2r;
		//}
		//else if (d<0)
		//{
		//	(vzespolona->at(2)).real(((vzespolona->at(0)).real() + (vzespolona->at(1)).real()));
		//	(vzespolona->at(2)).imag(((vzespolona->at(0)).imag() + (vzespolona->at(1)).imag()));

		//	//z->sr = z->x1r + z->x2r;
		//	//z->u.su = z->u.x1u + z->u.x2u;
		//}
	}

	void odejmij() {

		vzespolona->at(3) = vzespolona->at(0) - vzespolona->at(1);

		//if (d >= 0)
		//{
		//	(vzespolona->at(3)).real(((vzespolona->at(0)).real() - (vzespolona->at(1)).real()));
		//	//z->rr = z->x1r - z->x2r;
		//}
		//else if (d<0)
		//{
		//	(vzespolona->at(3)).real(((vzespolona->at(0)).real() - (vzespolona->at(1)).real()));
		//	(vzespolona->at(3)).imag(((vzespolona->at(0)).imag() - (vzespolona->at(1)).imag()));
		//	//z->rr = z->x1r - z->x2r;
		//	//z->u.ru = z->u.x1u - z->u.x2u;
		//}
	}

	void pomnoz() {

		vzespolona->at(4) = vzespolona->at(0) * vzespolona->at(1);

		//if (d >= 0)
		//{
		//	(vzespolona->at(4)).real(((vzespolona->at(0)).real() * (vzespolona->at(1)).real()));
		//	//z->ilr = z->x1r * z->x2r;
		//}
		//else if (d<0)
		//{
		//	(vzespolona->at(4)).real(((vzespolona->at(0)).real() * (vzespolona->at(1)).real()) - ((vzespolona->at(0)).imag() * (vzespolona->at(1)).imag()));
		//	(vzespolona->at(4)).real(((vzespolona->at(0)).real() * (vzespolona->at(1)).imag()) + ((vzespolona->at(0)).real() * (vzespolona->at(1)).imag()));

		//	//z->ilr = z->x1r * z->x2r - z->u.x1u * z->u.x2u;
		//	//z->u.ilu = z->x1r * z->u.x2u + z->x1r * z->u.x2u;
		//}
	}

	void podziel() {

		vzespolona->at(5) = vzespolona->at(0) / vzespolona->at(1);

		//if (d >= 0 && z->x2r != 0) {
		//	(vzespolona->at(5)).real(((vzespolona->at(0)).real() / (vzespolona->at(1)).real()));
		//	//z->irr = z->x1r / z->x2r;
		//}
		//else if (d < 0) {

		//	(vzespolona->at(5)).real(((vzespolona->at(0)).real() * (vzespolona->at(1)).real()) - ((vzespolona->at(0)).imag() * (vzespolona->at(1)).imag()) / ( (vzespolona->at(1)).real() * (vzespolona->at(1)).real()+ (vzespolona->at(1)).imag() * (vzespolona->at(1)).imag() ));
		//	(vzespolona->at(5)).imag(((vzespolona->at(0)).real() * (vzespolona->at(1)).imag()) + ((vzespolona->at(0)).real() * (vzespolona->at(1)).imag()));


		//	z->irr = (z->x1r * z->x2r - z->u.x1u * z->u.x2u) / (z->x2r * z->x2r + z->u.x2u * z->u.x2u);
		//	z->u.iru = (z->x2r * z->u.x1u - z->x1r * z->u.x2u) / (z->x2r * z->x2r + z->u.x2u * z->u.x2u);
		//}
	}

	void formatuj_zesp() {

		vzespolona->at(0).real();
		vzespolona->at(0).real();

		//int a = vzespolona->size();

		//for (int i = a; i >= 0; i--)
		//{
		//	*tmp = vzespolona->at(i);
		//	vzespolona->pop_back();

		//	if (tmp->imag() >= i) printf("Z = %f+%f*i\n", tmp->real(), tmp->imag());
		//	else printf("Z = %f%f*i\n", tmp->real(), tmp->imag());


		//}


		for (int i = 0; i < 6; i++)
		{
			if (vzespolona->at(i).imag() >= i) printf("Z = %f+%f*i\n", vzespolona->at(i).real(), vzespolona->at(i).imag());
			else printf("Z = %f%f*i\n", vzespolona->at(i).real(), vzespolona->at(i).imag());
		}

		//printf("\nX1:\n	Z= ");
		//if (vzespolona->at(0).imag() >= 0) printf("Z = %f+%f*i\n", vzespolona->at(0).real(), vzespolona->at(0).imag());
		//else printf("Z = %f%f*i\n", vzespolona->at(0).real(), vzespolona->at(0).imag());

		//printf("\nX2:\n	Z= ");
		//if (z->u.x2u >= 0) printf("Z = %f+%f*i\n", z->x2r, z->u.x2u);
		//else printf("z = %f%f*i\n", z->x2r, z->u.x2u);

		//printf("\nSuma:\n	Z= ");
		//if (z->u.su >= 0) printf("%f+%f*i\n", z->sr, z->u.su);
		//else printf("%f%f*i\n", z->sr, z->u.su);

		//printf("\nRoznica:\n	Z= ");
		//if (z->u.ru >= 0) printf("%f+%f*i\n", z->rr, z->u.ru);
		//else printf("%f%f*i\n", z->rr, z->u.ru);

		//printf("\nMnozenie:\n	Z= ");
		//if (z->u.ilu >= 0) printf("%f+%f*i\n", z->ilr, z->u.ilu);
		//else printf("%f%f*i\n", z->ilr, z->u.ilu);

		//printf("\nDzielenie:\n	Z= ");
		//if (z->u.iru >= 0) printf("%f+%f*i\n", z->irr, z->u.iru);
		//else printf("%f%f*i\n", z->irr, z->u.iru);

	}

	void wyswietl_wynik()
	{
		printf("\n\n");
		formatuj_rownanie();

		if (dane_we->at(0) == 0)
		{
			if (dane_we->at(1) != 0)
			{
				printf("\nx1v = %f\n", z->x1r);
			}
			else if ((dane_we->at(1) == 0) && (dane_we->at(2) != 0))
			{
				printf("rownanie jest sprzeczne!!!\n");
			}
			else if ((dane_we->at(1) == 0) && (dane_we->at(2) == 0))
			{
				printf("rownanie jest tozsamosciowe\n");
			}
		}
		else if (d > 0)
		{
			printf("\nx1v = %f\n", vzespolona->at(0).real());
			printf("x2v = %f\n", vzespolona->at(1).real());
			printf("sr = %f\n", vzespolona->at(2).real());
			printf("rr = %f\n", vzespolona->at(3).real());
			printf("ilr = %f\n", vzespolona->at(4).real());
			printf("irr = %f\n", vzespolona->at(5).real());
		}
		else if (d < 0)
		{
			printf("\nx1v = %f\n", vzespolona->at(0).real());
			printf("x2v = %f\n", vzespolona->at(1).real());
			printf("x1u = %f\n", vzespolona->at(0).imag());
			printf("x2u = %f\n", vzespolona->at(1).imag());
			printf("sr = %f\n", vzespolona->at(2).real());
			printf("su = %f\n", vzespolona->at(2).imag());
			printf("rr = %f\n", vzespolona->at(3).real());
			printf("ru = %f\n", vzespolona->at(3).imag());
			printf("ilr = %f\n", vzespolona->at(4).real());
			printf("ilu = %f\n", vzespolona->at(4).imag());
			printf("irr = %f\n", vzespolona->at(5).real());
			printf("iru = %f\n", vzespolona->at(5).imag());

			formatuj_zesp();

			modul();
			printf("\nmod = %f\n", md);
		}
		else if (d == 0)
		{
			printf("x1v = %f\n", z->x1r);
		}

		mnsqrt();

		if (pd > sqrtf(fabsf(d)))
		{
			printf("\nDokladnosc pierwiastka wynosi: %f", pd - sqrtf(fabsf(d)));
		}
		else
		{
			printf("\nDokladnosc pierwiastka wynosi: %f", sqrtf(fabsf(d)) - pd);
		}
	}

	void modul()
	{
		md = abs(vzespolona->at(0));
	}
#pragma endregion //Metody

};

int main()
{
	Rownanie* test = new Rownanie();
	delete test;
	return 0;
}