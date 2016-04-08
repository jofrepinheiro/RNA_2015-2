#include <stdio.h>

int main ()
{
	char ann[7][9];
	float pesos[4];
	float saida[4];

	float taxaAprendizado = 0.1; float ativacao = 0.1;

	int epoca = 1; int erro = 1;
	float y = 0; float bias = 0;
	int i = 0; int j = 0;

    char url[]="letras.txt";
	char ch;
	FILE *arq;

	arq = fopen(url, "r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while( (ch=fgetc(arq))!= EOF )
			putchar(ch);
	fclose(arq);

    pesos[0][0] = '0'; pesos[0][1] = '0'; pesos[0][2] = '0'; pesos[0][3] = '0'; pesos[0][4] = '0'; pesos[0][5] = '0'; pesos[0][6] = '0'; pesos[0][7] = '0'; pesos[0][8] = '0';
    pesos[1][0] = '0'; pesos[1][1] = '0'; pesos[1][2] = '0'; pesos[1][3] = '0'; pesos[1][4] = '0'; pesos[1][5] = '0'; pesos[1][6] = '0'; pesos[1][7] = '0'; pesos[1][8] = '0';
    pesos[2][0] = '0'; pesos[2][1] = '0'; pesos[2][2] = '0'; pesos[2][3] = '0'; pesos[2][4] = '0'; pesos[2][5] = '0'; pesos[2][6] = '0'; pesos[2][7] = '0'; pesos[2][8] = '0';
    pesos[3][0] = '0'; pesos[3][1] = '0'; pesos[3][2] = '0'; pesos[3][3] = '0'; pesos[3][4] = '0'; pesos[3][5] = '0'; pesos[3][6] = '0'; pesos[3][7] = '0'; pesos[3][8] = '0';
    pesos[4][0] = '0'; pesos[4][1] = '0'; pesos[4][2] = '0'; pesos[4][3] = '0'; pesos[4][4] = '0'; pesos[4][5] = '0'; pesos[4][6] = '0'; pesos[4][7] = '0'; pesos[4][8] = '0';
    pesos[5][0] = '0'; pesos[5][1] = '0'; pesos[5][2] = '0'; pesos[5][3] = '0'; pesos[5][4] = '0'; pesos[5][5] = '0'; pesos[5][6] = '0'; pesos[5][7] = '0'; pesos[5][8] = '0';
    pesos[6][0] = '0'; pesos[6][1] = '0'; pesos[6][2] = '0'; pesos[6][3] = '0'; pesos[6][4] = '0'; pesos[6][5] = '0'; pesos[6][6] = '0'; pesos[6][7] = '0'; pesos[6][8] = '0';

    saida[0][0] = '0'; saida[0][1] = '0'; saida[0][2] = '0'; saida[0][3] = '0'; saida[0][4] = '0'; saida[0][5] = '0'; saida[0][6] = '0'; saida[0][7] = '0'; saida[0][8] = '0';
    saida[1][0] = '0'; saida[1][1] = '0'; saida[1][2] = '0'; saida[1][3] = '0'; saida[1][4] = '0'; saida[1][5] = '0'; saida[1][6] = '0'; saida[1][7] = '0'; saida[1][8] = '0';
    saida[2][0] = '0'; saida[2][1] = '0'; saida[2][2] = '0'; saida[2][3] = '0'; saida[2][4] = '0'; saida[2][5] = '0'; saida[2][6] = '0'; saida[2][7] = '0'; saida[2][8] = '0';
    saida[3][0] = '0'; saida[3][1] = '0'; saida[3][2] = '0'; saida[3][3] = '0'; saida[3][4] = '0'; saida[3][5] = '0'; saida[3][6] = '0'; saida[3][7] = '0'; saida[3][8] = '0';
    saida[4][0] = '0'; saida[4][1] = '0'; saida[4][2] = '0'; saida[4][3] = '0'; saida[4][4] = '0'; saida[4][5] = '0'; saida[4][6] = '0'; saida[4][7] = '0'; saida[4][8] = '0';
    saida[5][0] = '0'; saida[5][1] = '0'; saida[5][2] = '0'; saida[5][3] = '0'; saida[5][4] = '0'; saida[5][5] = '0'; saida[5][6] = '0'; saida[5][7] = '0'; saida[5][8] = '0';
    saida[6][0] = '0'; saida[6][1] = '0'; saida[6][2] = '0'; saida[6][3] = '0'; saida[6][4] = '0'; saida[6][5] = '0'; saida[6][6] = '0'; saida[6][7] = '0'; saida[6][8] = '0';

    while(erro != 4)
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
    			erro = 0;
    		}
    		else
    		{
    			erro++;
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