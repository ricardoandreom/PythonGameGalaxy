#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const int MAXDIM=100000;

int Ocorrencias(char p[], int l, char c, int ind[])
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

void inicializa_jogada(char jogada[])//funçao para que no jogo apareça o "-"'s antes de se advinhar letras da palvra em questão.
{
	int i;
	for(i=0;i<20;i++)
		jogada[i]='-';
}
void preenche(char jogada [],char c, int ind[], int nvezes)//funçao para substituir os hifens por caracteres nas posiçoes adequadas da palavra que se está a tentar advinhar
{
	int i;
	for(i=0;i<nvezes;i++)
	{
		jogada[ind[i]]=c;
	}
}

void escreve(char jogada[],int l)//funçao para escrever os caracteres na palavra
{
	int i;
	for(i=0;i<l-1;i++)
		printf("%c",jogada[i]);
	printf("\n \n");
}
int main()
{
	srand(time(0));
	char s[MAXDIM][20], line[20], c;
	char palavra[20], jogada[20];//declaração da variavel jogada que representa o vetor de caracteres que forma a palavra cada vez que se inicia um novo jogo
	int cont=0,j,nvezes,l, ind[20];
	int creditos=10,win=0; //declaraçao da variavel win que represena o numero de caracteres acertados pelo utilizador e da variavel creditos e a sua inicializaçao em 10
	FILE *dicionario; 
	dicionario=fopen("dicionario.txt","r");
	
	 while (fgets(line, sizeof(line), dicionario)) {
        strcpy(s[cont],line);
        cont++;
    }
    
    j=rand()%cont;
    strcpy(palavra,s[j]);
    l=strlen(palavra);//comprimento do vetor palavra
    inicializa_jogada(jogada);
    while(creditos>0)
    {
		fflush(stdin);// computador estava a ler 2x o caracter que eu introduzia entao introduzi este comando para limpar o buffer
		printf("Introduza uma letra: ");
		scanf("%c",&c);
		nvezes=Ocorrencias(palavra,l,c,ind);
		win=win+nvezes;//// win representa o numero de caracteres da palavra que foram preenchidos
		if(nvezes>0)//se a letra escolhida pertencer a palavra, preencher a palavra com essa letra nos seus espaços apropriados
		  preenche(jogada,c,ind,nvezes); 
		
		creditos--;
		escreve(jogada,l);	
		if(win==l-1)	
			  {// se o numero de caracteres preenchidos for igual ao comprimento da palavra, é porque a pessoa ganhou
			  printf("Parabens!\n");
			  break;
		  }
	}
	if(win!=l-1)//caso contrario, perde, não advinhou as letras todas
		printf("A palavra procurada era %s",palavra);
    return 0;
  }

