#include <stdio.h>

int main ()
{
	float ann[21][63];
	float pesos[7][63];
	float saida[7][7];

	float taxaAprendizado = 1.0;
	float ativacao = 0.0;

	int epoca = 1; int acerto = 1;
	float y = 0;
	float bias[7];
	int i = 0; int j = 0; int k = 0; int count = 0; int letras = 0;

	for (i=0; i<7; i++)
		bias[i] = 0;

    char url[]="letras.txt";
	char ch;
	FILE *arq;

    for (i = 0; i < 7; i++)
    	for (k = 0; k < 63; k++)
    		pesos[i][k] = 0;

	arq = fopen(url, "r");
	if(arq == NULL)
	    printf("acerto, nao foi possivel abrir o arquivo\n");
	else
    {
	    while( ( (ch=fgetc(arq))!= EOF ) && (letras < 21) )
        {
            if (ch != '\n')
            {
                if(ch == '#'){
                	ann[letras][count] = 1;
                }else{
                	ann[letras][count] = -1;
                }

                count++;
                if (count % 63 == 0)
                {
                    count = 0;
                    fgetc(arq);
                    for (k = 0; k < 7; k++)
                    {
                        ch=fgetc(arq);
                        if (ch == '.')
                            saida[letras][k] = -1;
                        else
                            saida[letras][k] = 1;
                    }
                    letras++;
                }
            }
        }
    }
	fclose(arq);
/*
	for (i = 0; i < 21; i++)
		{
			for (j = 0; j < 63; j++)
			{
                printf("%.2f\t", ann[i][j]);
                if((j+1)%7 == 0){
                     printf("\n");
                     }
            }
   for (j = 0; j < 7; j++)
		{
            printf("%.2f\t", saida[i%7][j]);
            }
            printf("\n");
                            system("pause");
}
*/

    /* C�DIGO DA REDE */

	for(k = 0; k < 7; k++){
		acerto = 0;
		while(acerto != 1)
		{
            acerto = 1;
			//printf("------------- Epoca %d -------------\n", epoca);

			for (i = 0; i < 21; i++)
			{
				for (j = 0; j < 63; j++)
					y += ann[i][j] * pesos[k][j];
				y += bias[k];
				if (y > ativacao)
					y = 1;
				else if (y < (ativacao*(-1)))
					y = -1;
				else
					y = 0;
				//printf("y%d: %6.2f\n", i, y);
				
				if (y != saida[k][i%7])
				{
					for (j = 0; j < 63; j++)
					{
						pesos[k][j] = pesos[k][j] + taxaAprendizado * saida[k][i%7] * ann[i][j];
                    }      
					bias[k] = bias[k] + taxaAprendizado * saida[k][i%7];
					acerto = 0;
					printf("aqui\n");
				}
			}
		}
		system("pause");

        /* FIM C�DIGO DA REDE */
    }
    for(k = 0; k < 7; k++){
        for (i = 0; i < 7; i++)
    	{
    		for (j = 0; j < 63; j++)
    			y += ann[i][j] * pesos[k][j];
    		y += bias[k];
    		if (y > ativacao)
    			y = 1;
    		else if (y < (ativacao*(-1)))
    			y = -1;
    		else
    			y = 0;
    		printf("y%d: %6.2f\n", i, y);
        }
        printf("\n");
    }
    return 0;
}
