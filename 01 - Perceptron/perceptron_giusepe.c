#include <stdio.h>

int main (int argc, char** argv)
{
	/* Rede */
	int ann[3][4];
	/* Resultado desejado */
	int saida[4];
	float taxaAprendizado = 0.1;
	int quantidadeEpocas = 0;
	int erro = 1;
	int i = 0, j = 0 y = 0;
	int bias = 1;

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

    saida[0] = 1;
    saida[1] = -1;
    saida[2] = -1;
    saida[3] = -1;

    while(erro == 1)
    {
    	for (i = 0; i < 3; i++)
    	{
    		for (j = 0; j < 4; j++)
    		{
    			y += bias + ann[i][j] * saida[j];
    		}

    		

    		erro = 0;
    		y = 0;
    	}
    	epoca++;
    }

    return (0);
}