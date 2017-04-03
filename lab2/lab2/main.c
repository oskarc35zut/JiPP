#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma region Deklaracje

void podaj_dane(int* a, int* b, int* c);
void formatuj_rownanie(int a, int b, int c);
float oblicz_d(int a, int b, int c);
void oblicz_pierwiastki(int a, int b, int c, float* x1v, float* x2v, float* x1u, float* x2u);
void dodaj(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *sr, float *su);
void odejmij(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *rr, float *ru);
void pomnoz(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *ilr, float *ilu);
void podziel(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *ilr, float *ilu);
void formatuj_zesp(float x1r, float x1u);
void wyswietl_wynik(int a, int b, int c, float d, float x1r, float x2r, float x1u, float x2u, float sr, float su, float rr, float ru, float ilr, float ilu, float irr, float iru);

#pragma endregion



int main() {

	int a, b, c;
	float d, pd, x1r, x2r, x1u, x2u, sr, su, rr, ru, ilr, ilu, irr, iru;

	podaj_dane(&a, &b, &c);

	formatuj_rownanie(a, b, c);

	d = oblicz_d(a, b, c);

	oblicz_pierwiastki(a, b, c, &x1r, &x2r, &x1u, &x2u);
	dodaj(d, &x1r, &x2r, &x1u, &x2u, &sr, &su);
	odejmij(d, &x1r, &x2r, &x1u, &x2u, &rr, &ru);
	pomnoz(d, &x1r, &x2r, &x1u, &x2u, &ilr, &ilu);
	podziel(d, &x1r, &x2r, &x1u, &x2u, &irr, &iru);

	wyswietl_wynik(a, b, c, d, x1r, x2r, x1u, x2u, sr, su, rr, ru, ilr, ilu, irr, iru);

	scanf_s("%d", &c);
	return 0;
}


void podaj_dane(int* a, int* b, int* c) {
	printf("Podaj a b c\n");
	scanf_s("%d %d %d", &*a, &*b, &*c);
}

void formatuj_rownanie(int a, int b, int c) {
	//========================================================================================================================
	if (a>1 || a<0)
	{
		printf("%d*x*x", a);
	}
	else
	{
		if (a == 1)
		{
			printf("x*x");
		}
		else
		{
			if (a != 0)
			{
				printf("\n######\nformatuj_rownanie blad_a\n");
			}
		}
	}
	if (b>1)
	{
		printf("+%d*x", b);
	}
	else
	{
		if (b<0)
		{
			printf("%d*x", b);
		}
		else
		{
			if (b == 1)
			{
				printf("+x");
			}
			else
			{
				if (b != 0)
				{
					printf("\n######\nformatuj_rownanie blad_b\n");
				}
			}
		}
	}
	if (c>0)
	{
		printf("+%d", c);
	}
	else
	{
		if (c<0)
		{
			printf("%d", c);
		}
		else
		{
			if (c == 1)
			{
				printf("%d", c);
			}
			else
			{
				if (b != 0)
				{
					printf("\n######\nformatuj_rownanie blad_c\n");
				}
			}
		}
	}
	printf(" = 0\n");
}

float oblicz_d(int a, int b, int c) {
	return (b*b) - ((4 * a)*c);
}

void oblicz_pierwiastki(int a, int b, int c, float* x1v, float *x2v, float *x1u, float *x2u) {
	
	float d = oblicz_d(a, b, c);

	*x1v = ((-b - d) / (2 * a));
	*x2v = (-b + d) / (2 * a);

	*x1u = (-1)*(sqrt(d)) / (2 * a);
	*x2u = (-1)*(*x1u);

}

void dodaj(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *sr, float *su) {
	if (d>0)
	{
		*sr = *x1r + *x2r;
	}
	else if (d<0)
	{
		*sr = *x1r + *x2r;
		*su = *x1u + *x2u;
	}
}

void odejmij(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *rr, float *ru) {
	if (d>0)
	{
		*rr = *x1r - *x2r;
	}
	else if (d<0)
	{
		*rr = *x1r - *x2r;
		*ru = *x1u - *x2u;
	}
}

void pomnoz(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *ilr, float *ilu) {
	if (d>0)
	{
		*ilr = *x1r * *x2r;
	}
	else if (d<0)
	{
		*ilr = *x1r * *x2r - *x1u * *x2u;
		*ilu = *x1r * *x2u + *x1u * *x2r;
	}
}

void podziel(float d, float *x1r, float *x2r, float *x1u, float *x2u, float *irr, float *iru) {
	if (d>0)
	{
		*irr = *x1r / *x2r;
	}
	else if (d<0)
	{
		*irr = (*x1r * *x2r + *x1u * *x2u) / (*x2r * *x2r) + (*x2u * *x2u);
		if (*x2r != 0)
		{	
			*iru = (*x1u * *x2r - *x1r * *x2u) / (*x2r * *x2r) + (*x2u * *x2u);
		}
		else 
		{
			printf("\n ## x2r = 0 !!! ##");
		}
	}
}

void formatuj_zesp(float x1r, float x1u) {
	if (x1u<0)
	{
		printf("\n z1 = %f %f*i", x1r, x1u);
		printf("\n z2 = %f +%f*i", x1r, x1u);
	}
	else
	{
		printf("\n z1 = %f +%f*i", x1r, x1u);
		printf("\n z2 = %f %f*i", x1r, x1u);
	}
}

void wyswietl_wynik(int a, int b, int c, float d, float x1r, float x2r, float x1u, float x2u, float sr, float su, float rr, float ru, float ilr, float ilu, float irr, float iru) {
	printf("\n a= %d  b= %d  c= %d\n", a, b, c);

	formatuj_rownanie( a, b, c);

	printf("\n d= %f\n", d);
	printf("\n pd= %f", sqrt(d));

	printf("\n x1v= %f\n", x1r);
	printf("\n x2v= %f\n", x2r);

	printf("\n x1u= %f\n", x1u);
	printf("\n x2u= %f\n", x2u);


	printf("\n sr= %f\n", sr);
	printf("\n su= %f\n", su);


	printf("\n rr= %f\n", rr);
	printf("\n ru= %f\n", ru);

	printf("\n ilr= %f\n", ilr);
	printf("\n ilu= %f\n", ilu);

	printf("\n irr= %f\n", irr);
	printf("\n iru= %f\n", iru);
}