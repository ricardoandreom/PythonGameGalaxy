#include <stdio.h>
#include <string.h> //biblioteca para manipulaçao de strings
#include <stdlib.h>
#include <time.h> //biblioteca necessaria para as funçoes que gerem um numero inteiro aleatorio

const int MAXDIM=100000; //100000 porque vi no ficheiro de texto dicionario que sao 35000 palavras

int Ocorrencias(char p[], int l, char c, int ind[])//funçao que devolve o numero de vezes que o caracter c ocorre na palavra p de comprimento l e armazene os respetivos ındices no vetor ind
{
	//2a)
	int nvezes=0, i;
	for(i=0;i<l;i++)
	{
		if(p[i]==c)
		{
			ind[nvezes]=i;
			nvezes++;
		}
	}
	return nvezes;
}

//main
int main()
{
	srand(time(0));
	char s[MAXDIM][20], line[20], palavra[20]; 	//matriz que vai guardar o dicionario, considerei que nao ha palavras com mais de 20 letras
	int cont=0,j; 				//guardará o numero de palavras no dicionario
	FILE *dicionario; 			//ficheiro do dicionario
	dicionario=fopen("dicionario.txt","r");//abre o ficheiro dicionario.txt para leitura
	
	//alinea a
	 while (fgets(line, sizeof(line), dicionario)) {/*ler o dicionario.txt linha por linha
														enquanto o 'fgets' lê até ao numero de caracteres da linha ou até o '\n'
														copia a line o para vetor s*/	 
        strcpy(s[cont],line);
        cont++;
    }
    
    //alinea b
    // gere um numero inteiro aleatorio j entre 1 e o numero de palavras lidas;
    j=rand()%cont;
    
    //alinea c
    //c) escreva no ecr˜a quantas letras tem a palavra que esta guardada na j-esima posiç˜ao do vetor s;
	printf("O número de letras da palavra escolhida é %u", strlen(s[j])-1);
    
    //alinea d
    //guarde a palavra selecionada no vetor palavra
    strcpy(palavra,s[j]);
    
	
	return 0;
}
