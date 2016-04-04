#include <stdio.h>
 
int main()
{
  
	  float x[4][4];
	  float controle[4];
	  float w[4];
	  float t[4];
	  int b = 0, i=0, epoca = 0, y = 0, y_in = 0, parada = 0;
	  float theta = 0.2, alfa = 0.1;
  
  
  x[0][0] = 1;
  x[0][1] = 1;
  x[0][2] = 1;
  x[0][3] = 0;
  
  x[1][0] = 1;
  x[1][1] = 1;
  x[1][2] = 0;
  x[1][3] = 1;
  
  x[2][0] = 1;
  x[2][1] = 0;
  x[2][2] = 1;
  x[2][3] = 1;
  
  x[3][0] = 1;
  x[3][1] = 1;
  x[3][2] = 1;
  x[3][3] = 1;
 
  t[0] =  1;
  t[1] = -1;
  t[2] = -1;
  t[3] = -1;
  
  w[0] = 0;
  w[1] = 0;
  w[2] = 0;
  w[3] = 0;
  
  while(parada == 0){
	for(i=0; i<4; i++){
		y_in = b + (x[0][i]*w[0]) + (x[1][i]*w[1]) + (x[2][i]*w[2]) + (x[3][i]*w[3]);
		
		if(y_in > theta){
			y = 1;
		}else if(y_in < (-1*theta)){
			y = -1;
		}else{
			y = 0;
		}
		
		if(y != t[i]){
			w[0] = w[0] + (alfa * t[i] * x1[i]);
			w[1] = w[1] + (alfa * t[i] * x2[i]);
			w[2] = w[2] + (alfa * t[i] * x3[i]);
			w[3] = b;			
			b = b + alfa*t[i];
		}else{
			parada = 1;
		}	
		
		printf("%d %d %d %d %d\n", epoca, w[0], w[1], w[2], w[3]);
		system("pause");
	}
	epoca = epoca + 1;	
  }
  
  return 0;
}