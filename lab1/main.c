#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a, b, c;
float d, pd, x1v, x2v, x1u, x2u;


int main() {
	printf("==== 1 =====\n\n");
	printf("Podaj a b c\n");
	scanf ("%d %d %d",&a, &b, &c);
	
	a = 1;
	b = 1;
	c = 1;
	
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
        d=(b*b)-((4*a)*c);
        printf("\nd= %f\n",d);
        
        if(d>0)
        {
            if(d<=25)
            {
            	//obliczanie pierwiastka z d
                pd=d/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;// dokladnosc na poziomie 0.2
					}}}}}}}
					
                x1v=(-b-d)/(2*a);
                x2v=(-b+d)/(2*a);
                
                printf("\n x1v= %f\n",x1v);
                printf("\n x2v= %f\n",x2v);
            }
            
            
            else if(d>25)
                printf("Nie liczymy pierwiastka wiekszego od 25\n");
        }
        
        
            else if (d == 0)
            {
                x1v=(((float)b)/(2*((float)a)))*(-1);
                printf("\n x1v = %f",x1v);
            }
            
            
            else if ((d<0) && (d>=-25))
            {
                x1v=((-1)*((float)b))/(2*((float)a));
                x2v=x1v;
                
                printf("\nx1v = %f\n",x1v);
                printf("\nx2v = %f\n",x2v);
                
                d=-d;
                
                //obliczanie pierwiastka z d
                pd=d/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;
                if((d/pd-pd>0.1) || (d/pd-pd<-0.1)) {pd=(d/pd+pd)/2;// dokladnosc na poziomie 0.2
				}}}}}}}
				
                x1u=(-pd)/(2*a);
                x2u=-x1u;
                
                if(x1u<0)
                {
                printf("\n z1 = %f %f*i",x1v,x1u);
                printf("\n z2 = %f +%f*i",x2v,x2u);
                }
                else
                {
                printf("\n z1 = %f +%f*i",x1v,x1u);
                printf("\n z2 = %f %f*i",x2v,x2u);
                }
            }
    }
    
    
    
    
    
            else if(a == 0)
            {
    printf("\n\n==== 4 =====\n\n");
	//========================================================================================================================
                if(b != 0)
                {
                    x1v=((float)c/(float)b)*(-1);
                    printf("\n x1v = %f",x1v);
                }
                else if((b == 0) && (c != 0))
                {
                    printf("Rownanie jest sprzeczne\n");
                }
                else if((b == 0) && (c == 0))
                {
                    printf("Rownanie jest tozsamosciowe\n");
                }
            }
    getchar();
    return 0;
}






