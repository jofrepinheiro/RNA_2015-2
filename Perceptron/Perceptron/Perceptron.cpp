#include <iostream>
#include <fstream>
#include <string>
using namespace std;


float parse(char letra){
	if (letra == '.')
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


void leitura(string url, float ann[][63], float saida[][7]){
	char ch;
	int k; int letras = 0; int count = 0; int letra = 0; int pontArq = 0; int contLinha = 0;
	ifstream arq(url);
	string linha;
	float floatTemp;

	if (!arq)
	{
		cout << "Nao foi possivel abrir o arquivo\n";
		system("pause");
	}
	else
	{
		while (!arq.eof())
		{

			//Fim da Letra, começo da saída
			getline(arq, linha);

			if (count == 63)
			{
				system("pause");
				for (int i = 0; i < linha.length(); i++)
				{
					floatTemp = parse(linha[i]);
					saida[letra][i] = floatTemp;
				}
				count = 0;
				letra++;
			}

			//Coloca a letra no ANN
			for (int i = 0; i < linha.length(); i++)
			{
				if (!(linha[i] == '\n'))
				{
					floatTemp = parse(linha[i]);
					ann[letra][count] = floatTemp;
					count++;
				}
			}
		}
	}
}

void iniciaVetor(float vetor[], float valor){
	for (int i = 0; i < sizeof(vetor); i++) {
		vetor[i] = valor;
	}
}

void iniciaMatriz(float matriz[][63], float valor){
	for (int i = 0; i < sizeof(matriz); i++) {
		for (int j = 0; j < sizeof(matriz[i]); i++) {
			matriz[i][j] = valor;
		}
	}
}

int main(){

	float ann[7][63];
	float pesos[7][63];
	float saida[7][7];

	float taxaAprendizado = 1.0;
	float ativacao = 0.0;

	int epoca = 1; int acerto = 1;
	float y = 0;
	float bias[7];
	int i = 0; int j = 0; int k = 0;

	/*iniciaVetor(bias, 0);
	iniciaMatriz(pesos, 0);*/

	leitura("letras.txt", ann, saida);



	//for (k = 0; k < 7; k++){
	//	acerto = 0;
	//	while (acerto != 1)
	//	{
	//		//			system("pause");
	//		printf("------------- Epoca %d -------------\n", epoca);

	//		for (i = 0; i < 7; i++)
	//		{
	//			for (j = 0; j < 63; j++)
	//				y += ann[i][j] * pesos[k][j];
	//			y += bias[k];
	//			if (y > ativacao)
	//				y = 1;
	//			else if (y < (ativacao*(-1)))
	//				y = -1;
	//			else
	//				y = 0;
	//			printf("y%d: %6.2f\n", i, y);
	//			if (y != saida[k][i])
	//			{
	//				for (j = 0; j < 63; j++)
	//					pesos[k][j] = pesos[k][j] + (taxaAprendizado * saida[k][i] * ann[i][j]);

	//				bias[k] = bias[k] + taxaAprendizado * saida[k][i];
	//				acerto = 0;
	//			}
	//			else
	//			{
	//				acerto = 1;
	//			}

	//			y = 0;
	//		}

	//		for (j = 0; j < 63; j++)
	//			printf("Peso [%d, %d]: %6.2f\n", k, j, pesos[k][j]);
	//		epoca++;
	//		printf("\n Acerto: %d", acerto);
	//		printf("\n");
	//		//			system("pause");
	//	}

	//	/* FIM CÓDIGO DA REDE */
	//}

	return 0;

}