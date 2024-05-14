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
int main()
{
	srand(time(0));
	
	char s[MAXDIM][20], line[20], palavra[20], c; 
	int cont=0,j,nvezes,l;
	int ind[20],i; //declaraçao de uma variavel i e do vetor ind que armazena os indices das letras 
	
	FILE *dicionario; 
	dicionario=fopen("dicionario.txt","r");
	
	 while (fgets(line, sizeof(line), dicionario)) {
        strcpy(s[cont],line);
        cont++;
    }
    

    j=rand()%cont;
    strcpy(palavra,s[j]);
    l=strlen(palavra);//da o comprimento do vetor palavra
    
    //2b)
    /*implemente um novo programa que: peça
     ao utilizador que introduza uma letra, devolva o numero de ocorrencias dessa letra na palavra
     selecionada anteriormente, e escreva no ecr˜a quais as posiç˜oes em que essa letra aparece.
      */
      
    printf("Introduza uma letra: ");
    scanf("%c",&c);
    
    nvezes=Ocorrencias(palavra,l,c,ind);
    printf("Apareceram %d% '%c's na palavra %s% nas posicoes ", nvezes,c,palavra);
    
    for(i=0;i<nvezes;i++)
	   printf("%d ",ind[i]);
	return 0;
}
