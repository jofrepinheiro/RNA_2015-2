#include <stdio.h>

int main ()
{
	char ann[7][63];
	float pesos[63];
	float saida[7];

	float taxaAprendizado = 1; float ativacao = 0.1;

	int epoca = 1; int acerto = 1;
	float y = 0; float bias = 0;
	int i = 0; int j = 0; int k = 0; int count = 0; int linhas = 0;

    char url[]="letras.txt";
	char ch;
	FILE *arq;

    for (i = 0; i < 63; i++)
        pesos[i] = 0;

	arq = fopen(url, "r");
	if(arq == NULL)
	    printf("acerto, nao foi possivel abrir o arquivo\n");
	else
    {
	    while( ( (ch=fgetc(arq))!= EOF ) && (letras < 7) && (acerto != 7)
        {

            if (ch != '\n')
            {
                ann[letras][count] = ch;
                count++;
                if (count % 63 == 0)
                {
                    letras++;
                    count = 0;

                    for (k = 0; k < 7; k++)
                    {
                        ch=fgetc(arq));
                        if (ch == '.')
                            saida[k] = -1;
                        else
                            saida[k] = 1;
                    }

                    /* CÓDIGO DA REDE */
                    printf("------------- Epoca %d -------------\n", epoca);

                    for (i = 0; i < 7; i++)
                    {
                        for (j = 0; j < 63; j++)
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
                            for (j = 0; j < 63; j++)
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

                    for (j = 0; j < 63; j++)
                        printf("Peso %d: %6.2f\n", j, pesos[j]);
                    epoca++;
                    printf("\n");
                    system("pause");
                    printf("\n");
                    /* FIM CÓDIGO DA REDE */
                }
            }
        }
    }
	fclose(arq);

    return 0;
}