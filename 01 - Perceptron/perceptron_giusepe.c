#include <stdio.h>

int main (int argc, char** argv)
{
	int ann[3][4];
	int saida[4];
	int taxaAprendizado = 0.1;
	int quantidadeEpocas = 0;
	bool erro = true;

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

    while(erro)
    {
    	for (int i = 0; i < 4; i++)
    	{
    		
    	}
    }

    return (0);
}