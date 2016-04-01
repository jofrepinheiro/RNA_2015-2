#include <stdio.h>

int main (int argc, char** argv)
{
	int ann[3][4];
	int pesos[4];
	int saida[4];

	float taxaAprendizado = 0.3; float ativacao = 0.3;

	int epoca = 0; int erro = 1; int i = 0; int j = 0; int y = 0; int bias = 0;

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

    pesos[0] = 1;
    pesos[1] = 1;
    pesos[2] = 1;
    pesos[3] = 1;

    saida[0] = 1;
    saida[1] = -1;
    saida[2] = -1;
    saida[3] = -1;

    while(erro != 4)
    {
    	for (i = 0; i < 3; i++)
    	{
    		for (j = 0; j < 4; j++)
    			y += bias + ann[i][j] * pesos[j];

    		printf("y = %d\n", y);

    		if (y > ativacao)
    			y = 1;
    		else
    			if (y < (ativacao*(-1)))
    				y = -1;
    			else
    				y = 0;

    		if (y != saida[i])
    		{
    			for (j = 0; j < 4; j++)
    				pesos[j] = pesos[j] + taxaAprendizado * saida[i] * ann[i][j];

    			bias = bias + taxaAprendizado * saida[i];
    			erro = 0;
    		}
    		else
    		{
    			erro++;
    		}

    		y = 0;
    	}
    	epoca++;
    	for (j = 0; j < 4; j++)
    	{
    		printf("Peso %d: %d\n", j, pesos[j]);
    	}

    	system("pause");
    }

    return (0);
}