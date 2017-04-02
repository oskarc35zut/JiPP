#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a, b, c;
float d, pd, x1v, x2v, x1u, x2u;


int main() {
	printf("==== 1 =====\n\n");
	printf("Podaj a b c\n");
	scanf ("%d %d %d",&a, &b, &c);
	
	//a = 4;
	///b = 5;
	//c = 18;
	
	printf("a= %d  b= %d  c= %d\n", a,b,c);
	
	
	
	printf("\n\n==== 2 =====\n\n");
	//========================================================================================================================
	if(a>1 || a<0)
	{
		printf("%d*x*x", a);
	}
	else
	{
		if(a==1)
		{
			printf("x*x");
		}
		else
		{
			if(a!=0)
			{
				printf("\n######\nZad2. blad_a\n");
			}
		}
	}
	if(b>1)
	{
		printf("+%d*x", b);
	}
	else
	{
		if(b<0)
		{
			printf("%d*x", b);
		}
		else
		{
			if(b==1)
			{
				printf("+x");
			}
			else
			{
				if(b!=0)
				{
					printf("\n######\nZad2. blad_b\n");
				}
			}
		}
	}
	if(c>0)
	{
		printf("+%d", c);
	}
	else
	{
		if(c<0)
		{
			printf("%d", c);
		}
		else
		{
			if(c==1)
			{
				printf("%d", c);
			}
			else
			{
				if(b!=0)
				{
					printf("\n######\nZad2. blad_c\n");
				}
			}
		}
	}
	printf(" = 0\n");
	
	
	
	printf("\n\n==== 3 =====\n\n");
	//========================================================================================================================
	
	if(a!=0)
	{
		d=b*b-(4*a*c);
		printf("d= %f", d);
	}
	
	if(d>0)
	{
		if(d<=25)
		{
			
		}
	}
	
	
	
	return 0;
}
