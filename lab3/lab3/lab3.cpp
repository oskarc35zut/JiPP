#include "stdafx.h"
#include <math.h>

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
	zespolona* z;
	int* dane_we;
	float d, pd, md;

public:
	Rownanie()
	{
		z = new zespolona;
		dane_we = new int[3];
		podaj_dane();

		formatuj_rownanie();
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
		delete[] dane_we;
	}

#pragma region Metody

	void podaj_dane()
	{
		printf("Podaj a: ");
		scanf("%d", &dane_we[0]);
		printf("Podaj b: ");
		scanf("%d", &dane_we[1]);
		printf("Podaj c: ");
		scanf("%d", &dane_we[2]);
	}

	void formatuj_rownanie() {
		//========================================================================================================================

		if (dane_we[0]>1 || dane_we[0]<0)
		{
			printf("%d*x*x", dane_we[0]);
		}
		else
		{
			if (dane_we[0] == 1)
			{
				printf("x*x");
			}
			else
			{
				if (dane_we[0] != 0)
				{
					printf("\n######\nformatuj_rownanie blad_a\n");
				}
			}
		}
		if (dane_we[1]>1)
		{
			printf("+%d*x", dane_we[1]);
		}
		else
		{
			if (dane_we[1]<0)
			{
				printf("%d*x", dane_we[1]);
			}
			else
			{
				if (dane_we[1] == 1)
				{
					printf("+x");
				}
				else
				{
					if (dane_we[1] != 0)
					{
						printf("\n######\nformatuj_rownanie blad_b\n");
					}
				}
			}
		}
		if (dane_we[2]>0)
		{
			printf("+%d", dane_we[2]);
		}
		else
		{
			if (dane_we[2]<0)
			{
				printf("%d", dane_we[2]);
			}
			else
			{
				if (dane_we[2] == 1)
				{
					printf("%d", dane_we[2]);
				}
				else
				{
					if (dane_we[1] != 0)
					{
						printf("\n######\nformatuj_rownanie blad_c\n");
					}
				}
			}
		}
		printf(" = 0\n");
	}

	void oblicz_d() {
		d = (float)((dane_we[1] * dane_we[1]) - ((4 * dane_we[0])*dane_we[2]));
	}

	float mnsqrt()
	{
		pd = 0;

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
			pd = sqrtf(d);

			z->x1r = ((-(float)dane_we[1] + pd) / (2 * (float)dane_we[0]));
			z->x2r = ((-(float)dane_we[1] - pd) / (2 * (float)dane_we[0]));
		}
		else if (d == 0)
		{
			z->x1r = ((-(float)dane_we[1]) / (2 * (float)dane_we[0]));
		}
		else
		{
			pd = sqrtf(fabsf(d));

			z->x1r = ((-(float)dane_we[1]) / (2 * (float)dane_we[0]));
			z->x2r = z->x1r;

			z->u.x1u = -pd / 2 / (float)dane_we[0];
			z->u.x2u = -z->u.x1u;
		}

	}

	void dodaj() {
		if (d>0)
		{
			z->sr = z->x1r + z->x2r;
		}
		else if (d<0)
		{
			z->sr = z->x1r + z->x2r;
			z->u.su = z->u.x1u + z->u.x2u;
		}
	}

	void odejmij() {
		if (d >= 0)
		{
			z->rr = z->x1r - z->x2r;
		}
		else if (d<0)
		{
			z->rr = z->x1r - z->x2r;
			z->u.ru = z->u.x1u - z->u.x2u;
		}
	}

	void pomnoz() {
		if (d >= 0)
		{
			z->ilr = z->x1r * z->x2r;
		}
		else if (d<0)
		{
			z->ilr = z->x1r * z->x2r - z->u.x1u * z->u.x2u;
			z->u.ilu = z->x1r * z->u.x2u + z->x1r * z->u.x2u;
		}
	}

	void podziel() {
		if (d >= 0 && z->x2r != 0) {
			z->irr = z->x1r / z->x2r;
		}
		else if (d < 0) {
			z->irr = (z->x1r * z->x2r - z->u.x1u * z->u.x2u) / (z->x2r * z->x2r + z->u.x2u * z->u.x2u);
			z->u.iru = (z->x2r * z->u.x1u - z->x1r * z->u.x2u) / (z->x2r * z->x2r + z->u.x2u * z->u.x2u);
		}
	}

	void formatuj_zesp() {

		/*if (z->u.x1u >= 0) printf("Z = %f+%f*i\n", z->x1r, z->u.x1u);
		else printf("Z = %f%f*i\n", z->x1r, z->u.x1u);

		if (z->u.x2u >= 0) printf("Z = %f+%f*i\n", z->x2r, z->u.x2u);
		else printf("z = %f%f*i\n", z->x2r, z->u.x2u);*/

		printf("\nSuma:\n	Z= ");
		if (z->u.su >= 0) printf("%f+%f*i\n", z->sr, z->u.su);
		else printf("%f%f*i\n", z->sr, z->u.su);

		printf("\nRoznica:\n	Z= ");
		if (z->u.ru >= 0) printf("%f+%f*i\n", z->rr, z->u.ru);
		else printf("%f%f*i\n", z->rr, z->u.ru);

		printf("\nMnozenie:\n	Z= ");
		if (z->u.ilu >= 0) printf("%f+%f*i\n", z->ilr, z->u.ilu);
		else printf("%f%f*i\n", z->ilr, z->u.ilu);

		printf("\nDzielenie:\n	Z= ");
		if (z->u.iru >= 0) printf("%f+%f*i\n", z->irr, z->u.iru);
		else printf("%f%f*i\n", z->irr, z->u.iru);

	}

	void wyswietl_wynik()
	{
		if (dane_we[0] == 0)
		{
			if (dane_we[1] != 0)
			{
				printf("\nx1v = %f\n", z->x1r);
			}
			else if ((dane_we[1] == 0) && (dane_we[2] != 0))
			{
				printf("rownanie jest sprzeczne!!!\n");
			}
			else if ((dane_we[1] == 0) && (dane_we[2] == 0))
			{
				printf("rownanie jest tozsamosciowe\n");
			}
		}
		else if (d > 0)
		{
			printf("\nx1v = %f\n", z->x1r);
			printf("x2v = %f\n", z->x2r);
			printf("sr = %f\n", z->sr);
			printf("rr = %f\n", z->rr);
			printf("ilr = %f\n", z->ilr);
			printf("irr = %f\n", z->irr);
		}
		else if (d < 0)
		{
			printf("\nx1v = %f\n", z->x1r);
			printf("x2v = %f\n", z->x2r);
			printf("x1u = %f\n", z->u.x1u);
			printf("x2u = %f\n", z->u.x2u);
			printf("sr = %f\n", z->sr);
			printf("su = %f\n", z->u.su);
			printf("rr = %f\n", z->rr);
			printf("ru = %f\n", z->u.ru);
			printf("ilr = %f\n", z->ilr);
			printf("ilu = %f\n", z->u.ilu);
			printf("irr = %f\n", z->irr);
			printf("iru = %f\n", z->u.iru);

			formatuj_zesp();

			modul();
			printf("\nmod = %f\n", md);
		}
		else if (d == 0)
		{
			printf("x1v = %f\n", z->x1r);
		}
			


		mnsqrt();
		oblicz_d();
		d = sqrt(fabs(d));
		printf("\nRoznica w SQRT =%f\n", fabs(pd - d));

	}

	void modul()
	{
		md = sqrtf((z->x1r*z->x1r) + ((z->u).x1u*(z->u).x1u));
	}
#pragma endregion //Metody

};

int main()
{
	Rownanie* test = new Rownanie();
	return 0;
}