#include <stdio.h>

int main ()
{
	char ann[7][63];
	float pesos[63];
	float saida[63];

	float taxaAprendizado = 1; float ativacao = 0.1;

	int epoca = 1; int erro = 1;
	float y = 0; float bias = 0;
	int i = 0; int j = 0; int count = 0; int letras = 0;

    char url[]="letras.txt";
	char ch;
	FILE *arq;

	arq = fopen(url, "r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while( ( (ch=fgetc(arq))!= EOF ) && (letras < 7) )
        {
            putchar(ch);
            if (ch != '\n')
            {
                ann[letras][count] = ch;
                count++;
                if (count % 63 == 0)
                {
                    letras++;
                    count = 0;
                }
            }
        }
	fclose(arq);

    for (i = 0; i < 63; i++)
        pesos[i] = 0;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 63; j++)
        {
            if (j % 7 == 0)
            {
                printf("\n");
            }
            putchar(ann[i][j]);
        }
        printf("\n");
    }

    /*WTF IS THE SAIDA*/

    /*
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
    */
    return 0;
}