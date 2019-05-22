#include <stdio.h>
#include <stdlib.h>

//Definindo os pixels RGB da imagem
typedef struct Pixel{  
	int r,g,b; 
}PIXEL;
//Definindo as características da imagem
typedef struct {
	char tipo[2];
	int largura;
	int altura;
	PIXEL **pixelMap;
}PPM;

void carregaPPM(PPM *imagem, char *NomeImagem){
//Abrindo a imagem para leitura
	FILE * ImagemEntrada = fopen(NomeImagem, "r");

	if (ImagemEntrada == NULL)
	{
		printf("Imagem não encontrada.\n");
		exit(1);
	}

//Lendo informações da imagem
	fscanf(ImagemEntrada, "%s", imagem->tipo);//Lendo formato da imagem
	fscanf(ImagemEntrada, "%d %d %d", &imagem->largura, &imagem->altura);//Lendo altura e largura da imagem

//Processamento (leitura) dos pixels da imagem
	imagem->pixelMap = (PIXEL **) malloc(imagem-> altura * sizeof(PIXEL*));//ALocando dinamicante a altura da imagem
		
		for (int i = 0; i < imagem->altura; ++i)
		{
			imagem->pixelMap[i] = (PIXEL *) malloc(imagem->largura * sizeof(PIXEL));//Alocando dinamicamente a largura da imagem
			
			for (int j = 0; j < imagem->largura; ++j)
					{
						fscanf(ImagemEntrada, "%d %d %d", &imagem->pixelMap[i][j].r, &imagem->pixelMap[i][j].g, &imagem->pixelMap[i][j].b);//Lendo particularmente cada pixel da matriz (imagem)
					}		
		}
		fclose(ImagemEntrada);
}

int EscalaDeCinza(int r, int g, int b){
	int PixelCinza;

	PixelCinza = (r + g + b) / 3;//Recebendo os valores de rgb do pixel e estabelecendo uma média para encontrar o tom de cinza equivalente

	return PixelCinza;
}

int ** carregaEscalaDeCinza(PPM *imagem){
//Inicializando uma nova matriz de inteiros para armazenar a escala de cinza
	int**ImagemCinza = (int**) malloc(imagem->altura * sizeof(int*));//Alocando dinamicamente a altura da imagem em escala de cinza

		for (int i = 0; i < imagem->altura; ++i)
		{
			ImagemCinza[i] = (int*) malloc(imagem->largura * sizeof(int));//Alocando dinamicamente a largura da imagem em escala de cinza

			for (int j = 0; j < imagem->largura; ++j)
			{
				ImagemCinza[i][j] = EscalaDeCinza(imagem->pixelMap[i][j].r, imagem->pixelMap[i][j].g, imagem->pixelMap[i][j].b);
			}
		}
	return ImagemCinza;
}

int main(int argc, char const *argv[])
{
	char *char_imagem;
	PPM imagem;
	int ** ImagemCinza;

	scanf("%s", &char_imagem);//Lendo nome do arquivo

	carregaPPM(&imagem, char_imagem);

	ImagemCinza = carregaEscalaDeCinza(&imagem);

	return 0;
}