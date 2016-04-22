#include <stdio.h>

int main ()
{
	float ann[3][4];
	float pesos[4];
	float saida[4];

	float taxaAprendizado = 0.1; float ativacao = 0.1;

	int epoca = 1; int acerto = 1;
	float y = 0; float bias = 0;
	int i = 0; int j = 0;

    ann[0][0] = 1;
    ann[0][1] = 1;
    ann[0][2] = 1;
    ann[0][3] = 0;

    ann[1][0] = 1;
    ann[1][1] = 1;
    ann[1][2] = 0;
    ann[1][3] = 1;

    ann[2][0] = 1;
    ann[2][1] = 0;
    ann[2][2] = 1;
    ann[2][3] = 1;

	ann[3][0] = 1;
    ann[3][1] = 1;
    ann[3][2] = 1;
    ann[3][3] = 1;

    pesos[0] = 0;
    pesos[1] = 0;
    pesos[2] = 0;
    pesos[3] = 0;

    saida[0] =  1;
    saida[1] = -1;
    saida[2] = -1;
    saida[3] = -1;

    while(acerto != 4)
    {
    	printf("------------- Epoca %d -------------\n", epoca);
    	for (i = 0; i < 4; i++)
    	{
    		for (j = 0; j < 4; j++)
    			y += bias + ann[i][j] * pesos[j];
    		if (y > ativacao)
    			y = 1;
    		else if (y < (ativacao*(-1)))
				y = -1;
			else
				y = 0;
			printf("y%d: %6.2f\n", i, y);
    		if (y != saida[i])
    		{
    			for (j = 0; j < 4; j++)
    				pesos[j] = pesos[j] + taxaAprendizado * saida[i] * ann[i][j];

    			bias = bias + taxaAprendizado * saida[i];
    			acerto = 0;
    		}
    		else
    		{
    			acerto++;
    		}

    		y = 0;
    	}

    	for (j = 0; j < 4; j++)
    		printf("Peso %d: %6.2f\n", j, pesos[j]);
    	epoca++;
    	printf("\n");
    	system("pause");
    	printf("\n");
    }
    return 0;
}