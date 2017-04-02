#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) {
	
 double x;
  unsigned int i,a,r1,r2;

  x = 4;
  a = 0; r1 = 1; r2 = 2;
  for(i = 0; a <= x; i++)
  {
    a += r1; r1 += r2;
  }
  i--;

printf("%e", i);
	
	
	return 0;
}
